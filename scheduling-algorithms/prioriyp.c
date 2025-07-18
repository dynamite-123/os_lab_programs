#include <stdio.h>

typedef struct {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int priority;
    int completion;
    int waiting;
    int turnaround;
} Process;

int main() {
    int n, completed = 0, curr_time = 0, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].arrival);
        printf("Enter burst time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].burst);
        printf("Enter priority for Process %d (lower number = higher priority): ", p[i].pid);
        scanf("%d", &p[i].priority);
        p[i].remaining = p[i].burst;
    }

    float total_wait = 0, total_turnaround = 0;

    while(completed < n) {
        int idx = -1;
        int highest_priority = 1e9;

        // Select the highest priority process among arrived and not finished
        for(i = 0; i < n; i++) {
            if(p[i].arrival <= curr_time && p[i].remaining > 0) {
                if(p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
                // Resolve tie by arrival time
                else if(p[i].priority == highest_priority && p[i].arrival < p[idx].arrival) {
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            curr_time++; // If no process is ready, advance time
            continue;
        }

        // Run for one time unit
        p[idx].remaining--;
        curr_time++;

        // If process finishes
        if(p[idx].remaining == 0) {
            completed++;
            p[idx].completion = curr_time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            total_wait += p[idx].waiting;
            total_turnaround += p[idx].turnaround;
        }
    }

    // Output
    printf("\nPID\tArrival\tBurst\tPriority\tCompletion\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n",
            p[i].pid, p[i].arrival, p[i].burst, p[i].priority, p[i].completion, p[i].waiting, p[i].turnaround);
    }
    printf("\nAverage Waiting Time: %.2f\n", total_wait/n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround/n);

    return 0;
}
