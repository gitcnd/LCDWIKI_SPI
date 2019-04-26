// WORKS!!!

/*
  Any_Blink_1s.ino v1.0 - This code blinks an LED for 1s - useful for checking if you got the Arduino NANO HZ right

*/

#include <SerialID.h>	// So we know what code and version is running inside our MCUs - see https://github.com/gitcnd/SerialID
SerialIDset("\n#\tv2.01 " __FILE__ "\t" __DATE__ " " __TIME__);


// #ifdef TEENSYDUINO

// #ifdef ARDUINO_ESP8266_NODEMCU // Wemos_D1_ESP8266_NodeMCU_1

// #ifdef ARDUINO_AVR_PRO	// Arduino_Pro_Mini33



// IMPORTANT: LCDWIKI_SPI LIBRARY MUST BE SPECIFICALLY
// CONFIGURED FOR EITHER THE TFT SHIELD OR THE BREAKOUT BOARD.

//This program is a demo of displaying string

//when using the BREAKOUT BOARD only and using these hardware spi lines to the LCD,
//the SDA pin and SCK pin is defined by the system and can't be modified.
//if you don't need to control the LED pin,you can set it to 3.3V and set the pin definition to -1.
//other pins can be defined by youself,for example
//pin usage as follow:
//                 CS  A0/DC  RESET  SDA  SCK  LED    VCC     GND    
//ESP8266 D1 nimi  D1   D3     D2    D7   D5   D4   5V/3.3V   GND

#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library

//paramters define
#define MODEL SSD1283A
#define CS   10
#define CD   12 // Chris - not connected - do we need it?
#define SDA  11 // A2   //if you use the hardware spi,this pin is no need to set - MOSI
#define MOSI SDA
#define MISO 8	// unused
#define SCK  13 // A1   //if you use the hardware spi,this pin is no need to set
#define RST  9 // not connected
#define LED  -1   //if you don't need to control the LED pin,you should set it to -1 and set it to 3.3V

//the definiens of hardware spi mode as follow:
//if the IC model is known or the modules is unreadable,you can use this constructed function
//LCDWIKI_SPI mylcd(MODEL,CS,CD,RST,LED); 
LCDWIKI_SPI mylcd(MODEL,CS,CD, MISO, MOSI, RST, SCK, LED); 
//	LCDWIKI_SPI(uint16_t model,int8_t cs, int8_t cd, int8_t miso, int8_t mosi, int8_t reset, int8_t clk, int8_t led);

#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void setup() 
{
  SerialIDshow(115200); // starts Serial.
  mylcd.Init_LCD();
  mylcd.Fill_Screen(BLACK);
}

void loop() 
{
  mylcd.Set_Text_Mode(0);
  
  mylcd.Fill_Screen(0x0000);
  mylcd.Set_Text_colour(RED);
  mylcd.Set_Text_Back_colour(BLACK);
  mylcd.Set_Text_Size(1);
  mylcd.Print_String("Hello World!", 0, 0);
  mylcd.Print_Number_Float(01234.56789, 2, 0, 8, '.', 0, ' ');  
  mylcd.Print_Number_Int(0xDEADBEF, 0, 16, 0, ' ',16);

  mylcd.Set_Text_colour(GREEN);
  mylcd.Set_Text_Size(2);
  mylcd.Print_String("Hello", 0, 32);
  mylcd.Print_Number_Float(01234.56789, 2, 0, 48, '.', 0, ' ');  
  mylcd.Print_Number_Int(0xDEADBEF, 0, 64, 0, ' ',16);

  mylcd.Set_Text_colour(BLUE);
  mylcd.Set_Text_Size(3);
  mylcd.Print_String("Hello", 0, 86);
  mylcd.Print_Number_Float(01234.56789, 2, 0, 110, '.', 0, ' ');  
  mylcd.Print_Number_Int(0xDEADBEF, 0, 134, 0, ' ',16);

  delay(3000);
}











/*

Arduino_Pro_Mini33
        -DF_CPU=8000000L
        -DARDUINO=10807
        -DARDUINO_AVR_PRO
        -DARDUINO_ARCH_AVR

Arduino_Nano
        -DF_CPU=16000000L
        -DARDUINO=10807
        -DARDUINO_AVR_NANO
        -DARDUINO_ARCH_AVR

Teensy
        -D__MK20DX256__
        -DTEENSYDUINO=144
        -DARDUINO=10807
        -DF_CPU=96000000
        -DUSB_SERIAL
        -DLAYOUT_US_ENGLISH

Wemos_D1_ESP8266_NodeMCU_1
        -D__ets__
        -DICACHE_FLASH
        -DF_CPU=80000000L
        -DLWIP_OPEN_SRC
        -DTCP_MSS=536
        -DARDUINO=10807
        -DARDUINO_ESP8266_NODEMCU
        -DARDUINO_ARCH_ESP8266
        -DARDUINO_BOARD=\"ESP8266_NODEMCU\"
        -DESP8266

 */

