#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int doc, interview;
} Applicant;

int compare(const void* a, const void* b) {
    return ((Applicant*)a)->doc - ((Applicant*)b)->doc;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        Applicant* arr = (Applicant*)malloc(sizeof(Applicant) * N);

        for (int i = 0; i < N; i++)
            scanf("%d %d", &arr[i].doc, &arr[i].interview);

        qsort(arr, N, sizeof(Applicant), compare);

        int count = 1;
        int best = arr[0].interview;

        for (int i = 1; i < N; i++) {
            if (arr[i].interview < best) {
                count++;
                best = arr[i].interview;
            }
        }

        printf("%d\n", count);
        free(arr);
    }

    return 0;
}
