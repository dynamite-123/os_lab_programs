#include <stdio.h>

typedef struct {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
    int started; // 0 = not started, 1 = started
} Process;

int main() {
    int n, completed = 0, curr_time = 0, i, min_idx;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].arrival);
        printf("Enter burst time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].burst);
        p[i].remaining = p[i].burst; // Initialize remaining time
        p[i].started = 0;
    }

    float total_wait = 0, total_turnaround = 0;

    int last_completed = -1;
    while(completed < n) {
        int idx = -1;
        int min_remaining = 1e9;

        // Find the process with the shortest remaining time among arrived and not finished
        for(i = 0; i < n; i++) {
            if(p[i].arrival <= curr_time && p[i].remaining > 0) {
                if(p[i].remaining < min_remaining) {
                    min_remaining = p[i].remaining;
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            curr_time++; // If no process is ready, advance time
            continue;
        }

        // Run process for one unit of time
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
    printf("\nPID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
            p[i].pid, p[i].arrival, p[i].burst, p[i].completion, p[i].waiting, p[i].turnaround);
    }
    printf("\nAverage Waiting Time: %.2f\n", total_wait/n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround/n);

    return 0;
}
