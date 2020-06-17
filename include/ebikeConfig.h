#ifdef ESP32

#ifndef _EBIKE_EBIKECONFIG_h
#define _EBIKE_EBIKECONFIG_h

////////////////////////////////////////////////////  PINS  /////////////////////////////////////////////////////////////

//#define EBIKE_PIN_GYRO_SDA 22
//#define EBIKE_PIN_GYRO_SCL 25
//
//#define EBIKE_PIN_NEOPIXEL_TAIL 19		// big LED strip rear turn signals, brake light, tail lights
//#define EBIKE_PIN_NEOPIXEL_SIGNALS_RL 18	// LED strip rear left  turn signals
//#define EBIKE_PIN_NEOPIXEL_SIGNALS_RR 17	// LED strip rear right turn signals
//#define EBIKE_PIN_NEOPIXEL_SIGNALS_FL 16	// LED strip items left  turn signals
//#define EBIKE_PIN_NEOPIXEL_SIGNALS_FR 15	// LED strip items right turn signals
//#define EBIKE_PIN_NEOPIXEL_DASHBOARD 21	// LED strip dashboard !!! ruseni I2C
//
//#define EBIKE_PIN_HEADLIGHT 33			// LED headlight
//#define EBIKE_PIN_BUTTON_BRAKE 13		// brzda brake lights
//#define EBIKE_PIN_VARIABLE_BRAKE 34		// variabilni brzda 1,3-5V 
//#define EBIKE_PIN_BUTTON_SIGNAL_LEFT 23	// leva packa blinkru, turn left
//#define EBIKE_PIN_BUTTON_SIGNAL_RIGHT 32	// prava packa blinkru, turn right
//
//#define EBINE_PIN_ENGINE_ACTIVE 5		// engine on to start day lights (buttonPinEng)
//
////const int buttonPinKnightRider = 25;         // knight rider lights
////const int buttonPinTailLights = 14;          // tail lights
////const int nucularPin = 35;




#define EBIKE_PIN_GYRO_SDA				18	// gyro data line
#define EBIKE_PIN_GYRO_SCL				19	// gyro clock line

#define EBIKE_PIN_NEOPIXEL_TAIL			16	// big LED strip rear turn signals, brake light, tail lights
#define EBIKE_PIN_NEOPIXEL_SIGNALS_RL	27	// LED strip rear left  turn signals
#define EBIKE_PIN_NEOPIXEL_SIGNALS_RR	25	// LED strip rear right turn signals
#define EBIKE_PIN_NEOPIXEL_SIGNALS_FL	22	// LED strip items left  turn signals
#define EBIKE_PIN_NEOPIXEL_SIGNALS_FR	15	// LED strip items right turn signals
#define EBIKE_PIN_NEOPIXEL_DASHBOARD	21	// LED strip dashboard !!! ruseni I2C

#define EBIKE_PIN_HEADLIGHT				33	// LED headlight
#define EBIKE_PIN_KLAXON				2	// klaxon enable


#define EBIKE_PIN_BUTTON_BRAKE			13	// brzda brake lights
#define EBIKE_PIN_VARIABLE_BRAKE		34	// variabilni brzda 1,3-5V 
#define EBIKE_PIN_BUTTON_SIGNAL_LEFT	23	// leva packa blinkru, turn left
#define EBIKE_PIN_BUTTON_SIGNAL_RIGHT	26	// prava packa blinkru, turn right
#define EBIKE_PIN_BUTTON_LIGHTS			5 	//
#define EBIKE_PIN_BUTTON_KLAXON			4 	// 

#define EBINE_PIN_ENGINE_ACTIVE			-1	// engine on to start day lights (buttonPinEng)

//////////////////////////////////////////////  DEFINITIONS  //////////////////////////////////////////////////////////

#define EBIKE_TURN_SIGNALS_COUNT 4
#define EBIKE_BUTTON_DEBOUNCE_MS 5

#define EBIKE_NEOPIXEL_LEDS_TAIL_COUNT 26
#define EBIKE_NEOPIXEL_LEDS_TURN_SIGNALS_COUNT 10
#define EBIKE_NEOPIXEL_LEDS_DASHBOARD_COUNT 3

#define EBIKE_NEOPIXEL_TYPE WS2812B
#define EBIKE_NEOPIXEL_COLOR_ORDER GRB
#define EBIKE_NEOPIXEL_COLOR_CORRECTION 0xFFFFFFUL
#define EBIKE_NEOPIXEL_INITIAL_BRIGHTNESS 32


#endif
#endif