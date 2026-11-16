#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, S;
    printf("Enter an integer:\n");
    scanf("%d", &N);
    for (i = 0; i <= 9; i++) {
        S = N * i;
        printf("%d*%d=%d\n", N, i, S);
    }
    return 0;
}
