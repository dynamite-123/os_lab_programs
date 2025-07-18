#include <stdio.h>

typedef struct {
    int pid;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
    int done; // 0 if not done, 1 if done
} Process;

int main() {
    int n, i, completed = 0, curr_time = 0, min_index;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].arrival);
        printf("Enter burst time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].burst);
        p[i].done = 0;
    }

    float total_wait = 0, total_turnaround = 0;

    while(completed < n) {
        int idx = -1;
        int min_burst = 1e9;

        // Find the process with the shortest burst time among arrived and not done
        for(i = 0; i < n; i++) {
            if(!p[i].done && p[i].arrival <= curr_time) {
                if(p[i].burst < min_burst) {
                    min_burst = p[i].burst;
                    idx = i;
                }
                // For tie, choose process with earlier arrival
                else if(p[i].burst == min_burst && p[i].arrival < p[idx].arrival) {
                    idx = i;
                }
            }
        }

        // If no process has arrived, advance time
        if(idx == -1) {
            curr_time++;
            continue;
        }

        // Schedule the process
        p[idx].completion = curr_time + p[idx].burst;
        p[idx].turnaround = p[idx].completion - p[idx].arrival;
        p[idx].waiting = p[idx].turnaround - p[idx].burst;
        curr_time = p[idx].completion;
        p[idx].done = 1;
        completed++;

        total_wait += p[idx].waiting;
        total_turnaround += p[idx].turnaround;
    }

    // Output
    printf("\nPID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
            p[i].pid, p[i].arrival, p[i].burst, p[i].completion, p[i].waiting, p[i].turnaround);
    }
    printf("\nAverage Waiting Time: %.2f\n", total_wait/n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround/n);

    return 0;
}
