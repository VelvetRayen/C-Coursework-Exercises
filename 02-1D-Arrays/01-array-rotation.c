#include <stdio.h>

int main() {
    int t[100];
    int n,R;
    int d;
    int i, j ;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for ( i= 0; i < n; i++) {
        printf("t[%d] = ", i);
        scanf("%d", &t[i]);
    }

    printf("Enter the number of rotations: ");
    scanf("%d", &R);

    for (j = 0; j < R; j++) {
        d = t[n - 1];

        for (i = n - 1; i > 0; i--) {
            t[i] = t[i - 1];
        }

        t[0] = d;
    }

    printf("Final array:\n");
    for (i = 0; i < n; i++) {
        printf("[%d] ", t[i]);
    }

    return 0;
}
