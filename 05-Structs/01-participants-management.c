#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct participant {
    int dejeuner, diner, hotel, cin;
    char nom[50];
    char prenom[50];
} participant;

int main() {
    participant p[100];
    int choix, n = 0, n4 = 0, cinrec, existe, total, i, j, pos, rech = 0, choix_aff;

    do {
        do {
            printf("\nSelection Menu\n");
            printf("1- Add a participant.\n");
            printf("2- Calculate a participant's bill.\n");
            printf("3- Display the participants' information.\n");
            printf("4- Delete a participant by their ID.\n");
            printf("0- Quit\n");
            printf("Please enter your choice: ");
            scanf("%d", &choix);
        } while (choix < 0 || choix > 4);

        switch (choix) {
            case 0:
                printf("Thank you, end of program\n");
                break;

            case 1:
                printf("Enter the participant's CIN: ");
                scanf("%d", &p[n].cin);
                printf("Enter the participant's last name: ");
                scanf("%s", p[n].nom);
                printf("Enter the participant's first name: ");
                scanf("%s", p[n].prenom);
                printf("Lunch (15 DT) [1: Yes / 0: No]: ");
                scanf("%d", &p[n].dejeuner);
                printf("Dinner (35 DT) [1: Yes / 0: No]: ");
                scanf("%d", &p[n].diner);
                printf("Hotel (0: None, 4: 4 stars, 5: 5 stars): ");
                scanf("%d", &p[n].hotel);
                n++;
                printf("Participant added successfully\n");
                break;

            case 2:
                printf("Calculating the participant's bill\n");
                printf("Enter the participant's CIN: ");
                scanf("%d", &cinrec);
                existe = 0;

                for (i = 0; i < n; i++) {
                    if (p[i].cin == cinrec) {
                        existe = 1;
                        total = 0;
                        if (p[i].dejeuner == 1) {
                            total += 15;
                        }
                        if (p[i].diner == 1) {
                            total += 35;
                        }
                        if (p[i].hotel == 4) {
                            total += 75;
                        }
                        if (p[i].hotel == 5) {
                            total += 100;
                        }

                        printf("The amount for %s %s is %d dinars\n", p[i].nom, p[i].prenom, total);
                    }
                }

                break;

            case 3:
                do {
                    do {
                        printf("\nDisplay the participants' information\n");
                        printf("1- all participants, with no search criteria.\n");
                        printf("2- participants who booked a 4-star hotel.\n");
                        printf("3- participants who booked a 5-star hotel.\n");
                        printf("0- Quit\n");
                        printf("Please enter your choice: ");
                        scanf("%d", &choix_aff);
                    } while (choix_aff < 0 || choix_aff > 3);

                    switch (choix_aff) {
                        case 1:
                            for (i = 0; i < n; i++) {
                                printf("CIN: %d | Last name: %s | First name: %s | Hotel: %d | Lunch: %d | Dinner: %d\n",
                                       p[i].cin, p[i].nom, p[i].prenom, p[i].hotel, p[i].dejeuner, p[i].diner);
                            }
                            break;

                        case 2:
                            printf("Participants who booked a 4-star hotel:\n");
                            for (i = 0; i < n; i++) {
                                if (p[i].hotel == 4) {
                                    printf("CIN: %d , Last name: %s , First name: %s\n", p[i].cin, p[i].nom, p[i].prenom);
                                }
                            }
                            break;

                        case 3:
                            printf("Participants who booked a 5-star hotel:\n");
                            for (i = 0; i < n; i++) {
                                if (p[i].hotel == 5) {
                                    printf("CIN: %d , Last name: %s , First name: %s\n", p[i].cin, p[i].nom, p[i].prenom);
                                }
                            }
                            break;

                        case 0:
                            printf("Back to the main menu\n");
                            break;
                    }
                } while (choix_aff != 0);
                break;

            case 4:
                if (n == 0) {
                    printf("No participant to delete\n");
                    break;
                }
                for (i = 0; i < n; i++) {
                    printf("| CIN: %d\n", p[i].cin);
                }

                printf("Enter the CIN of the participant to delete: ");
                scanf("%d", &cinrec);
                pos = -1;

                for (i = 0; i < n; i++) {
                    if (p[i].cin == cinrec) {
                        pos = i;
                    }
                }

                if (pos != -1) {
                    for (j = pos; j < n - 1; j++) {
                        p[j] = p[j + 1];
                    }
                    n--;
                    printf("Participant deleted successfully\n");
                }
                break;
        }

    } while (choix != 0);

    return 0;
}
