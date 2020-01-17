/* File: Scheduler.c
 * Authors: Dylan Tomberlin
 * Description: 
 */

#include "Scheduler.h"
#include "Task.h"
#include "Tick.h"
#include <stddef.h>
#include <malloc.h>

//global unscheduled tasks queue
Task *unscheduledTasks;
Task *scheduledTasks;
//TODO add unscheduled tail so ISR does not need to traverse entire linked list

/*
void CBScheduleTask(void *scheduleTasksData)
{

}
*/

void schedulerAddToQueue(Task *toBeQueued, uint32_t scheduleForMs)
{
    if(!toBeQueued)      {return;}

    toBeQueued->scheduledTime = scheduleForMs;
    if(!unscheduledTasks) 
    {
        unscheduledTasks = toBeQueued;
        return;
    }

    Task *curr = unscheduledTasks;
    while(curr->queueNext != NULL)
    {
        curr = curr->queueNext;
    }
    
    curr->queueNext = toBeQueued;
    toBeQueued->queueNext = NULL;
}



void schedulerScheduleTask(Task *toBeScheduled)
{
    if(!toBeScheduled) {return;}

/*
    TasksList *newNode = malloc(sizeof(TasksList));
    if(!newNode) {return;} //TODO: implement return error codes
    newNode->currTask = toBeScheduled;
*/
    if(!scheduledTasks)
    {
        scheduledTasks = toBeScheduled;
        return;
    }

    Task *curr = scheduledTasks;
    while (curr->queueNext != NULL)
    {
        if(curr !=NULL)
        {
            //Place new task in order of next to execute, secondary sort by priority
            if(curr->queueNext->scheduledTime > toBeScheduled->scheduledTime 
            || (curr->queueNext->scheduledTime == toBeScheduled->scheduledTime && 
            curr->queueNext->priority))
            {
                toBeScheduled->queueNext = curr->queueNext;
                curr->queueNext = toBeScheduled;
                return;
            }
        }
    }
    
}
void schedulerExecuteTask(Task *toBeExecuted)
{
    if(!toBeExecuted) {return;}
    toBeExecuted->callBackPtr(toBeExecuted->dataPtr);
}

//runs in main loop every tick
void schedulerRun()
{
    uint32_t systemTime;

    while (scheduledTasks && unscheduledTasks)
    {
        
        systemTime = TickGetSystemTime();
        //Immediately execute late tasks or are scheduled for this tick
        while(scheduledTasks != NULL && scheduledTasks->scheduledTime <= systemTime)
        {
            Task *nextSceduled = scheduledTasks->queueNext;
            schedulerExecuteTask(scheduledTasks);
            scheduledTasks->queueNext = NULL;
            scheduledTasks = nextSceduled;
            systemTime = TickGetSystemTime();
        }

        //schedule queued tasks
        while(unscheduledTasks)
        {
            Task *next = unscheduledTasks->queueNext;
            schedulerScheduleTask(unscheduledTasks);
        }
    }
}