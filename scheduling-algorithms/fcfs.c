#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

// Sort processes by arrival time (simple bubble sort)
void sortByArrival(struct Process p[], int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-1-i; j++) {
            if(p[j].arrival > p[j+1].arrival) {
                swap(&p[j], &p[j+1]);
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].arrival);
        printf("Enter burst time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].burst);
    }

    // Sort by arrival time
    sortByArrival(p, n);

    // Calculate completion, waiting and turnaround times
    int curr_time = 0;
    for(i = 0; i < n; i++) {
        if(curr_time < p[i].arrival)
            curr_time = p[i].arrival;
        p[i].completion = curr_time + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
        curr_time = p[i].completion;
    }

    // Output
    float total_wait = 0, total_turnaround = 0;
    printf("\nPID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
            p[i].pid, p[i].arrival, p[i].burst, p[i].completion, p[i].waiting, p[i].turnaround);
        total_wait += p[i].waiting;
        total_turnaround += p[i].turnaround;
    }
    printf("\nAverage Waiting Time: %.2f\n", total_wait/n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround/n);

    return 0;
}
