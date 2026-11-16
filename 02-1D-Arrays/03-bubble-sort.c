#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, permut, aux;
    int T[100];

    printf("Choose the value of N, the array size:\n");
    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("Filling the array\n");
    for (i = 0; i < n; i++) {
        printf("Enter the value of T[%d]: ", i + 1);
        scanf("%d", &T[i]);
    }

    do
    {
        permut = 0;
        for (i = 0; i < n - 1; i++) {
            if (T[i] > T[i + 1])
            {
                aux = T[i];
                T[i] = T[i + 1];
                T[i + 1] = aux;
                permut = 1;
            }
        }
    } while (permut == 1);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("| T[%d] = %d | ", i + 1, T[i]);
    }

    return 0;
}
