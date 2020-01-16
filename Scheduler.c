/* File: Scheduler.c
 * Authors: Dylan Tomberlin
 * Description: 
 */

#include "Scheduler.h"
#include "Task.h"
#include <stddef.h>

//global unscheduled tasks queue
const TasksList *unscheduledTasks;
const TasksList *scheduledTasks;

void CBScheduleTask(Data *scheduleTasksData)
{

}

void schedulerAddToQueue(Task *toBeQueued)
{
    if(!toBeQueued)      {return;}
    if(!unscheduledTasks) 
    {
        unscheduledTasks = toBeQueued;
        return;
    }

    TasksList *curr = unscheduledTasks;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    
    curr->next = toBeQueued;
}

void schedulerScheduleTask(Task *toBeScheduled, uint32_t scheduleFor)
{
    if(!toBeScheduled) {return;}

    if(!scheduledTasks)
    {
        scheduledTasks = toBeScheduled;
        return;
    }

    TasksList *curr = scheduledTasks;
    while (curr->next != NULL)
    {
        if(curr->currTask !=NULL)
        {
            //Place new task in order of next to execute, secondary sort by priority
            if(curr->next->currTask->scheduledTime > toBeScheduled->scheduledTime 
            || (curr->next->currTask->scheduledTime == toBeScheduled->scheduledTime && 
            curr->next->currTask->priority))
            {
                //TODO: need to malloc space for taskList node for toBeScheduled
                curr->next = toBeScheduled;
                toBeScheduled->next = 
            }
        }
    }
    
}
void schedulerExecuteTask(Task *toBeExecuted)
{

}