#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Tab[100][100];
    int r, p, i, j, choix;
    int np, nr, nq, s, sp = 0, min, trouve, d, f, aus, X, m;
    int T[100];
    int Tp[100];

    printf("Enter the number of shelves: ");
    scanf("%d", &r);
    printf("Enter the number of product types: ");
    scanf("%d", &p);

    printf("Filling the matrix\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < p; j++) {
            printf("Enter the quantity of product %d on shelf %d: ", j + 1, i + 1);
            scanf("%d", &Tab[i][j]);
        }
    }

    do {
        do {
            printf("\nSelection Menu\n");
            printf("1- Display the matrix\n");
            printf("2- Update the quantity of a given product on a given shelf\n");
            printf("3- Calculate and display the total quantity of each product\n");
            printf("4- Enter the unit price of each product\n");
            printf("5- Remove zero prices, sort, and run a binary search\n");
            printf("0- Quit\n");
            printf("Your choice: ");
            scanf("%d", &choix);
        } while (choix < 0 || choix > 5);

        switch (choix) {


            case 2:
                printf("Enter the product type (1....%d): ", p);
                scanf("%d", &np);
                printf("Enter the shelf number (1....%d): ", r);
                scanf("%d", &nr);
                printf("Enter the new quantity: ");
                scanf("%d", &nq);

                Tab[nr - 1][np - 1] = nq;
                printf("The quantity of product %d on shelf %d was changed to %d.", np, nr, nq);
                break;



            case 0:
                printf("Thank you, end of program!\n");
                break;

            case 1:
                printf("Displaying the matrix:\n");
                for (i = 0; i < r; i++) {
                    for (j = 0; j < p; j++) {
                        printf("%7d", Tab[i][j]);
                    }
                    printf("\n");
                }
                break;



            case 3:
                printf("Total quantity of each product:\n");
                for (i = 0; i < p; i++) {
                    s = 0;
                    for (j = 0; j < r; j++) {
                        s += Tab[j][i];
                    }
                    T[i] = s;
                }
                printf("Quantity array:\n");
                for (i = 0; i < p; i++) {
                    printf("The total quantity of product %d is %d\n", i + 1, T[i]);
                }
                break;

            case 4:
                int sp;
                sp = 0;
                for (i = 0; i < p; i++) {
                    printf("Enter the price of product %d: ", i + 1);
                    scanf("%d", &Tp[i]);
                }
                for (i = 0; i < p; i++) {
                    printf("| Price of product %d: %d |\n", i + 1, Tp[i]);
                    sp=T[i]*Tp[i];
                    printf("| Total price of product %d: %d |\n", i+1,sp);
                }
                break;

            case 5:
                for (i = 0; i < p; i++) {
                    if (Tp[i] == 0) {
                        for (j = i; j < p - 1; j++) {
                            Tp[j] = Tp[j + 1];
                        }
                        i--;
                        p--;
                    }
                }

                for (i = 0; i < p - 1; i++) {
                    min = i;
                    for (j = i + 1; j < p; j++) {
                        if (T[j] < T[min])
                            min = j;
                    }
                    aus = T[i];
                    T[i] = T[min];
                    T[min] = aus;
                }

                printf("Enter the value to find: ");
                scanf("%d", &X);

                d = 0;
                f = p - 1;
                trouve = -1;

                while ((trouve == -1) && (d <= f)) {
                    m = (d + f) / 2;
                    if (T[m] > X)
                        f = m - 1;
                    else if (T[m] < X)
                        d = m + 1;
                    else
                        trouve = 1;
                }

                if (trouve == 1) {
                    printf("Searching.........!\n");
                    printf("The value exists.\n");
                } else {
                    printf("Searching..........!\n");
                    printf("The value does not exist.\n");
                }
                break;


        }

    } while (choix != 0);

    return 0;
}
