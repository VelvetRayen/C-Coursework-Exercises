#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char CH1[100];
    char CH2[100];
    char CH3[200];
    int Lg1, Lg2;

    printf("Enter CH1: ");
    gets(CH1);

    printf("Enter CH2: ");
    gets(CH2);

    Lg1 = strlen(CH1);
    Lg2 = strlen(CH2);

    strncpy(CH3, CH1, Lg1 / 2);
    CH3[Lg1 / 2] = '\0';

    strncat(CH3, CH2, Lg2 / 2);

    printf("The result is: %s", CH3);

    return 0;
}
