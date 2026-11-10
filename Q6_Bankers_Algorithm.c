#include <stdio.h>

int main(void) {
    int n = 5, m = 3;

    int alloc[5][3] = {
        {0,1,0}, {2,0,0}, {3,0,2},
        {2,1,1}, {0,0,2}
    };

    int max[5][3] = {
        {7,5,3}, {3,2,2}, {9,0,2},
        {2,2,2}, {4,3,3}
    };

    int avail[3] = {3,3,2};
    int need[5][3], finish[5] = {0};
    int work[3], safe[5], count = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for (int j = 0; j < m; j++)
        work[j] = avail[j];

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int ok = 1;

                for (int j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        ok = 0;

                if (ok) {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
            break;
    }

    if (count == n) {
        printf("Safe State\nSequence: ");
        for (int i = 0; i < n; i++)
            printf("P%d ", safe[i]);
        printf("\n");
    } else {
        printf("Unsafe State\n");
    }

    return 0;
}
