/* File: Tick.h
 * Authors: Dylan Tomberlin
 * Description: 
 */

#pragma once
#include <stdint.h>

void ISRTimerTick();//increment system time, schedule scheduler task
uint32_t TickGetSystemTime();