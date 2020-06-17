# eBike_Firmware

Hey! This is a PlatformIO project that I use to develop a really cool eBike firmware.

# Downloading the firmware from releases tab

1. Go to https://github.com/immakermatty/eBike_Firmware/releases
2. Download the latest EbikeFirmwareLoader.rar
3. Open Arduino IDE, choose appropriate ESP32 board from the boards menu (you might need to install the ESP32 enviroment to the Arduino IDE)
4. !!! Select Partition scheme in the Arduino tool tab to Minimal SPIFFS !!!
5. Upload the EbikeFirmwareLoader.ino
6. Open Serial monitor and read the instructions
7. Connect to the EBIKE_FIRMWARE_LOADER wifi network
8. When connected, open http://update.local or http://192.168.4.1 in the google chrome
9. In the update form choose firmware.bin file
10. Hit upload
11. Wait for the upload to complete
12. DONE - eBike firmware should be flashed over the air


# Developing this PlatformIO project

1. Make sure you have git installed on your PC. Download and install from https://git-scm.com/downloads
2. Navigate to a folder where you want to download this project
3. Open command line terminal in the folder (on windows shift + right click -> open PowerShell)
4. Run this command: git clone --recurse-submodules https://github.com/immakermatty/eBike_Firmware.git
5. Wait for it to download
6. Open the eBike_Firmware folder in the PlatformIO

And you should be ready to develop and compile the code!

www.maker.matejsuchanek.cz
