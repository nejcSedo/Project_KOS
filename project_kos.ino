//----------- v0.9.2 -------------//

//----------- LIBS -------------//
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMono9pt7b.h>

//----------- PINI -------------//
#define TEMP_SENZOR A0
#define VLAGA_SENZOR A1
#define AREF_VOLTAGE 5
#define BTN_D 5
#define BTN_L 4
#define PUMP 7
//#define LED_TEST 6

//----------- IKONE -------------//
const unsigned char settings_bitMap [] PROGMEM = {
  // settings_icon, 32x32px
  0x00, 0x00, 0x04, 0x20, 0x00, 0x00, 0x0e, 0x70, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 
  0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x7e, 0x7f, 0x00, 0x00, 0x7c, 0x3e, 0x00, 0x00, 0x38, 0x1c, 
  0x00, 0x00, 0x38, 0x1c, 0x00, 0x00, 0x7c, 0x3e, 0x00, 0x00, 0x7e, 0x7f, 0x00, 0x70, 0x7f, 0xfe, 
  0x00, 0x70, 0x0f, 0xf0, 0x00, 0x70, 0x0f, 0xf0, 0x1c, 0xf9, 0xce, 0x70, 0x3f, 0xff, 0xc4, 0x20, 
  0x1f, 0xff, 0xc0, 0x00, 0x0f, 0xff, 0x80, 0x00, 0x0f, 0x0f, 0x80, 0x00, 0x1e, 0x03, 0xc0, 0x00, 
  0xfe, 0x03, 0xf8, 0x00, 0xfe, 0x03, 0xf8, 0x00, 0xfe, 0x03, 0xf8, 0x00, 0x1e, 0x03, 0xc0, 0x00, 
  0x1f, 0x07, 0x80, 0x00, 0x0f, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xc0, 0x00, 
  0x1d, 0xf9, 0xc0, 0x00, 0x00, 0x70, 0x80, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00
};

