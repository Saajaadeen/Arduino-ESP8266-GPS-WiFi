<center><h1>Arduino ESP8266 + BN-220 GPS Tracker</h1></center>

This ESP8266 can be used to build a compact GPS logger that tracks location data (LAT/LONG) as well as timestamps in any specified intervals.

<center><h1>Program Description</h1></center>

When the board is first plugged in there is a delay to allow the user time to open the serial monitor and view the information being displayed (anything related to the serial monitor will be removed in the production version to allow for better performance), afterwards a webserver is created to view the data in your browser, the ip address of the server will be displayed on the screen for the user to view. The GPS will begin transmitting the data and the ESP8266 will start to receive. In the event the GPS cannot obtain a datastream an error will occur until the datastream is established, once a stream is established GPS data like sats, lat/long, time and date will print to the serial monitor. On the frontend of the webserver the data will show everything in the serial monitor.

<center><h1>Hardware</h1></center>

All the hardware being used in this project is a [Hiletgo ESP8266](https://a.co/d/daYSCQz) and a [Beitian BN-220](https://a.co/d/0MroIBl) attached to a breadboard not much else is needed to get the functionality though if you want to add a beeper and some other LED's to indicate certain sections of code or functions you can add those with the rest of the availble pins.

<center><h1>Wiring</h1></center>

When wiring the BN-220 to the ESP8266 you will only need to solder a total of four wires GND, TX, RX, and VCC or (3.3-5v), The wiring will go as follows with explainations why.

**Wiring:**
- BN-220 White (TX) -> ESP8266 D2 (RX)
- BN-220 Green (RX) -> ESP8266 D1 (TX)
- BN-220 Black (GND) -> ESP8266 GND
- BN-220 Red (VCC) -> ESP8266 3V3 (3.3V)
- 
<center><h1>Authors</h1></center>

This project was created and maintained by Saajaadeen M. Jeffries
