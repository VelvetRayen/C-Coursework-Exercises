#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, re, p = 0, reC;
    int T[5][10];
    int trouve = 0;

    printf("Filling the matrix\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++) {
            printf("Enter the value of T[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &T[i][j]);
        }
    }

    printf("Displaying the matrix\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++) {
            printf("%7d", T[i][j]);
        }
        printf("\n");
    }

    printf("\nCount the occurrences of an integer:\n");
    printf("Enter a value: ");
    scanf("%d", &re);

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++) {
            if (re == T[i][j]) {
                p++;
            }
        }
    }

    printf("The number %d appears %d time(s)\n", re, p);

    printf("Search for an integer:\n");
    printf("Enter a value: ");
    scanf("%d", &reC);

    trouve = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++) {
            if (T[i][j] == reC) {
                printf("Found at T[%d][%d]\n", i + 1, j + 1);
                trouve = 1;
                break;
            }
        }
        if (trouve) {
            break;
        }
    }

    if (!trouve) {
        printf("The value %d was not found in the matrix.\n", reC);
    }

    return 0;
}
