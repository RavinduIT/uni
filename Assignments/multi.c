#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100
#define TIME_QUANTUM 20

// Define the Process structure
struct Process {
    int pid;                // Process ID
    int burst_time;         // Burst time of the process
    int remaining_time;     // Remaining time for execution
    int arrival_time;       // Arrival time of the process
    int waiting_time;       // Waiting time of the process
    int turnaround_time;    // Turnaround time of the process
    int queue;              // Queue priority (0-3)
    bool completed;         // Completion status
};

// Function to sort processes based on arrival time and burst time (for SJF)
void sort_by_burst_time(struct Process q[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (q[j].burst_time > q[j + 1].burst_time) {
                struct Process temp = q[j];
                q[j] = q[j + 1];
                q[j + 1] = temp;
            }
        }
    }
}

// Function to execute Round Robin scheduling for Q0
void round_robin(struct Process q[], int n, int *global_time) {
    bool done;
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (q[i].remaining_time > 0) {
                done = 0;
                int execution_time = (q[i].remaining_time > TIME_QUANTUM) ? TIME_QUANTUM : q[i].remaining_time;
                *global_time += execution_time;
                q[i].remaining_time -= execution_time;
                
                if (q[i].remaining_time == 0) {
                    q[i].turnaround_time = *global_time - q[i].arrival_time;
                    q[i].waiting_time = q[i].turnaround_time - q[i].burst_time;
                }
            }
        }
    } while (!done);
}

// Function to execute Shortest Job First scheduling
void shortest_job_first(struct Process q[], int n, int *global_time) {
    sort_by_burst_time(q, n);
    for (int i = 0; i < n; i++) {
        *global_time += q[i].burst_time;
        q[i].turnaround_time = *global_time - q[i].arrival_time;
        q[i].waiting_time = q[i].turnaround_time - q[i].burst_time;
    }
}

// Function to execute First-In-First-Out scheduling
void first_in_first_out(struct Process q[], int n, int *global_time) {
    for (int i = 0; i < n; i++) {
        *global_time += q[i].burst_time;
        q[i].turnaround_time = *global_time - q[i].arrival_time;
        q[i].waiting_time = q[i].turnaround_time - q[i].burst_time;
    }
}

// Main function to simulate multilevel queue scheduling
int main() {
    struct Process processes[MAX_PROCESSES];
    int num_processes;

    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    // Input process details
    for (int i = 0; i < num_processes; i++) {
        printf("Enter Process ID: ");
        scanf("%d", &processes[i].pid);
        
        do {
            printf("Enter Burst Time: ");
            scanf("%d", &processes[i].burst_time);
        } while (processes[i].burst_time <= 0);

        do {
            printf("Enter Queue Priority (0-3): ");
            scanf("%d", &processes[i].queue);
        } while (processes[i].queue < 0 || processes[i].queue > 3);

        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = processes[i].turnaround_time = 0;
        processes[i].completed = 0;
        processes[i].arrival_time = i * 5; // Assuming processes arrive at different times
    }

    // Separate processes into queues based on priority
    struct Process queues[4][MAX_PROCESSES];
    int count[4] = {0};
    int global_time = 0;

    for (int i = 0; i < num_processes; i++) {
        queues[processes[i].queue][count[processes[i].queue]++] = processes[i];
    }

    // Scheduling for each queue
    printf("\nScheduling Queue Q0 (Round Robin):\n");
    round_robin(queues[0], count[0], &global_time);
    printf("PID\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < count[0]; i++) {
        printf("%d\t%d\t\t%d\n", queues[0][i].pid, queues[0][i].waiting_time, queues[0][i].turnaround_time);
    }

    printf("\nScheduling Queue Q1 (Shortest Job First):\n");
    shortest_job_first(queues[1], count[1], &global_time);
    printf("PID\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < count[1]; i++) {
        printf("%d\t%d\t\t%d\n", queues[1][i].pid, queues[1][i].waiting_time, queues[1][i].turnaround_time);
    }

    printf("\nScheduling Queue Q2 (Shortest Job First):\n");
    shortest_job_first(queues[2], count[2], &global_time);
    printf("PID\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < count[2]; i++) {
        printf("%d\t%d\t\t%d\n", queues[2][i].pid, queues[2][i].waiting_time, queues[2][i].turnaround_time);
    }

    printf("\nScheduling Queue Q3 (First-In-First-Out):\n");
    first_in_first_out(queues[3], count[3], &global_time);
    printf("PID\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < count[3]; i++) {
        printf("%d\t%d\t\t%d\n", queues[3][i].pid, queues[3][i].waiting_time, queues[3][i].turnaround_time);
    }

    return 0;
}