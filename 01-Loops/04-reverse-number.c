#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nbre ,org,nbreinv=0,rs;
    do{
    printf("Enter a strictly positive number:\n");
    scanf("%d",&nbre);

    }while(nbre<=0);
    org=nbre;
    while(org!=0){
        rs=org % 10;
        nbreinv=nbreinv*10+rs;
        org = org /10;

    }
    printf("Number entered: %d\n",nbre);
    printf("Reversed number: %d\n",nbreinv);
    return 0;
}
