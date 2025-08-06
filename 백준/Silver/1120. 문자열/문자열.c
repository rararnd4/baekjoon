#include <stdio.h>
#include <string.h>

int main() {
    char A[51], B[51];
    scanf("%s %s", A, B);

    int min = 51;
    int lenA = strlen(A), lenB = strlen(B);

    for (int i = 0; i <= lenB - lenA; i++) {
        int diff = 0;
        for (int j = 0; j < lenA; j++) {
            diff += (A[j] != B[i + j]);
        }
        if (diff < min) min = diff;
    }

    printf("%d\n", min);
    return 0;
}
