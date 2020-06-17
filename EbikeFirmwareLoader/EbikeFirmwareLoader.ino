/** 
 * Author	: @makermatty (maker.matejsuchanek.cz)
 * Date		: 15-6-2020
 * 
 * !!! Select Partition scheme in the Arduino tool tab to Minimal SPIFFS !!!
 * 
 * Also make sure you have the the latest stable version of the ESP32 package installed in the Arduino IDE
 * 
 * Upload this Arduino sketch to your ESP32 and follow the instructions in the serial motior 
 * to flash the firmware over the air.
 * 
 * Based on the https://github.com/immakermatty/MakerMatty_AccessPointWebUpdate
 */

#ifdef ESP32

#include <Arduino.h>

#include <DNSServer.h>
#include <ESPmDNS.h>
#include <Update.h>
#include <WebServer.h>
#include <WiFi.h>
#include <WiFiClient.h>

#include "jquery.h"

#define DNS_PORT 53
#define HTTPSERVER_PORT 80

const IPAddress ap_local_IP(8, 8, 8, 8);
const IPAddress ap_gateway(8, 8, 8, 8);
const IPAddress ap_subnet(255, 255, 255, 0);

WebServer server(HTTPSERVER_PORT);
DNSServer dnsServer;

const char* serverIndex = "<!DOCTYPE html>"
                          "<html lang=\"en\">"
                          "<head>"
                          "<meta charset=\"utf-8\">"
                          "<title>ESP32 OTA Update</title>"
                          "<script src='/jquery.min.js'></script>"
                          "</head>"
                          "<body>"
                          "OTA update proccess tested on Windows 10 10.0.18363 Build 18363<br>"
                          "using Chrome 80.0.3987.149<br><br>"
                          "<form method='POST' action='#' enctype='multipart/form-data' id='upload_form'>"
                          "<input type='file' name='start'>"
                          "<input type='submit' value='Update'>"
                          "</form>"
                          "<script>$('form').submit(function(e){e.preventDefault();var form = $('#upload_form')[0];"
                          "var data = new FormData(form); $.ajax({url: '/start',type: 'POST',data: data,contentType: "
                          "false,processData:false,xhr: function() {var xhr = new window.XMLHttpRequest();xhr.upload.addEventListener"
                          "('progress', function(evt) {if (evt.lengthComputable) {var per = evt.loaded / evt.total;$('#prg').html"
                          "('progress: ' + Math.round(per*100) + '%');}}, false);return xhr;},success:function(d, s) {console.log"
                          "('success!')},error: function (a, b, c) {}});});</script>"
                          "<br>"
                          "<div id='prg'>progress: 0%</div>"
                          "</body>"
                          "</html>";

void start(const char* ssid, const char* password, const char* host)
{
    Serial.println("Starting OTA Update...");

    Serial.printf("ssid: %s, password: %s, host: %s\n", ssid ? ssid : "", password ? password : "", host ? host : "");

    /* added to start with the wifi off, avoid crashing */
    WiFi.disconnect();
    WiFi.mode(WIFI_OFF);
    WiFi.mode(WIFI_AP);
    /* this causes problems in the current version of Arduino esp32 package */
    // WiFi.softAPConfig(ap_local_IP, ap_gateway, ap_subnet);
    WiFi.softAP(ssid, password);
    Serial.println("Software AP running");

    dnsServer.start(DNS_PORT, "*", ap_local_IP);
    Serial.println("DNS server started");

    /* return index page which is stored in serverIndex */
    server.on("/", HTTP_GET,
        []() {
            server.sendHeader("Connection", "close");
            server.send(200, "text/html", serverIndex);
        });

    /* return javascript jquery */
    server.on("/jquery.min.js", HTTP_GET,
        []() {
            server.setContentLength(jquery_min_js_v3_2_1_gz_len);
            server.sendHeader("Content-Encoding", "gzip");
            server.send_P(200, "text/javascript", jquery_min_js_v3_2_1_gz, jquery_min_js_v3_2_1_gz_len);
        });

    /* handling uploading firmware file */
    server.on("/start", HTTP_POST,
        []() {
            server.sendHeader("Connection", "close");
            server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
            ESP.restart();
        },
        []() {
            HTTPUpload& upload = server.upload();
            if (upload.status == UPLOAD_FILE_START) {
                Serial.printf("Update: %s\n", upload.filename.c_str());
                /* start with max available size */
                if (!Update.begin(UPDATE_SIZE_UNKNOWN)) {
                    Update.printError(Serial);
                }
            } else if (upload.status == UPLOAD_FILE_WRITE) {
                /* flashing firmware to ESP */
                if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
                    Update.printError(Serial);
                }
            } else if (upload.status == UPLOAD_FILE_END) {
                /* true to set the size to the current progress */
                if (Update.end(true)) {
                    Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
                } else {
                    Update.printError(Serial);
                }
            }
        });

    server.on("/gen_204", []() {
        server.send(204, "");
    });

    server.on("/generate_204", []() {
        server.send(204, "");
    });

    server.onNotFound([]() {
        server.send(404, "text/html", "404 - Page not found");
    });

    server.begin();

    Serial.println("Web server started!");

    Serial.printf("\n\nFor update connect to the wifi network EBIKE_FIRMWARE_LOADER and in the browser open one of the following links:\n");
    Serial.printf("   url: http://%s\n", WiFi.softAPIP().toString().c_str());

    /* use mdns for host name resolution */
    if (host && MDNS.begin(host)) {
        MDNS.addService("http", "tcp", 80);
        Serial.printf("   url: http://%s.local\n", host);
    }

    Serial.println();

    while (true) {
        dnsServer.processNextRequest();
        server.handleClient();
        delay(0);
    }
}

void setup()
{
    Serial.begin(115200);

    Serial.println("\n!!! Be sure to select Partition scheme in "
                   "the Arduino tool tab to \"Minimal SPIFFS\" "
                   "before uploading this sketch !!!\n");

    delay(1000);

    start("EBIKE_FIRMWARE_LOADER", nullptr, "update");
}

void loop()
{
    delay(1000);
}

#endif