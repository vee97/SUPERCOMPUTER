# SUPERCOMPUTER
Master control panel code and communication code that was used to test serial port communication.

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
  
NANO COMMUNICATION CODE
This code allows Nanos to read information from the serial port sent
from the control panel, and display corresponding images/animations on
the OLEDs.


