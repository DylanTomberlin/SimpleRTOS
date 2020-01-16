/* File: Task.h
 * Authors: Dylan Tomberlin
 * Description: 
 */

#pragma once

#include <stdint.h>

typedef struct
{
    void *dataPtr;
    uint32_t scheduledTime;
    Task *queueNext; //For making linked lists of tasks.  Not a secondary
                     //task to be kicked off by this one. Avoids needing Malloc
                     //to make linked list node
    uint16_t priority;
    uint8_t (*callBackPtr)(void *dataPtr);
} Task;

/*
//Linked list node of tasks
typedef struct 
{
    Task *currTask;
    TasksList *next;
} TasksList;
*/