#include <stdio.h>

int main() {
    int n, quantum = 4;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];
    int wt[n], tat[n], t = 0;

    printf("Enter process IDs and burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &processes[i], &burst_time[i]);
        wt[i] = tat[i] = 0;
    }

    do {
        for (int i = 0; i < n; i++) {
            if (burst_time[i] > 0) {
                if (burst_time[i] > quantum) {
                    t += quantum;
                    burst_time[i] -= quantum;
                } else {
                    t += burst_time[i];
                    wt[i] = t - burst_time[i];
                    burst_time[i] = 0;
                }
                tat[i] = t;
            }
        }
    } while (burst_time[0] + burst_time[1] + burst_time[2] > 0);

    printf("Process\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\n", processes[i], wt[i], tat[i]);

    return 0;
}