const unsigned char moisture_bitMap [] PROGMEM = {
  // moisture_icon, 32x32px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x30, 
  0x03, 0xe3, 0x00, 0x30, 0x03, 0xea, 0xb0, 0x78, 0x0f, 0xdf, 0xf0, 0xf8, 0x0d, 0xff, 0xf8, 0xfc, 
  0x0f, 0xf9, 0xac, 0xf8, 0x07, 0x3f, 0xf0, 0x78, 0x03, 0xf1, 0xf8, 0x30, 0x00, 0xd3, 0xb0, 0x00, 
  0x00, 0x1f, 0xe0, 0x20, 0x00, 0x13, 0xe0, 0x30, 0x00, 0xb0, 0x60, 0x30, 0x20, 0x70, 0x00, 0x78, 
  0x30, 0x32, 0x00, 0xf8, 0x10, 0x38, 0x40, 0xfc, 0x18, 0x30, 0x40, 0xd8, 0x08, 0x20, 0x80, 0x78, 
  0x0c, 0x21, 0x80, 0x00, 0x06, 0x27, 0x00, 0x00, 0x02, 0x38, 0x02, 0x30, 0x01, 0xa0, 0x0c, 0x30, 
  0x00, 0x60, 0x78, 0x78, 0x00, 0x70, 0xe0, 0xf8, 0x00, 0x6f, 0x00, 0xfc, 0x00, 0x60, 0x00, 0xf8, 
  0x00, 0x60, 0x00, 0x78, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char clock_bitMap [] PROGMEM = {
  // clock_icon, 32x32px
  0x00, 0x07, 0xe0, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0xff, 0xff, 0x00, 0x03, 0xff, 0xff, 0xc0, 
  0x07, 0xe1, 0x87, 0xe0, 0x0f, 0x80, 0x01, 0xf0, 0x1f, 0x00, 0x00, 0xf8, 0x1e, 0x01, 0x80, 0x78, 
  0x3c, 0x01, 0x80, 0x3c, 0x38, 0x01, 0x80, 0x1e, 0x78, 0x01, 0x80, 0x1e, 0x70, 0x01, 0x80, 0x0e, 
  0x70, 0x01, 0x80, 0x0f, 0xf0, 0x01, 0x80, 0x0f, 0xf0, 0x03, 0xc0, 0x07, 0xf8, 0x03, 0xc0, 0x1f, 
  0xf8, 0x03, 0xe0, 0x1f, 0xf0, 0x03, 0xf0, 0x07, 0xf0, 0x00, 0x70, 0x0f, 0x70, 0x00, 0x38, 0x0f, 
  0x70, 0x00, 0x1c, 0x0e, 0x78, 0x00, 0x0e, 0x1e, 0x38, 0x00, 0x06, 0x1e, 0x3c, 0x00, 0x00, 0x3c, 
  0x1e, 0x00, 0x00, 0x78, 0x1f, 0x00, 0x00, 0xf8, 0x0f, 0x80, 0x01, 0xf0, 0x07, 0xe1, 0x87, 0xe0, 
  0x03, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0x00, 0x00, 0x3f, 0xfe, 0x00, 0x00, 0x07, 0xf0, 0x00
};

const unsigned char menu_bitMap [] PROGMEM = {
  // menu_icon, 32x32px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x07, 0xe0, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x70, 0x0e, 0x00, 0x00, 0xc0, 0x03, 0x00, 
  0x01, 0x80, 0x01, 0x80, 0x03, 0x00, 0x00, 0xc0, 0x06, 0x00, 0x00, 0x60, 0x06, 0x1f, 0xf8, 0x60, 
  0x04, 0x1f, 0xf8, 0x20, 0x0c, 0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x30, 0x0c, 0x1f, 0xf8, 0x30, 
  0x0c, 0x1f, 0xf8, 0x30, 0x0c, 0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x30, 0x04, 0x1f, 0xf8, 0x20, 
  0x06, 0x1f, 0xf8, 0x60, 0x06, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x00, 0xc0, 0x01, 0x80, 0x01, 0x80, 
  0x00, 0xc0, 0x03, 0x00, 0x00, 0x70, 0x0e, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x07, 0xe0, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char kos_bitMap [] PROGMEM = {
  // kos_icon, 128x64px
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xfe, 0x00, 0x1f, 0xfc, 0x1c, 0xcf, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xf8, 0x00, 0x07, 0xfc, 0xcc, 0xcf, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xf0, 0x00, 0x03, 0xfc, 0xce, 0xdf, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xc0, 0x00, 0x01, 0xfc, 0xce, 0x1f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0x80, 0x00, 0x00, 0x7c, 0x0f, 0x3f, 0xff, 
  0xff, 0xf9, 0xf1, 0xe3, 0xc1, 0xe0, 0xf0, 0x07, 0xff, 0x00, 0x00, 0x00, 0x7c, 0xe7, 0x3f, 0xff, 
  0xff, 0xf8, 0xf1, 0xe3, 0xc0, 0xe0, 0xf0, 0x03, 0xff, 0x00, 0x00, 0x00, 0x3c, 0xe7, 0x3f, 0xff, 
  0xff, 0xfa, 0xf1, 0xeb, 0xce, 0x67, 0xe0, 0x03, 0xfe, 0x00, 0x00, 0x00, 0x1c, 0xcf, 0x3f, 0xff, 
  0xff, 0xfa, 0x61, 0xc9, 0xce, 0x67, 0xe0, 0x01, 0xfc, 0x00, 0x00, 0x7c, 0x1c, 0x1f, 0x3f, 0xff, 
  0xff, 0xfa, 0x69, 0xc9, 0xcf, 0x20, 0xe0, 0x01, 0xfc, 0x00, 0x00, 0xfe, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xfb, 0x49, 0xdc, 0xcf, 0x67, 0xe0, 0x00, 0xfc, 0x00, 0x01, 0xf6, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xfb, 0x09, 0x80, 0xce, 0x67, 0xc0, 0x00, 0x78, 0x00, 0x01, 0xe3, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xfb, 0x19, 0x9c, 0xcc, 0x67, 0xc0, 0x00, 0x38, 0x00, 0x01, 0x83, 0x00, 0x1f, 0xff, 0xff, 
  0xff, 0xfb, 0x99, 0xbe, 0x40, 0xe0, 0xc0, 0x00, 0x08, 0x00, 0x01, 0xc6, 0x00, 0x0f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x1f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x3f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x81, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xc0, 0x3f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xc0, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x11, 0x18, 0x60, 0x70, 0x18, 0x00, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x12, 0x6c, 0x90, 0x90, 0x34, 0x00, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x16, 0x46, 0x80, 0xf0, 0x60, 0xc0, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1c, 0xc6, 0xe0, 0xe8, 0x61, 0x30, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x14, 0xc6, 0x31, 0xb8, 0x61, 0x30, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x12, 0x44, 0x11, 0x98, 0x61, 0x30, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x13, 0x7c, 0xf0, 0xfc, 0x3d, 0xe4, 0x3f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x6f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xfe, 0x08, 0x18, 0x3e, 0x06, 0x79, 0x1c, 0xd9, 0xcf, 0xe7, 0xf3, 0xfc, 0x73, 0x07, 0x38, 0x3f, 
  0xfc, 0xf9, 0xfb, 0x9c, 0xe6, 0x7b, 0x1c, 0xd9, 0x9f, 0xef, 0xfb, 0xfc, 0x33, 0x3f, 0x31, 0xbf, 
  0xfc, 0xf9, 0xfb, 0xcc, 0xf2, 0x73, 0x0c, 0xd9, 0x3f, 0xdf, 0xfd, 0xfc, 0x33, 0x3f, 0x33, 0xff, 
  0xfe, 0x39, 0xfb, 0xc9, 0xf3, 0x33, 0x0c, 0xd9, 0x3f, 0x9f, 0xfc, 0xfc, 0x93, 0x3f, 0x27, 0xff, 
  0xff, 0x18, 0x3b, 0xc9, 0xf3, 0x37, 0x24, 0xd8, 0x78, 0x4f, 0xfe, 0x7c, 0x93, 0x07, 0x27, 0xff, 
  0xff, 0xc9, 0xfb, 0xc9, 0xf3, 0x27, 0x34, 0xd9, 0x3b, 0xe7, 0xf0, 0x1c, 0xc3, 0x3f, 0x27, 0xff, 
  0xff, 0xc9, 0xfb, 0xcc, 0xf3, 0x87, 0x30, 0xd9, 0x9f, 0xff, 0xe7, 0xe4, 0xc3, 0x3f, 0x23, 0xff, 
  0xfc, 0x88, 0x18, 0x1c, 0x47, 0x8f, 0x38, 0xd9, 0x9f, 0xff, 0xff, 0xfc, 0xe3, 0x3c, 0x33, 0xbf, 
  0xfc, 0x1c, 0x18, 0x3e, 0x0f, 0x8f, 0x39, 0xd9, 0xcf, 0xff, 0xff, 0xfc, 0xe3, 0x04, 0x78, 0x3f, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

const unsigned char water_bitMap [] PROGMEM = {
  // water_icon, 32x32px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 
  0x00, 0x01, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x07, 0xe0, 0x00, 
  0x00, 0x05, 0xe0, 0x00, 0x00, 0x0d, 0xf0, 0x00, 0x00, 0x0b, 0xf0, 0x00, 0x00, 0x1b, 0xf8, 0x00, 
  0x00, 0x1b, 0xf8, 0x00, 0x00, 0x1b, 0xf8, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x0f, 0xf0, 0x00, 
  0x00, 0x47, 0xe2, 0x00, 0x01, 0x23, 0xc4, 0x80, 0x00, 0x20, 0x04, 0x00, 0x01, 0x1c, 0x38, 0x80, 
  0x00, 0x80, 0x01, 0x00, 0x00, 0x3c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char temp_bitMap [] PROGMEM = {
  // temp_icon, 32x32px
  0x00, 0x38, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 
  0x00, 0xfe, 0x00, 0x00, 0x3c, 0xfe, 0x00, 0x00, 0x3c, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 
  0x0e, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x0e, 0x08, 0x00, 0xfe, 0x3f, 0x1c, 0x0e, 0xfe, 0x20, 0x96, 
  0x00, 0xfe, 0x60, 0x9c, 0x3c, 0xfe, 0x60, 0x00, 0x3c, 0xfe, 0x60, 0x00, 0x00, 0xfe, 0x60, 0x00, 
  0x0e, 0xfe, 0x60, 0x00, 0x00, 0xfe, 0x60, 0x80, 0x00, 0xfe, 0x60, 0x80, 0x0e, 0xfe, 0x21, 0x80, 
  0x00, 0xfe, 0x1f, 0x00, 0x3c, 0xfe, 0x00, 0x00, 0x3c, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 
  0x00, 0xfe, 0x00, 0x00, 0x01, 0xff, 0x00, 0x00, 0x01, 0xff, 0x00, 0x00, 0x01, 0xff, 0x00, 0x00, 
  0x01, 0xff, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00
};

const unsigned char alarm_bitMap [] PROGMEM = {
  // alarm_icon, 32x32px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x06, 0x60, 0x00, 
  0x00, 0x06, 0x60, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x18, 0x1f, 0xf8, 0x18, 
  0x30, 0x3f, 0xfc, 0x0c, 0x64, 0x7f, 0xfe, 0x26, 0x6c, 0x7f, 0xfe, 0x36, 0xd8, 0x7f, 0xfe, 0x1b, 
  0xd8, 0x7f, 0xfe, 0x1b, 0xd8, 0xff, 0xff, 0x1b, 0xd8, 0xff, 0xff, 0x1b, 0xd8, 0xff, 0xff, 0x1b, 
  0xc0, 0xff, 0xff, 0x03, 0x41, 0xff, 0xff, 0x82, 0x01, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0x80, 
  0x03, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 
  0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 
  0x00, 0x07, 0xe0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//----------- VARS -------------//
unsigned long s(0);
unsigned long start_time(0);
unsigned long end_time(0);
unsigned long pump_start(0);
float temp_value(0.0);
float vlaga_value(0.0);
float Rkty(0.0);
float R25(2000.0);
float alpha(7.88 / 1000);
float beta(1.937 / 10000);
float KayTee(0.0);
float AcT(0.0);
float resistor_1(2460.0);
float avg(0);
int max_vlaga(150);
int min_vlaga(650);
int btn_wait(250);
int pump_on(4000);
byte ura(6);
byte minuta(0);
byte samples(20);
byte vlaznost_alarm(50);
byte h(13);
byte m(30);
byte pos(0);
bool on_clock(false);
bool moist_on(false);
bool alarm_off(false);
bool btn_pressed(false);

Adafruit_SSD1306 display;

//----------- SETUP -------------//
void setup() {
  //Serial.begin(9600);
  pinMode(BTN_L, INPUT_PULLUP);
  pinMode(BTN_D, INPUT_PULLUP);
  pinMode(PUMP, OUTPUT);
  //pinMode(LED_TEST, OUTPUT);
  digitalWrite(PUMP, HIGH);
  //digitalWrite(LED_TEST, LOW);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(1000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setRotation(0);
  display.setTextWrap(false);
  display.dim(0);
  display.setFont(&FreeMono9pt7b);
  display.setTextSize(0);
  display.drawBitmap(0,0,kos_bitMap,128,64,WHITE);
  display.display();
  delay(5000);
}

//----------- KALIBRACIJA --------------//
void Kalibracija() {
  display.clearDisplay();
  display.println("Suh senzor.");
  display.println("Pritisni desno tipko");
  display.println("za kalibracijo ->");
  display.display();
  delay(btn_wait);
  while(digitalRead(BTN_D)) {}
  int avg(0);
  for(byte i(0); i<samples; i++) {
    min_vlaga = analogRead(VLAGA_SENZOR);
    avg += min_vlaga;
  }
  min_vlaga = avg / samples;
  display.clearDisplay();
  display.setCursor(0,5);
  display.println("Moker senzor.");
  display.println("Pritisni desno");
  display.println("tipko za kalibracijo!");
  display.display();
  delay(btn_wait);
  while(digitalRead(BTN_D)) {}
  avg = 0;
  for(byte i(0); i<samples; i++) {
    max_vlaga = analogRead(VLAGA_SENZOR);
    avg += max_vlaga;
  }
  max_vlaga = avg / samples;
  delay(btn_wait);
}

//----------- SENZORJI -------------//
void ReadSensor() {
  avg = 0;
  for (byte i(0); i < samples; i++) {
    temp_value = analogRead(TEMP_SENZOR);
    avg += temp_value;
    delay(1);
  }
  temp_value = avg / samples;
  avg = 0;
  for (byte i(0); i < samples; i++) {
    vlaga_value = analogRead(VLAGA_SENZOR);
    avg += vlaga_value;
    delay(1);
  }
  vlaga_value = avg / samples;
  Rkty = (resistor_1 * temp_value) / (1023 - temp_value);
  KayTee = Rkty / R25 ;
  AcT = 25 + ((sqrt((alpha * alpha) - (4 * beta) + (4 * beta * KayTee)) - alpha) / (2 * beta));
  vlaga_value = map(vlaga_value, max_vlaga, min_vlaga, 100, 0);
  if(vlaga_value <= 0)
    vlaga_value = 0;
  if(vlaga_value >= 100)
    vlaga_value = 99;
}

void Btn_up() {
  while((!digitalRead(BTN_L) || !digitalRead(BTN_D)) && !btn_pressed) {}
  btn_pressed = true;
}

//----------- OSNOVNI EKRAN -------------//
void PrintOLED() {
  display.setFont(&FreeMono9pt7b);
  display.setTextSize(0);
  display.clearDisplay();
  display.drawBitmap(4,0,temp_bitMap,32,32,WHITE);
  display.setCursor(35,20);
  display.print(byte(AcT));
  display.drawBitmap(0,34,water_bitMap,32,32,WHITE);
  display.setCursor(30,48);
  display.print(byte(vlaga_value));
  display.print("%");
  display.drawLine(70,0,70,70,1);
  display.drawBitmap(85,2,clock_bitMap,32,32,WHITE);
  if(h >= 10) {
    pos = 75;
  } else {
    pos = 85;
  }
  display.setCursor(pos,48);
  display.print(h);
  if(byte(s/1000)%2 == 0) {
    display.print(":");
  } else {
    display.print(" ");
  }
  display.print(m);
  display.setFont();
  display.setTextSize(1);
  if(ura >= 10) {
    pos = 88;
  } else {
    pos = 94;
  }
  display.setCursor(pos,55);
  display.print(ura);
  display.print(":");
  display.print(minuta);
  if(on_clock) {
    display.print("*");
  }
  display.setCursor(33,55);
  display.print(vlaznost_alarm);
  display.print("%");
  if(moist_on) {
    display.print("*");
  }
  display.display();
  display.setFont(&FreeMono9pt7b);
  display.setTextSize(0);
}

//----------- MENI OLED -------------//
void Menu_OLED() {
  display.clearDisplay();
  display.drawBitmap(50,0,menu_bitMap,32,32,WHITE);
  display.setCursor(5, 35);
  display.println("<");
  display.setCursor(115, 35);
  display.println(">");
  display.setCursor(38, 50);
  display.println("IZHOD");
  display.display();
}

//----------- MENI -------------//
void Menu() {
  btn_pressed = false;
  Menu_OLED();
  Btn_up();
  bool exit_menu(false);
  while(!exit_menu) {
    delay(btn_wait);
    if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
      Nastavitve();
      break;
    }
    else if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
      Alarm();
      break;
    }
    else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
      display.clearDisplay();
      display.drawBitmap(50,0,menu_bitMap,32,32,WHITE);
      display.setCursor(5, 35);
      display.println("<");
      display.setCursor(115, 35);
      display.println(">");
      display.setCursor(27, 50);
      display.println(">IZHOD<");
      display.display();
      btn_pressed = false;
      Btn_up();
      while(!exit_menu) {
        delay(btn_wait);
        if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
          exit_menu = true;
        }
        else if(!digitalRead(BTN_D) || !digitalRead(BTN_L)) {
          Menu_OLED();
          break;
        }
      }
    }
  }
}

//----------- ALARM -------------//
void Alarm() {
  btn_pressed = false;
  bool break_loop(false);
  if(ura >= 10) {
    pos = 40;
  } else {
    pos = 50;
  }
  display.clearDisplay();
  display.drawBitmap(50,0,alarm_bitMap,32,32,WHITE);
  display.setCursor(pos, 50);
  display.print(ura);
  display.print(":");
  display.print(minuta);
  display.setCursor(5, 35);
  display.println("<");
  display.setCursor(115, 35);
  display.println(">");
  if(on_clock) {
    display.setCursor(20,20);
    display.print("ON");
  } else {
    display.setCursor(85,20);
    display.print("OFF");
  }
  display.display();
  Btn_up();
  while(true) {
    delay(btn_wait);
    if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
      Menu();
      break;
    }
    else if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
      Vlaznost();
      break;
    }
    else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
      btn_pressed = false;
      if(ura >= 10) {
        pos = 29;
      } else {
        pos = 39;
      }
      display.clearDisplay();
      display.drawBitmap(50,0,alarm_bitMap,32,32,WHITE);
      display.setCursor(pos, 50);
      display.print(">");
      display.print(ura);
      display.print(":");
      display.print(minuta);
      display.print("<");
      if(on_clock) {
        display.setCursor(20,20);
        display.print("ON");
      } else {
        display.setCursor(85,20);
        display.print("OFF");
      }
      display.display();
      Btn_up();
      while(true) {
        delay(btn_wait);
        if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
          if(ura >= 23) {
            ura = 0;
          } else {
            ura++;
          }
          if(ura >= 10) {
            pos = 29;
          } else {
            pos = 39;
          }
          display.clearDisplay();
          display.drawBitmap(50,0,alarm_bitMap,32,32,WHITE);
          display.setCursor(pos, 50);
          display.print(">");
          display.print(ura);
          display.print(":");
          display.print(minuta);
          display.print("<");
          if(on_clock) {
            display.setCursor(20,20);
            display.print("ON");
          } else {
            display.setCursor(85,20);
            display.print("OFF");
          }
          display.display();
        }
        else if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
          if(minuta >= 59) {
            minuta = 0;
          } else {
            minuta++;
          }
          if(ura >= 10) {
            pos = 29;
          } else {
            pos = 39;
          }
          display.clearDisplay();
          display.drawBitmap(50,0,alarm_bitMap,32,32,WHITE);
          display.setCursor(pos, 50);
          display.print(">");
          display.print(ura);
          display.print(":");
          display.print(minuta);
          display.print("<");
          if(on_clock) {
            display.setCursor(20,20);
            display.print("ON");
          } else {
            display.setCursor(85,20);
            display.print("OFF");
          }
          display.display();
        }
        else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
          btn_pressed = false;
          if(ura >= 10) {
            pos = 40;
          } else {
            pos = 50;
          }
          display.clearDisplay();
          display.drawBitmap(50,0,alarm_bitMap,32,32,WHITE);
          display.setCursor(pos, 50);
          display.print(ura);
          display.print(":");
          display.print(minuta);
          if(on_clock) {
            display.setCursor(10,20);
            display.print(">ON");
          } else {
            display.setCursor(85,20);
            display.print("OFF<");
          }
          display.display();
          Btn_up();
          while(true) {
            delay(btn_wait);
            if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
              display.clearDisplay();
              display.drawBitmap(50,0,alarm_bitMap,32,32,WHITE);
              display.setCursor(pos, 50);
              display.print(ura);
              display.print(":");
              display.print(minuta);
              on_clock = true;
              if(on_clock) {
                display.setCursor(15,20);
                display.print(">ON");
              } else {
                display.setCursor(85,20);
                display.print("OFF<");
              }
              display.display();
            }
            else if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
              display.clearDisplay();
              display.drawBitmap(50,0,alarm_bitMap,32,32,WHITE);
              display.setCursor(pos, 50);
              display.print(ura);
              display.print(":");
              display.print(minuta);
              on_clock = false;
              if(on_clock) {
                display.setCursor(15,20);
                display.print(">ON");
              } else {
                display.setCursor(85,20);
                display.print("OFF<");
              }
              display.display();
            }
            else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
              break_loop = true;
              btn_pressed = false;
              display.clearDisplay();
              display.drawBitmap(50,0,alarm_bitMap,32,32,WHITE);
              display.setCursor(pos, 50);
              display.print(ura);
              display.print(":");
              display.print(minuta);
              display.setCursor(5, 35);
              display.println("<");
              display.setCursor(115, 35);
              display.println(">");
              if(on_clock) {
                display.setCursor(20,20);
                display.print("ON");
              } else {
                display.setCursor(85,20);
                display.print("OFF");
              }
              display.display();
              Btn_up();
              break;
            }
          }
          if(break_loop) {
            break;
          }
        }
      }
    }
  }
}

