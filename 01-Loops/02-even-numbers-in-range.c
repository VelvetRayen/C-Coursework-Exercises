#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N1, N2, i;
    printf("Enter integer n1:\n");
    scanf("%d", &N1);
    printf("Enter integer n2:\n");
    scanf("%d", &N2);

    for (i = N1; i <= N2; i++) {
        if (i % 2 == 0) {
            printf("%d is even\n", i);
        }
    }
    return 0;
}
