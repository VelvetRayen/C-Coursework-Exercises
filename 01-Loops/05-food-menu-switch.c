#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choix;

    printf("1- Pizza \n2- Escalope Dish \n3- Chicken Dish \n4- Mixed Grill Dish\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choix);
    } while (choix < 1 || choix > 4);

    switch (choix) {
        case 1:
            printf("You chose: Pizza\n");
            break;
        case 2:
            printf("You chose: Escalope Dish\n");
            break;
        case 3:
            printf("You chose: Chicken Dish\n");
            break;
        case 4:
            printf("You chose: Mixed Grill Dish\n");
            break;
    }

    return 0;
}
