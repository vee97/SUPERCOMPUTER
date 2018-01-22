/*
  Code Development Team
  DIGF 2005 - Atelier II
  Professor Nick Puckett
  Tuesday January 23, 2018


  CONTROL PANEL & CENTRAL BRAIN CODE
  This code allows the control panel Arduino to read and check input values,
  display corresponding images on the Central Brain, and send appropriate
  information to each connected Arduino Nano using Software Serial.

  *** Note: Does not display images on Central Brain OLED yet. Waiting on code.
  *** Note: Does not have functions related to RGB LED yet.

  THE CIRCUIT
    RX is digital pin 8 (connect to TX of other device)
    TX is digital pin 9 (connect to RX of other device)

  REFERENCES:
  https://www.arduino.cc/en/Tutorial/SoftwareSerialExample
  https://www.arduino.cc/reference/en/language/variables/data-types/bool/
  http://forum.arduino.cc/index.php?topic=42603.0
*/

// include necessary libraries
#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9); // RX, TX

const int sensor1 = A0;    // select input pin A0 for photoresistor
const int sensor2 = A1;    // select input pin A1 for pressure sensor
const int sensor3 = A2;    // select input pin A2 for potentiometer

int sensorVal1 = 0;        // value read from the photoresistor
int sensorVal2 = 0;        // value read from the pressure sensor
int sensorVal3 = 0;        // value read from the potentiometer

int outputValue = 0;       // value output to the PWM (analog out)

bool heat;                 // set global variable of boolean for heat
bool poison;               // set global variable of boolean for poison
bool water;                // set global variable of boolean for water

byte i = 0;                // set global variable of byte for i

void setup() {
  Serial.begin(9600);      // initialize serial communications at 9600 bps
  mySerial.begin(4800);    // initialize software serial communications at 4800 bps
}

void loop() {
  // Call function to read sensor values of each input
  // Check range of values for each sensor and send message accordingly
  readInputs();
  checkLight();
  checkPressure();
  checkDial();
}

void readInputs() {
  // read each input sensor
  sensorVal1 = analogRead(sensor1);
  sensorVal2 = analogRead(sensor2);
  sensorVal3 = analogRead(sensor3);

  // print the results to the serial monitor:
  Serial.print("light = ");
  Serial.print(sensorVal1);
  Serial.print("\t pressure = ");
  Serial.print(sensorVal2);
  Serial.print("\t dial = ");
  Serial.println(sensorVal3);

  // wait 500 milliseconds before the next loop
  delay(500);
}


//// CHECKING FUNCTIONS TO DECIDE IF INPUTS ARE TRUE OR FALSE

void checkLight() {

  if (sensorVal1 > 400) {       // if value of sensor 1 (photoresistor) > 400
    heat = true;                // heat is true
    msg();                      // send message
  }
  else {                        // else, heat is false
    heat = false;
  }
  Serial.print("HEAT = ");      // print boolean values to serial port
  Serial.print(heat);
}

void checkPressure() {
  if (sensorVal2 > 500) {       // if value of sensor 2 (pressure) > 500
    poison = true;              // poison is true
    msg2();                     // send message 2
  }
  else {                        // else, poison is false
    poison = false;
  }
  Serial.print("\t POISON = "); // print boolean values to serial port
  Serial.print(poison);
}

void checkDial() {
  if (sensorVal3 > 500) {       // if value of sensor 3 (water) > 500
    water = true;               // water is true
    msg3();                     // send message
  }
  else {                        // else, water is false
    water = false;
  }
  Serial.print("\t WATER = ");  // print boolean values to serial port
  Serial.print(water);
  Serial.println("\n");         // skip a line
}


//// MESSAGE FUNCTIONS TO COMMUNICATE WITH SERIAL PORT BETWEEN NANOS

void msg() {
  if (mySerial.available()) {   // if mySerial is available
    i = 1;                      // byte i = 1
  }
  else {                        // else, byte i = 0
    i = 0;
  }
  mySerial.write(i);       // write i value to mySerial
  delay(2);                // delay for 2 ms
}

void msg2() {
  if (mySerial.available()) {   // if mySerial is available
    i = 2;                      // byte i = 2
  }
  else {                        // else, byte i = 0
    i = 0;
  }
  mySerial.write(i);       // write i value to mySerial
  delay(2);                // delay for 2 ms
}

void msg3() {
  if (mySerial.available()) {   // if mySerial is available
    i = 3;                      // byte i = 3
  }
  else {                        // else, byte i = 0
    i = 0;
  }
  mySerial.write(i);       // write i value to mySerial
  delay(2);                // delay for 2 ms
}


// PSUEDOCODE FOR SIMPLIFYING BELOW

void sendMessage() {
  // Serial.write(heat|water|poison)
  // Serial.write(1|0|0)
}

void checkMessage() {
  // if Serial.read(0|0|0)
  // play happy animation

  // if Serial.read(1|0|0)
  // play death animation

  // if Serial.read(0|1|0)
  // play happy animation

  // if Serial.read(0|0|1)
  // play happy animation

  // check which happened last, play animation for what happened last
}


