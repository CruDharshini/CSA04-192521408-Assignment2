#include <stdio.h>

int main(void) {
    int n, bt[20], rem[20], wt[20], tat[20];
    int tq, time = 0, done;
    float avgWT = 0, avgTAT = 0;

    printf("Number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Burst time P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }
    printf("Time quantum: ");
    scanf("%d", &tq);

    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = 0;
                int run = rem[i] < tq ? rem[i] : tq;
                time += run;
                rem[i] -= run;
                if (rem[i] == 0) {
                    tat[i] = time;
                    wt[i] = tat[i] - bt[i];
                }
            }
        }
    } while (!done);

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        avgWT += wt[i];
        avgTAT += tat[i];
    }
    printf("Average WT = %.2f\nAverage TAT = %.2f\n", avgWT/n, avgTAT/n);
    return 0;
}
