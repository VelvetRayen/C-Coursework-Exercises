#include <stdio.h>

int main() {
    int n, m, j, i, val, max, min,k;
    int trouve = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int A[n][m];

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Given matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    printf("Searching for saddle points\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            val = A[i][j];
            max = 1;
            min = 1;

            for (k = 0; k < m; k++) {
                if (A[i][k] < val) {
                    min = 0;
                    break;
                }
            }

            for (k = 0; k < n; k++) {
                if (A[k][j] > val) {
                    max = 0;
                    break;
                }
            }

            if (max && min) {
                printf("Saddle point found: value %d at position (row %d, column %d)\n", val, i, j);
                trouve = 1;
            }
        }
    }

    if (!trouve) {
        printf("No saddle point was found in this matrix.\n");
    }

    return 0;
}
