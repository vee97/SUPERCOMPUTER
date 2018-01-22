/*
  Code Development Team
  DIGF 2005 - Atelier II
  Professor Nick Puckett
  Tuesday January 23, 2018
  
  NANO COMMUNICATION CODE
  This code allows Nanos to read information from the serial port sent
  from the control panel, and display corresponding images/animations on
  the OLEDs.

  THE CIRCUIT
    RX is digital pin 8 (connect to TX of other device)
    TX is digital pin 9 (connect to RX of other device)
    SDA connected to A4
    SCL connected to A5
    GND connected to GND
    VCC connected to VTN

  REFERENCES:
  https://www.arduino.cc/en/Tutorial/SoftwareSerialExample
  https://www.arduino.cc/reference/en/language/variables/data-types/bool/
  http://forum.arduino.cc/index.php?topic=42603.0
*/

// include necessary libraries
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#include <SoftwareSerial.h>

int incoming;

SoftwareSerial mySerial(8, 9); // RX, TX

// select correct OLED model
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {

  pinMode(13, OUTPUT);         // set pin 13 as output

  // set pins for OLED
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  u8g2.begin(4, 5, 6);

  mySerial.begin(4800);
  mySerial.println("Hello, world?");

  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {

  // OLED clear buffer
  u8g2.clearBuffer(); // clear the internal memory

  // put your main code here, to run repeatedly:
  if (mySerial.available()) {
    incoming = mySerial.read();
    //mySerial.println(incoming);
    Serial.println(mySerial.read());

    // if incoming value read is 1, play heated animation
    if (incoming == 1) {
      heated();
    }

    // if incoming value read is 2, play heated animation
    if (incoming == 2) {
      poisoned();
    }

    // if incoming value read is 3, play heated animation
    if (incoming == 3) {
      watered();
    }

    // if incoming value read is 0, clear display (replace with neutral animation)
    if (incoming == 0) {
      u8g2.clearBuffer();     // clear the internal memory, clear display
    }
  }
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(500);
}

// snowman icon test function
void drawSnowman(int x, int y) {
  u8g2.setFont(u8g2_font_unifont_t_symbols);
  u8g2.drawGlyph(x, y, 0x2603);  /* dec 9731/hex 2603 Snowman */
}

// FUNCTIONS FOR DRAWING ANIMATIONS ACCORDING TO THE INPUTS

void heated() {
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.drawStr(0, 15, "Heated");
}

void poisoned() {
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.drawStr(0, 15, "Poisoned");
}

void watered() {
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.drawStr(0, 15, "Watered");
}

