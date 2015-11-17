/**********************************************
 *
 * temp.cpp
 *
 * Read temperature on Arduino from any NTC resistor
 *
 * Per-Ola Gustavsson
 * http://marsba.se
 * pelle@marsba.se
 *
 *
 *
 * Copyright 2015 Per-Ola Gustavsson
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *********************************************/

#include <Arduino.h>
#include "temp.h"
	
const byte TEMP_READINGS = 4;			// Get average temp over several readings

float tempGetK (int pin, int pullupOhm, int NTCOhm25, int NTCB25_100) 
{
	// Read from sensor
	int sensorValue = 0;
	for(int i = 0; i < TEMP_READINGS; i++) {
		sensorValue += analogRead(pin);    
	}
	sensorValue = sensorValue / TEMP_READINGS;  
	
	// Avoid divide by zero errors
	if (sensorValue == 0)
		return 1000 + TEMP_0C;
	if (sensorValue == 1023)
		return 0;

	// Calculate current NTC resistance
	float NTCOhm = (float)pullupOhm * (float)sensorValue / (float)(1023-sensorValue);
	// Calculate and return temperature in Kelvin
	return 1 / (log( NTCOhm / (float)NTCOhm25 ) / (float)NTCB25_100 + 1 / TEMP_25C);
}

float tempGetC (int pin, int pullupOhm, int NTCOhm25, int NTCB25_100) 
{
	// Convert from Kelvin to Celcius
	return tempGetK(pin, pullupOhm, NTCOhm25, NTCB25_100) - TEMP_0C;
}

