# LCDWIKI_SPI
An SPI display library for LCD panels using ILI9325, ILI9328, ILI9341, HX8357D, HX8347G, HX8347I, ILI9486, ST7735S, or SSD1283A controllers


# SYNOPSIS

```C
  #include <LCDWIKI_GUI.h> //Core graphics library
  #include <LCDWIKI_SPI.h> //Hardware-specific library

  #define MODEL SSD1283A	// Which controller does your LCD use
  #define CS   10		// Chip Select SPI pin (Might be called SS) - Wire this to pin 10 on an Arduino Pro Mini
  #define CD   12
  #define SDA  11		// if you use the hardware spi,this pin is no need to set - Wire this to pin 11, MOSI, on a Pro Mini
  #define MOSI SDA		// An alias
  #define MISO 8		// unused - my SSD1283A is write-only (no read)
  #define SCK  13 		//if you use the hardware spi,this pin is no need to set - Wire to pin 13 on a Pro Mini
  #define RST  9		// Reset pin - I use 9 on my Pro Mini
  #define LED  -1		// My LED backlight is hard-wired to VCC: if you don't need to control the LED pin,you should set it to -1 and set it to 3.3V

  LCDWIKI_SPI mylcd(MODEL,CS,CD, MISO, MOSI, RST, SCK, LED); // Tell the lib what pins we are using

  #define  BLACK   0x0000
  #define RED     0xF800

  void setup() 
  {
    mylcd.Init_LCD();
    mylcd.Fill_Screen(BLACK);
  }

  void loop() {
    mylcd.Set_Text_Mode(0);
  
    mylcd.Set_Text_colour(RED);
    mylcd.Set_Text_Back_colour(BLACK);
    mylcd.Set_Text_Size(1);
    mylcd.Print_String("Hello World!", 0, 0);

    ...
  }
```

# FUNCTIONS


  See the header file


# HOW TO INSTALL

(Method 1)

1. Open a terminal (commandline, bash shell, whatever)
2. Change into your Arduino folder
```bash
   cd /Applications/Arduino.app/Contents/Java/libraries/
   (or)
   cd ~/Arduino/libraries/
```
3. grab and install this code
```bash
   git clone https://github.com/gitcnd/LCDWIKI_SPI.git
```
4. restart your arduino IDE
5. Choose File => Examples => LCDWIKI_SPI => hello
6. Hit the "build" button and enjoy!

(Method 2) - see https://www.arduino.cc/en/Guide/Libraries

1. Download the ZIP of this repo: https://github.com/gitcnd/LCDWIKI_SPI/archive/master.zip
2. In your IDE, select Sketch -> Include Library -> Add .ZIP Library
3. Choose File => Examples => LCDWIKI_SPI => hello
4. Hit the "build" button and enjoy!
