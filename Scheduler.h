/* File: Scheduler.h
 * Authors: Dylan Tomberlin
 * Description: 
 */
#pragma once

#include "Task.h"

//scheduleTasks Task
/*
void CBScheduleTask(void *scheduleTasksData);
typedef struct
{
    TasksList *unscheduledTasks;
} DataScheduleTask;
*/

void schedulerAddToQueue(Task *toBeQueued, uint32_t scheduleFor);
void schedulerScheduleTask(Task *toBeScheduled);
void schedulerExecuteTask(Task *toBeExecuted);
void schedulerRun();
