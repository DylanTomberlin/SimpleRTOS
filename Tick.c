/* File: Tick.c
 * Authors: Dylan Tomberlin
 * Description: 
 */

#include "Tick.h"

uint16_t systemTime;

uint32_t TickGetSystemTime()
{
    return systemTime;
}