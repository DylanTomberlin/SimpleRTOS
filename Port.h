/* File: Port.h
 * Authors: Dylan Tomberlin
 * Description: Functions needed to be implemented for a specific chip
 */

#pragma once

#include <stdint.h>
void setUpHardwareTimer(uint16_t tickFrequency); //Probably need a ISR CB to be passed in
void sleepUntilInterrupt();    //Put system to sleep until woken by ISR