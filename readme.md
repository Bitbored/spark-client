spark-client
============

libraries for the [Spark Core](https://www.spark.io/) that provides access to the ATT IOT platform.

### Installation
1. Download the source code
	2a. Upload it to [the Spark online IDE](https://www.spark.io/build/)
	2b. Use [the Spark Command line utility](http://docs.spark.io/cli/)
	
### Instructions
1. Setup the SPARK hardware
	- LED + 1K resistor R1 connected to pin D0
	- LDR + 10K resistor R2 connected to pin A0
	```
	      _____________________________________________
	     |                                            |
	   --|---------------------------------------     |
	  / A0 A1 A2 A3 A4 A5 A6 A7 RX  TX  GND VIN |     |
	  |                             _        ___|     |
	  | ||    |||||||||||||||||    |_| mode |   |     |
	  | ||    ||||||CC3000|||||  ( )_       |   |     |
	  | ||    |||||||||||||||||    |_| rst  |___|     |
	  |                                         |     |
	  \ D0 D1 D2 D3 D4 D5 D6 D7 GND 3V3 RST 3V3 |     |
	   --|-----------------------|---------------     |
	     |               _       |           |        |
	     o---/\/\/\/\---(_)------o           _        |
	            R1      LED      |          (~)  LDR  |
	           (1K)              |           |        |
	                             |           |        |
	                             |-/\/\/\/\--o-------o
	                                  R2
	                                 (10K)
```
2. Open the project in the Spark IDE (https://www.spark.io/build/)
3. Fill in the missing strings (deviceId, clientId, clientKey, mac) and optionally change/add the sensor & actuator names, ids, descriptions, types
	 For extra actuators, make certain to extend the callback code at the end of the sketch.
4. Compile and flash the Spark Core with the new firmware
