#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TIME_QUANTUM 20
#define MAX_PROCESSES 100

// Structure to represent a process
typedef struct {
    int pid;             // Process ID
    int burst_time;      // Burst time of the process
    int remaining_time;  // Remaining time for Round Robin
    int waiting_time;    // Waiting time of the process
    int turnaround_time; // Turnaround time of the process
    int arrival_time;    // Arrival time of the process
    bool completed;      // Whether the process is completed
} Process;

// Function prototypes
void round_robin(Process processes[], int *n, int *current_time);
void shortest_job_first(Process processes[], int *n, int *current_time);
void first_in_first_out(Process processes[], int *n, int *current_time);
void execute_queue(Process processes[], int *n, int *current_time, const char *queue_name, void (*scheduling_algorithm)(Process[], int *, int *));
void print_results(Process processes[], int n, const char *queue_name);

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process q0[MAX_PROCESSES], q1[MAX_PROCESSES], q2[MAX_PROCESSES], q3[MAX_PROCESSES]; // Queues for priorities 0 to 3
    int count_q0 = 0, count_q1 = 0, count_q2 = 0, count_q3 = 0;

    // Input processes and assign them to respective queues based on priority
    for (int i = 0; i < num_processes; i++) {
        int burst_time, priority, arrival_time;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time);
        printf("Enter priority (0-3) for process %d: ", i + 1);
        scanf("%d", &priority);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time);

        Process p = {i + 1, burst_time, burst_time, 0, 0, arrival_time, false}; // Initialize process

        if (priority == 0)
            q0[count_q0++] = p;
        else if (priority == 1)
            q1[count_q1++] = p;
        else if (priority == 2)
            q2[count_q2++] = p;
        else if (priority == 3)
            q3[count_q3++] = p;
        else {
            printf("Invalid priority! Please enter a priority between 0 and 3.\n");
            return -1;
        }
    }

    // Execute each queue in a round-robin fashion every TIME_QUANTUM seconds
    int current_time = 0;

    while (count_q0 > 0 || count_q1 > 0 || count_q2 > 0 || count_q3 > 0) {
        if (count_q0 > 0) {
            execute_queue(q0, &count_q0, &current_time, "Queue 0 (Round Robin)", round_robin);
        }
        if (count_q1 > 0) {
            execute_queue(q1, &count_q1, &current_time, "Queue 1 (Shortest Job First)", shortest_job_first);
        }
        if (count_q2 > 0) {
            execute_queue(q2, &count_q2, &current_time, "Queue 2 (Shortest Job First)", shortest_job_first);
        }
        if (count_q3 > 0) {
            execute_queue(q3, &count_q3, &current_time, "Queue 3 (First In First Out)", first_in_first_out);
        }
    }

    return 0;
}

// Function to execute a queue using a specific scheduling algorithm
void execute_queue(Process processes[], int *n, int *current_time, const char *queue_name,
                   void (*scheduling_algorithm)(Process[], int *, int *)) {
    printf("\nExecuting %s at time %d:\n", queue_name, *current_time);
    scheduling_algorithm(processes, n, current_time);
}

// Round Robin Scheduling for Queue 0
void round_robin(Process processes[], int *n, int *current_time) {
    for (int i = 0; i < *n; i++) {
        if (!processes[i].completed && processes[i].arrival_time <= *current_time) {
            if (processes[i].remaining_time > TIME_QUANTUM) {
                *current_time += TIME_QUANTUM;
                processes[i].remaining_time -= TIME_QUANTUM;
                printf("Process %d executed for %d seconds. Remaining time: %d\n", processes[i].pid,
                       TIME_QUANTUM, processes[i].remaining_time);
            } else {
                *current_time += processes[i].remaining_time;
                processes[i].waiting_time += (*current_time - processes[i].burst_time - processes[i].arrival_time);
                processes[i].turnaround_time = *current_time - processes[i].arrival_time;
                processes[i].remaining_time = 0;
                processes[i].completed = true;
                printf("Process %d completed. Turnaround time: %d seconds. Waiting time: %d seconds.\n",
                       processes[i].pid,
                       processes[i].turnaround_time,
                       processes[i].waiting_time);
            }
        }
    }

    // Remove completed processes from the queue
    int new_count = 0;
    for (int i = 0; i < *n; i++) {
        if (!processes[i].completed) {
            processes[new_count++] = processes[i];
        }
    }
    *n = new_count;
}

// Shortest Job First Scheduling for Queues 1 and 2
void shortest_job_first(Process processes[], int *n, int *current_time) {
    
   // Sort by remaining time first before execution.
   for (int i = 0; i < *n - 1; i++) {
       for (int j = i + 1; j < *n; j++) {
           if (processes[i].burst_time > processes[j].burst_time) {
               Process temp = processes[i];
               processes[i] = processes[j];
               processes[j] = temp;
           }
       }
   }

   // Execute each process in SJF order within TIME_QUANTUM limit
   for (int i = 0; i < *n; i++) {
       if (!processes[i].completed && processes[i].arrival_time <= *current_time) {
           if(processes[i].remaining_time > TIME_QUANTUM){
               // Execute only for TIME_QUANTUM seconds.
               *current_time += TIME_QUANTUM;
               processes[i].remaining_time -= TIME_QUANTUM;
               printf("Process %d executed for %d seconds. Remaining time: %d\n", 
                      processes[i].pid,
                      TIME_QUANTUM,
                      processes[i].remaining_time);
           }else{
               // Complete the process.
               *current_time += processes[i].remaining_time;
               processes[i].waiting_time += (*current_time - processes[i].burst_time - processes[i].arrival_time);
               processes[i].turnaround_time = *current_time - processes[i].arrival_time;
               processes[i].remaining_time = 0;
               processes[i].completed = true;

               printf("Process %d completed. Turnaround time: %d seconds. Waiting time: %d seconds.\n",
                      processes[i].pid,
                      processes[i].turnaround_time,
                      processes[i].waiting_time);
           }
       }
   }

   // Remove completed processes from the queue
   int new_count = 0;
   for (int i = 0; i < *n; i++) {
       if (!processes[i].completed) {
           processes[new_count++] = processes[i];
       }
   }
   *n = new_count;

}

// First-In-First-Out Scheduling for Queue 3
void first_in_first_out(Process processes[], int *n, int *current_time) {

   for(int i=0;i<*n;i++){
       if(!processes[i].completed && processes[i].arrival_time <= *current_time){
           // Execute the whole burst time.
           *current_time += processes[i].burst_time;
           // Calculate waiting and turnaround times.
           processes[i].waiting_time += (*current_time - processes[i].burst_time - processes[i].arrival_time);
           processes[i].turnaround_time = *current_time - processes[i].arrival_time;
           // Mark as completed.
           processes[i].completed=true;

           printf("Process %d completed. Turnaround time: %d seconds. Waiting time: %d seconds.\n",
                  processes[i].pid,
                  processes[i].turnaround_time,
                  processes[i].waiting_time);
       }
   }

   // Remove completed from queue.
   int new_count=0;
   for(int i=0;i<*n;i++){
       if(!processes[i].completed){
           processes[new_count++]=processes[i];
       }
   }
   *n=new_count;

}
