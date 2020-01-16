/* File: Port.h
 * Authors: Dylan Tomberlin
 * Description: 
 */

#pragma once

#include <stdint.h>
void setUpHardwareTimer(uint16_t tickFrequency); //Probably need a ISR CB to be passed in