//----------- VLAZNOST -------------//
void Vlaznost() {
  btn_pressed = false;
  bool break_loop(false);
  if(vlaznost_alarm >= 10) {
    pos = 50;
  } else {
    pos = 60;
  }
  display.clearDisplay();
  display.drawBitmap(48,0,moisture_bitMap,32,32,WHITE);
  display.setCursor(pos, 50);
  display.print(vlaznost_alarm);
  display.print("%");
  display.setCursor(5, 35);
  display.println("<");
  display.setCursor(115, 35);
  display.println(">");
  if(moist_on) {
    display.setCursor(20,20);
    display.print("ON");
  } else {
    display.setCursor(85,20);
    display.print("OFF");
  }
  display.display();
  Btn_up();
  while(true) {
    delay(btn_wait);
    if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
      Alarm();
      break;
    }
    else if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
      Nastavitve();
      break;
    }
    else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
      btn_pressed = false;
      if(vlaznost_alarm >= 10) {
        pos = 39;
      } else {
        pos = 44;
      }
      display.clearDisplay();
      display.drawBitmap(48,0,moisture_bitMap,32,32,WHITE);
      display.setCursor(pos, 50);
      display.print(">");
      display.print(vlaznost_alarm);
      display.print("%");
      display.print("<");
      if(moist_on) {
        display.setCursor(20,20);
        display.print("ON");
      } else {
        display.setCursor(85,20);
        display.print("OFF");
      }
      display.display();
      Btn_up();
      while(true) {
        delay(btn_wait);
        if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
          if(vlaznost_alarm == 0) {
            vlaznost_alarm = 0;
          } else {
            vlaznost_alarm--;
          }
          display.clearDisplay();
          display.drawBitmap(48,0,moisture_bitMap,32,32,WHITE);
          display.setCursor(pos, 50);
          display.print(">");
          display.print(vlaznost_alarm);
          display.print("%");
          display.print("<");
          if(moist_on) {
            display.setCursor(20,20);
            display.print("ON");
          } else {
            display.setCursor(85,20);
            display.print("OFF");
          }
          display.display();
        }
        else if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
          if(vlaznost_alarm == 99) {
            vlaznost_alarm = 99;
          } else {
            vlaznost_alarm++;
          }
          if(vlaznost_alarm >= 10) {
            pos = 39;
          } else {
            pos = 44;
          }
          display.clearDisplay();
          display.drawBitmap(48,0,moisture_bitMap,32,32,WHITE);
          display.setCursor(pos, 50);
          display.print(">");
          display.print(vlaznost_alarm);
          display.print("%");
          display.print("<");
          if(moist_on) {
            display.setCursor(20,20);
            display.print("ON");
          } else {
            display.setCursor(85,20);
            display.print("OFF");
          }
          display.display();
        }
        else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
          btn_pressed = false;
          display.clearDisplay();
          if(vlaznost_alarm >= 10) {
            pos = 39;
          } else {
            pos = 44;
          }
          display.clearDisplay();
          display.drawBitmap(48,0,moisture_bitMap,32,32,WHITE);
          display.setCursor(pos, 50);
          display.print(vlaznost_alarm);
          display.print("%");
          if(moist_on) {
            display.setCursor(10,20);
            display.print(">ON");
          } else {
            display.setCursor(85,20);
            display.print("OFF<");
          }
          display.display();
          Btn_up();
          while(true) {
            delay(btn_wait);
            if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
              if(vlaznost_alarm >= 10) {
                pos = 50;
              } else {
                pos = 60;
              }
              display.clearDisplay();
              display.drawBitmap(48,0,moisture_bitMap,32,32,WHITE);
              display.setCursor(pos, 50);
              display.print(vlaznost_alarm);
              display.print("%");
              moist_on = true;
              if(moist_on) {
                display.setCursor(10,20);
                display.print(">ON");
              } else {
                display.setCursor(85,20);
                display.print("OFF<");
              }
              display.display();
            }
            else if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
              display.clearDisplay();
              if(vlaznost_alarm >= 10) {
                pos = 50;
              } else {
                pos = 60;
              }
              display.clearDisplay();
              display.drawBitmap(48,0,moisture_bitMap,32,32,WHITE);
              display.setCursor(pos, 50);
              display.print(vlaznost_alarm);
              display.print("%");
              moist_on = false;
              if(moist_on) {
                display.setCursor(10,20);
                display.print(">ON");
              } else {
                display.setCursor(85,20);
                display.print("OFF<");
              }
              display.display();
            }
            else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
              break_loop = true;
              btn_pressed = false;
              if(vlaznost_alarm >= 10) {
                pos = 50;
              } else {
                pos = 60;
              }
              display.clearDisplay();
              display.drawBitmap(48,0,moisture_bitMap,32,32,WHITE);
              display.setCursor(pos, 50);
              display.print(vlaznost_alarm);
              display.print("%");
              display.setCursor(5, 35);
              display.println("<");
              display.setCursor(115, 35);
              display.println(">");
              if(moist_on) {
                display.setCursor(20,20);
                display.print("ON");
              } else {
                display.setCursor(85,20);
                display.print("OFF");
              }
              display.display();
              Btn_up();
              break;
            }
          }
          if(break_loop) {
            break;
          }
        }
      }
    }
  }
}

