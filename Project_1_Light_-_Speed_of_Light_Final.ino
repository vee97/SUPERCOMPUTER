/*
Light Project
Vivian Wong
DIGF 1006 - Phyical Computing
OCAD University
Created on: January 19, 2016

Based on:

Blink Without Delay   
 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 modified 11 Nov 2013
 by Scott Fitzgerald
 modified 9 Jan 2017
 by Arturo Guadalupi 
 https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay

Example of flashing multiple LEDs at different rates without delays
 Author: Nick Gammon
 Date: 23 December 2012
̈ https://www.gammon.com.au/blink

Example†Title ̈†Example†Author ̈†URL

*/

// Identify which pins are connected to their respective LEDs
const byte redLED = 13; // red LED
const byte greenLED = 12; // uvLED
const byte whiteLED = 11; // fading white LED
const byte fadeLED2 = 9; // fading red LED1
const byte fadeLED = 10; // fading red LED2
const byte blueLED = 7; // blue LED
const byte rgbLED3 = 6; // RGBblue
const byte rgbLED = 5; // RGBgreen
const byte rgbLED2 = 3; // RGBred



// Assign time intervals for blinks in milliseconds
const unsigned long greenLEDinterval = 200;
const unsigned long redLEDinterval = 300;
const unsigned long rgbLEDinterval = 550;

// Assign time intervals between fades
const unsigned long fadeLEDinterval = 50;
const unsigned long fadeLED2interval = 20;
const unsigned long whiteLEDinterval = 50;

// Assign time intervals between fades for the red and green rgb LED
const unsigned long rgbLED2interval = 30;
const unsigned long rgbLED3interval = 70;

// Create a variable to hold the timer value of each LED
unsigned long greenLEDtimer;
unsigned long redLEDtimer;
unsigned long whiteLEDtimer;
unsigned long blueLEDtimer;
unsigned long fadeLEDtimer;
unsigned long fadeLED2timer;
unsigned long rgbLEDtimer;
unsigned long rgbLED2timer;
unsigned long rgbLED3timer;



// Assign initial value for brightness and fadeAmount for fading LEDs
int brightness = 0;
int brightness2 = 0;
int fadeAmount = 5;
int fadeAmount2 = 5;

void setup ()
  {
  // Assign output or input for each pin component
  pinMode (greenLED, OUTPUT);
  pinMode (redLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(fadeLED, OUTPUT);
  pinMode (fadeLED2, OUTPUT);
  pinMode(rgbLED, OUTPUT);
  pinMode(rgbLED2,OUTPUT);
  pinMode(rgbLED3, OUTPUT);


  // Current time in milliseconds assigned to each timer
  greenLEDtimer = millis ();
  redLEDtimer = millis ();
  fadeLEDtimer = millis();
  fadeLED2timer = millis();
  rgbLEDtimer = millis();
  whiteLEDtimer = millis();
  rgbLED2timer = millis();
  rgbLED3timer = millis();
  }


// code each LED toggle function to be called in loop later
// code for toggling blinking lights
void toggleGreenLED ()
  {
    if (digitalRead (greenLED) == LOW)
      digitalWrite (greenLED, HIGH);
    else
      digitalWrite (greenLED, LOW);

  // remember when this function is toggled
    greenLEDtimer = millis ();
  }

void toggleRedLED ()
  {
    if (digitalRead (redLED) == LOW)
      digitalWrite (redLED, HIGH);
    else
      digitalWrite (redLED, LOW);

    redLEDtimer = millis ();
  }

void toggleRgbLED ()
  {
    if (digitalRead (rgbLED) == LOW)
      digitalWrite (rgbLED, HIGH);
    else
      digitalWrite (rgbLED, LOW);

    rgbLEDtimer = millis ();
  }

// code for each of the fade lights
void toggleFadeLED ()
  {
    analogWrite(fadeLED, brightness);
    
    brightness = brightness + fadeAmount;
    
   if (brightness <= 0 || brightness >= 255) {
    
    fadeAmount = -fadeAmount;
   }
  fadeLEDtimer = millis ();
  }

void toggleFadeLED2 ()
  {
    analogWrite(fadeLED2, brightness2);

    brightness2 = brightness2 + fadeAmount2;

    if (brightness2 <= 0 || brightness2 >= 255) {

      fadeAmount2 = -fadeAmount2;
    }
    fadeLED2timer = millis ();
  }


void toggleRgbLED2 ()
  {
    analogWrite(rgbLED2, brightness2);

    brightness2 = brightness2 + fadeAmount2;

    if (brightness2 <= 0 || brightness2 >= 255) {

      fadeAmount2 = -fadeAmount2;
    }
    rgbLED2timer = millis ();
  }

void toggleRgbLED3 ()
  {
    analogWrite(rgbLED3, brightness2);

    brightness2 = brightness2 + fadeAmount2;

    if (brightness2 <= 0 || brightness2 >= 255) {

      fadeAmount2 = -fadeAmount2;
    }
    rgbLED3timer = millis ();
  }


void toggleWhiteLED ()
  {
    analogWrite(whiteLED, brightness);

    brightness = brightness + fadeAmount;

    if (brightness <= 0 || brightness >= 255) {

      fadeAmount = -fadeAmount;
    }
    whiteLEDtimer = millis ();
  }

  
void loop ()
  {
  // Check if current time minus toggled time is greater or equal to interval
  // if true, toggle specified LEDs, repeat for each LED
    
  if (millis () - greenLEDtimer >= greenLEDinterval)
    toggleGreenLED();

  if (millis () - redLEDtimer >= redLEDinterval)
    toggleRedLED();

  if (millis () - fadeLEDtimer >= fadeLEDinterval)
    toggleFadeLED();

  if (millis () - fadeLED2timer >= fadeLED2interval)
    toggleFadeLED2();

  if (millis () - rgbLEDtimer >= rgbLEDinterval)
    toggleRgbLED();

  if (millis () - rgbLED2timer >= rgbLED2interval)
    toggleRgbLED2();

  if (millis () - rgbLED3timer >= rgbLED3interval)
    toggleRgbLED3();

  if (millis () - whiteLEDtimer >= whiteLEDinterval)
    toggleWhiteLED();

// blue LED turned on constantly
  digitalWrite(blueLED, HIGH);
  }
