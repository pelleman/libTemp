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


#ifndef _TEMP_H_
#define _TEMP_H_

const float TEMP_0C = 273.150;			// 0 degree C in K
const float TEMP_25C = 298.150;			// 25 degree C in K

/**********************************************
 *
 * Connect the pullup resistor to analog reference voltage
 * Connect the NTC to ground
 *
 * pin is the analog pin used
 * pullupOhm is the resistance of the pullup resistor
 * NTCOhm25 is the resistance of the NTC at 25 degree C
 * NTCB25_100 is the B25/100 value of the NTC
 *
 * The resistance values must have the same ratio as the
 * actual values. Divide them by 42 or whatever to make them 
 * fit into an integer.
 *
 *********************************************/

float tempGetK(int pin, int pullupOhm, int NTCOhm25, int NTCB25_100);
float tempGetC(int pin, int pullupOhm, int NTCOhm25, int NTCB25_100);

#endif