//----------- NASTAVITVE OLED ------------//
void Nastavitve_OLED() {
  display.clearDisplay();
  display.setCursor(0,5);
  display.print("Ura: ");
  display.println(h);
  display.print("Min: ");
  display.println(m);
  display.print("Btn: ");
  display.println(btn_wait);
  display.print("Pmp: ");
  display.println(pump_on/1000);
  display.print("v_-: ");
  display.println(min_vlaga);
  display.print("v_+: ");
  display.println(max_vlaga);
  display.print("Pmp: ");
  display.println(!digitalRead(PUMP));
  display.setCursor(70,5);
  display.println("Kal.");
  display.setCursor(70,13);
  display.println("Izh.");
  display.display();
}


//----------- NASTAVITVE -------------//
void Nastavitve() {
  btn_pressed = false;
  bool break_loop(false);
  display.clearDisplay();
  display.drawBitmap(48,15,settings_bitMap,32,32,WHITE);
  display.setCursor(5, 35);
  display.println("<");
  display.setCursor(115, 35);
  display.println(">");
  display.display();
  Btn_up();
  while(true) {
    delay(btn_wait);
    if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
      Vlaznost();
      break;
    }
    else if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
      Menu();
      break;
    }
    else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
      btn_pressed = false;
      display.setFont();
      display.setTextSize(1);
      Nastavitve_OLED();
      display.setCursor(55,5);
      display.println("<");
      display.display();
      Btn_up();
      while(true) {
        delay(btn_wait);
        if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
          if(h >= 23) {
            h = 0;
          } else {
            h++;
          }
          Nastavitve_OLED();
          display.setCursor(55,5);
          display.println("<");
          display.display();
        }
        else if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
          if(h <= 0) {
            h = 23;
          } else {
            h--;
          }
          Nastavitve_OLED();
          display.setCursor(55,5);
          display.println("<");
          display.display();
        }
        else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
          btn_pressed = false;
          Nastavitve_OLED();
          display.setCursor(55,12);
          display.println("<");
          display.display();
          Btn_up();
          while(true) {
            delay(btn_wait);
            if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
              if(m >= 59) {
                m = 0;
              } else {
                m++;
              }
              Nastavitve_OLED();
              display.setCursor(55,12);
              display.println("<");
              display.display();
            }
            else if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
              if(m <= 0) {
                m = 59;
              } else {
                m--;
              }
              Nastavitve_OLED();
              display.setCursor(55,12);
              display.println("<");
              display.display();
            }
            else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
              btn_pressed = false;
              Nastavitve_OLED();
              display.setCursor(55,20);
              display.println("<");
              display.display();
              Btn_up();
              while(true) {
                delay(btn_wait);
                if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
                  if(btn_wait >= 500) {
                    btn_wait = 500;
                  } else {
                    btn_wait += 50;
                  }
                  Nastavitve_OLED();
                  display.setCursor(55,20);
                  display.println("<");
                  display.display();
                }
                else if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
                  if(btn_wait <= 50) {
                    btn_wait = 50;
                  } else {
                    btn_wait -= 50;
                  }
                  Nastavitve_OLED();
                  display.setCursor(55,20);
                  display.println("<");
                  display.display();
                }
                else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
                  btn_pressed = false;
                  Nastavitve_OLED();
                  display.setCursor(55,28);
                  display.println("<");
                  display.display();
                  Btn_up();
                  while(true) {
                    delay(btn_wait);
                    if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
                      if(pump_on >= 10000) {
                        pump_on = 10000;
                      } else {
                        pump_on += 1000;
                      }
                      Nastavitve_OLED();
                      display.setCursor(55,28);
                      display.println("<");
                      display.display();
                    }
                    else if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
                      if(pump_on <= 1000) {
                        pump_on = 1000;
                      } else {
                        pump_on -= 1000;
                      }
                      Nastavitve_OLED();
                      display.setCursor(55,28);
                      display.println("<");
                      display.display();
                    }
                    else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
                      btn_pressed = false;
                      Nastavitve_OLED();
                      display.setCursor(55,37);
                      display.println("<");
                      display.display();
                      Btn_up();
                      while(true) {
                        delay(btn_wait);
                        if((!digitalRead(BTN_L)) && digitalRead(BTN_D)) {
                          if(min_vlaga <= max_vlaga) {
                            min_vlaga = max_vlaga + 1;
                          } else {
                            min_vlaga--;
                          }
                          Nastavitve_OLED();
                          display.setCursor(55,37);
                          display.println("<");
                          display.display();
                        }
                        else if((!digitalRead(BTN_D)) && digitalRead(BTN_L)) {
                          if(min_vlaga >= 1023) {
                            min_vlaga = 1023;
                          } else {
                            min_vlaga++;
                          }
                          Nastavitve_OLED();
                          display.setCursor(55,37);
                          display.println("<");
                          display.display();
                        }
                        else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
                          btn_pressed = false;
                          Nastavitve_OLED();
                          display.setCursor(55,45);
                          display.println("<");
                          display.display();
                          Btn_up();
                          while(true) {
                            delay(btn_wait);
                            if(digitalRead(BTN_L) && !(digitalRead(BTN_D))) {
                              if(max_vlaga >= min_vlaga) {
                                max_vlaga = min_vlaga - 1;
                              } else {
                                max_vlaga++;
                              }
                              Nastavitve_OLED();
                              display.setCursor(55,45);
                              display.println("<");
                              display.display();
                            }
                            else if(digitalRead(BTN_D) && !(digitalRead(BTN_L))) {
                              if(max_vlaga <= 1) {
                                max_vlaga = 1;
                              } else {
                                max_vlaga--;
                              }
                              Nastavitve_OLED();
                              display.setCursor(55,45);
                              display.println("<");
                              display.display();
                            }
                            else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
                              btn_pressed = false;
                              Nastavitve_OLED();
                              display.setCursor(55,52);
                              display.println("<");
                              display.display();
                              Btn_up();
                              while(true) {
                                delay(btn_wait);
                                if(digitalRead(BTN_L) && !(digitalRead(BTN_D))) {
                                  digitalWrite(PUMP, LOW);
                                  Nastavitve_OLED();
                                  display.setCursor(55,52);
                                  display.println("<");
                                  display.display();
                                }
                                else if(digitalRead(BTN_D) && !(digitalRead(BTN_L))) {
                                  digitalWrite(PUMP, HIGH);
                                  Nastavitve_OLED();
                                  display.setCursor(55,52);
                                  display.println("<");
                                  display.display();
                                }
                                else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
                                  btn_pressed = false;
                                  Nastavitve_OLED();
                                  display.setCursor(100,5);
                                  display.println("<");
                                  display.display();
                                  Btn_up();
                                  while(true) {
                                    delay(btn_wait);
                                    if(digitalRead(BTN_L) && !(digitalRead(BTN_D))) {
                                      Kalibracija();
                                      Nastavitve_OLED();
                                      display.setCursor(100,5);
                                      display.println("<");
                                      display.display();
                                    }
                                    else if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
                                      btn_pressed = false;
                                      Nastavitve_OLED();
                                      display.setCursor(100,13);
                                      display.println("<");
                                      display.display();
                                      Btn_up();
                                      while(true) {
                                        delay(btn_wait);
                                        if(!digitalRead(BTN_L) || !(digitalRead(BTN_D))) {
                                          break_loop = true;
                                          display.setFont(&FreeMono9pt7b);
                                          display.setTextSize(0);
                                          display.clearDisplay();
                                          display.drawBitmap(48,15,settings_bitMap,32,32,WHITE);
                                          display.setCursor(5, 35);
                                          display.println("<");
                                          display.setCursor(115, 35);
                                          display.println(">");
                                          display.display();
                                          break;
                                        }
                                      }
                                    }
                                    if(break_loop) {
                                        break;
                                    }
                                  }
                                }
                                if(break_loop) {
                                  break;
                                }
                              }
                            }
                            if(break_loop) {
                              break;
                            }
                          }
                        }
                        if(break_loop) {
                          break;
                        }
                      }
                    }
                    if(break_loop) {
                      break;
                    }
                  }
                }
                if(break_loop) {
                  break;
                }
              }
              if(break_loop) {
                break;
              }
            }
            if(break_loop) {
              break;
            }
          }
          if(break_loop) {
            break;
          }
        }
        if(break_loop) {
          break;
        }
      }
    }
    btn_pressed = false;
    break_loop = false;
  }
}

