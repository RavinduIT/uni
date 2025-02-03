#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char processID[10];     // Process identifier
    int burstTime;          // Total execution time
    int remainingTime;      // Time left to complete
    int waitingTime;        // Time spent waiting
    int turnaroundTime;     // Total time from arrival to completion
    int priorityLevel;      // Priority of the process (0 is highest)
} Task;

void executeRoundRobin(Task *taskQueue, int count, int timeSlice) {
    int currentTime = 0;
    int allDone;

    do {
        allDone = 1;
        for (int i = 0; i < count; i++) {
            if (taskQueue[i].remainingTime > 0) {
                allDone = 0;
                if (taskQueue[i].remainingTime > timeSlice) {
                    currentTime += timeSlice;
                    taskQueue[i].remainingTime -= timeSlice;
                } else {
                    currentTime += taskQueue[i].remainingTime;
                    taskQueue[i].waitingTime = currentTime - taskQueue[i].burstTime;
                    taskQueue[i].turnaroundTime = currentTime;
                    taskQueue[i].remainingTime = 0;
                }
            }
        }
    } while (!allDone);
}

void executeSJF(Task *taskQueue, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (taskQueue[i].burstTime > taskQueue[j].burstTime) {
                Task temp = taskQueue[i];
                taskQueue[i] = taskQueue[j];
                taskQueue[j] = temp;
            }
        }
    }

    int currentTime = 0;
    for (int i = 0; i < count; i++) {
        taskQueue[i].waitingTime = currentTime;
        currentTime += taskQueue[i].burstTime;
        taskQueue[i].turnaroundTime = currentTime;
    }
}

void executeFIFO(Task *taskQueue, int count) {
    int currentTime = 0;
    for (int i = 0; i < count; i++) {
        taskQueue[i].waitingTime = currentTime;
        currentTime += taskQueue[i].burstTime;
        taskQueue[i].turnaroundTime = currentTime;
    }
}

void multilevelScheduling(Task *tasks, int totalTasks) {
    Task queues[4][totalTasks];
    int queueSizes[4] = {0};

    for (int i = 0; i < totalTasks; i++) {
        queues[tasks[i].priorityLevel][queueSizes[tasks[i].priorityLevel]++] = tasks[i];
    }

    int timeSlice = 20;

    executeRoundRobin(queues[0], queueSizes[0], timeSlice);
    executeSJF(queues[1], queueSizes[1]);
    executeSJF(queues[2], queueSizes[2]);
    executeFIFO(queues[3], queueSizes[3]);

    printf("%-10s %-15s %-15s\n", "Process ID", "Waiting Time", "Turnaround Time");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < queueSizes[i]; j++) {
            printf("%-10s %-15d %-15d\n", queues[i][j].processID, queues[i][j].waitingTime, queues[i][j].turnaroundTime);
        }
    }
}

int main() {
    int processCount;
    printf("Enter the number of processes: ");
    scanf("%d", &processCount);

    Task taskList[processCount];
    for (int i = 0; i < processCount; i++) {
        printf("Enter ID for process %d: ", i + 1);
        scanf("%s", taskList[i].processID);
        printf("Enter priority (0-3) for process %d (0 is highest): ", i + 1);
        scanf("%d", &taskList[i].priorityLevel);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &taskList[i].burstTime);
        taskList[i].remainingTime = taskList[i].burstTime;
    }

    multilevelScheduling(taskList, processCount);

    return 0;
}