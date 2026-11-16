#include <stdio.h>
#include <stdlib.h>

int main()
{
    char prenom[50];
    int i = 0;

    printf("Enter your first name: ");
    gets(prenom);

    while (prenom[i] != '\0')
    {
        i++;
    }

    printf("The length of the string is: %d", i);

    return 0;
}
