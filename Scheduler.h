/* File: Scheduler.h
 * Authors: Dylan Tomberlin
 * Description: 
 */
#pragma once

#include "Task.h"

//scheduleTasks Task
void CBScheduleTask(Data *scheduleTasksData);
typedef struct
{
    TasksList *unscheduledTasks;
} DataScheduleTask;

void schedulerAddToQueue(Task *toBeQueued);
void schedulerScheduleTask(Task *toBeScheduled, uint32_t scheduleFor);
void schedulerExecuteTask(Task *toBeExecuted);

