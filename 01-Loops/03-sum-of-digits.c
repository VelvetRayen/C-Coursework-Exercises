#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,s=0;
    printf("Enter a number N:\n");
    scanf("%d",&n);
    while (n!=0){
        s+=(n%10);
        n=n/10;
    }
    printf("The sum is %d",s);

    return 0;
}
