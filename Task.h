/* File: Task.h
 * Authors: Dylan Tomberlin
 * Description: 
 */

#pragma once

#include <stdint.h>

typedef struct Data{};

typedef struct
{
    uint8_t (*callBackPtr)(Data *dataPtr);
    Data *dataPtr;
    uint16_t priority;
    uint32_t scheduledTime;
} Task;

//Linked list node of tasks
typedef struct 
{
    Task *currTask;
    TasksList *next;
} TasksList;