//----------- URA -------------//
void Clock_now() {
  s += (end_time - start_time);
  if(s >= 60000) {
    s -= 60000;
    m++;
  }
  if(m >= 60) {
    m=0;
    h++;
  }
  if(h >= 23) {
    h=0;
  }
}

//----------- SERIAL -------------//
void PrintSerial() {
  for (byte i(0); i < 30; i++) {
    Serial.println("");
  }
}

//----------- LOOP -------------//
void loop() {
  ReadSensor();
  PrintOLED();
  //PrintSerial();
  if(!(digitalRead(BTN_L)) && !(digitalRead(BTN_D))) {
    Menu();
    PrintOLED();
    btn_pressed = false;
    Btn_up();
  }
  if((ura == h && minuta == m && on_clock && !alarm_off) || ((vlaznost_alarm > vlaga_value) && moist_on && !alarm_off)) {
    digitalWrite(PUMP, LOW);
    pump_start = end_time;
    //digitalWrite(LED_TEST, HIGH);
    alarm_off = true;
  }
  if(((end_time - pump_start) >= pump_on) && alarm_off) {
    digitalWrite(PUMP, HIGH);
    //digitalWrite(LED_TEST, LOW);
  }
  if((end_time - pump_start) >= 60050) {
    alarm_off = false;
  }
  if(end_time - start_time >= 1000) {
    Clock_now();
    start_time = end_time;
  }
  end_time = millis();
  if(end_time < start_time) {
    s = sizeof(unsigned long) - start_time;
    start_time = 0;
  }
}
