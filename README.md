<center><h1>ESP8266 + BN-220 GPS Tracker</h1></center>

This ESP8266 can be used to build a compact GPS logger that tracks location data (LAT/LONG) as well as timestamps in any specified intervals.

<center><h1>Hardware</h1></center>

All the hardware being used in this project is a [Hiletgo ESP8266](https://a.co/d/daYSCQz) and a [Beitian BN-220](https://a.co/d/0MroIBl) attached to a breadboard not much else is needed to get the functionality though if you want to add a beeper and some other LED's to indicate certain sections of code or functions you can add those with the rest of the availble pins.

<center><h1>Wiring</h1></center>

When wiring the BN-220 to the ESP8266 you will only need to solder a total of four wires GND, TX, RX, and VCC or (3.3-5v), The wiring will go as follows with explainations why.

Wiring:
  - BN-220 White (TX) > ESP8266 D2 (RX)
      The gps will transmit the data through the TX wire and the esp8266 needs to receive that data through the RX pin.
  - BN-220 Green (RX) > ESP8266 D1 (TX)
      The gps will receive data being transmitted from the esp8266 so the these two pins need to connect as listed.
  - BN-220 Black (GND) > ESP8266 GND
      Any pin on the ESP8266 labeled GND will be fine to the connect the BN-220 to.
  - BN-220 Red (VCC) > ESP8266 3V3 (3.3V)
      The BN-220 can operate on the range of 3.0-5.5v and since this board can supply 3.3v it will be capable of powering the GPS unit.

<center><h1>Software</h1></center>
