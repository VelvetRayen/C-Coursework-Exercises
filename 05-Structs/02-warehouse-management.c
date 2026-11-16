#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char ville[20];
    char type[30];
    int nbRayons;
    int produits[100];
    char responsable[30];
} Depot;

int main()
{
    Depot Tdep[100];
    int nb = 0;
    int choix, i, j, id, q;
    int trouve, total;
    char type[30], ville[30], resp[30];
    int seuil;

    do{
        do
        {
            printf("\n 1. Add a warehouse");
            printf("\n 2. Add products (first empty shelf)");
            printf("\n 3. List warehouses by type");
            printf("\n 4. Display the manager and city of the most heavily stocked warehouse");
            printf("\n 5. Change a warehouse's manager");
            printf("\n 6. Count the warehouses in a city");
            printf("\n 7. Display the warehouses under a maximum threshold");
            printf("\n 8. Delete the first empty warehouse");
            printf("\n 0. Quit");
            printf("\n Your choice: ");
            scanf("%d", &choix);
        } while((choix < 0) || (choix > 8));

        switch(choix)
        {
            case 1:
                if(nb < 100)
                {
                    printf("ID: ");
                    scanf("%d", &Tdep[nb].id);

                    printf("City (tunis, sousse, bizerte): ");
                    do{
                        scanf("%s", Tdep[nb].ville);
                    } while(strcmp(Tdep[nb].ville, "tunis") != 0 &&
                            strcmp(Tdep[nb].ville, "sousse") != 0 &&
                            strcmp(Tdep[nb].ville, "bizerte") != 0);

                    printf("Type (vestimentaire = clothing, alimentaire = food, piecederechange = spare parts): ");
                    do{
                        scanf("%s", Tdep[nb].type);
                    } while(strcmp(Tdep[nb].type, "vestimentaire") != 0 &&
                            strcmp(Tdep[nb].type, "alimentaire") != 0 &&
                            strcmp(Tdep[nb].type, "piecederechange") != 0);

                    printf("Number of shelves: ");
                    scanf("%d", &Tdep[nb].nbRayons);

                    for(i = 0; i < Tdep[nb].nbRayons; i++)
                    {
                        Tdep[nb].produits[i] = 0;
                    }

                    printf("Manager: ");
                    scanf("%s", Tdep[nb].responsable);

                    nb++;
                    printf("Warehouse added successfully!\n");
                }
                else
                {
                    printf("Cannot add (array is full).\n");
                }
                break;

            case 2:
                printf("Enter the warehouse ID: ");
                scanf("%d", &id);

                trouve = 0;
                for(i = 0; i < nb; i++)
                {
                    if(Tdep[i].id == id)
                    {
                        trouve = 1;
                        j = 0;
                        while(j < Tdep[i].nbRayons && Tdep[i].produits[j] != 0)
                        {
                            j++;
                        }

                        if(j < Tdep[i].nbRayons)
                        {
                            printf("Number of products to add: ");
                            scanf("%d", &q);

                            if(q > 0 && q <= 200)
                            {
                                Tdep[i].produits[j] = q;
                                printf("Products added to shelf %d successfully!\n", j + 1);
                            }
                            else
                            {
                                printf("Invalid quantity (must be between 1 and 200)!\n");
                            }
                        }
                        else
                        {
                            printf("No empty shelf in this warehouse!\n");
                        }
                    }
                }

                if(trouve == 0)
                {
                    printf("Warehouse not found!\n");
                }
                break;

            case 3:
                printf("Enter the type: ");
                scanf("%s", type);

                trouve = 0;
                for(i = 0; i < nb; i++)
                {
                    if(strcmp(Tdep[i].type, type) == 0)
                    {
                        trouve = 1;
                        printf("\n--- Warehouse ID: %d ---", Tdep[i].id);
                        printf("\nCity: %s", Tdep[i].ville);
                        printf("\nManager: %s\n", Tdep[i].responsable);
                    }
                }

                if(trouve == 0)
                {
                    printf("No warehouse found for this type!\n");
                }
                break;

            case 4:
                if(nb == 0)
                {
                    printf("No warehouse registered!\n");
                    break;
                }
                {
                    int maxTotal = -1;
                    int idxMax = -1;

                    for(i = 0; i < nb; i++)
                    {
                        total = 0;
                        for(j = 0; j < Tdep[i].nbRayons; j++)
                        {
                            total += Tdep[i].produits[j];
                        }
                        if(total > maxTotal)
                        {
                            maxTotal = total;
                            idxMax = i;
                        }
                    }

                    if(idxMax != -1)
                    {
                        printf("\nWarehouse holding the most products (%d products):", maxTotal);
                        printf("\nCity: %s", Tdep[i = idxMax].ville);
                        printf("\nManager: %s\n", Tdep[idxMax].responsable);
                    }
                }
                break;

            case 5:
                printf("Enter the warehouse ID: ");
                scanf("%d", &id);

                trouve = 0;
                for(i = 0; i < nb; i++)
                {
                    if(Tdep[i].id == id)
                    {
                        trouve = 1;
                        printf("Current manager: %s\n", Tdep[i].responsable);
                        printf("New manager: ");
                        scanf("%s", Tdep[i].responsable);
                        printf("Manager changed successfully!\n");
                    }
                }
                if(trouve == 0)
                {
                    printf("Warehouse not found!\n");
                }
                break;

            case 6:
                printf("Enter the city: ");
                scanf("%s", ville);

                int cptVille = 0;
                for(i = 0; i < nb; i++)
                {
                    if(strcmp(Tdep[i].ville, ville) == 0)
                    {
                        cptVille++;
                    }
                }
                printf("Number of warehouses in %s: %d\n", ville, cptVille);
                break;

            case 7:
                printf("Enter the maximum threshold per shelf: ");
                scanf("%d", &seuil);

                trouve = 0;
                for(i = 0; i < nb; i++)
                {
                    int valide = 1;
                    for(j = 0; j < Tdep[i].nbRayons; j++)
                    {
                        if(Tdep[i].produits[j] >= seuil)
                        {
                            valide = 0;
                            break;
                        }
                    }
                    if(valide && Tdep[i].nbRayons > 0)
                    {
                        trouve = 1;
                        printf("Warehouse ID: %d (City: %s)\n", Tdep[i].id, Tdep[i].ville);
                    }
                }
                if(trouve == 0)
                {
                    printf("No warehouse meets this threshold.\n");
                }
                break;

            case 8:
                {
                    int idxVide = -1;
                    for(i = 0; i < nb; i++)
                    {
                        total = 0;
                        for(j = 0; j < Tdep[i].nbRayons; j++)
                        {
                            total += Tdep[i].produits[j];
                        }
                        if(total == 0)
                        {
                            idxVide = i;
                            break;
                        }
                    }

                    if(idxVide == -1)
                    {
                        printf("No empty warehouse found.\n");
                    }
                    else
                    {
                        for(i = idxVide; i < nb - 1; i++)
                        {
                            Tdep[i] = Tdep[i + 1];
                        }
                        nb--;
                        printf("The first empty warehouse was deleted successfully.\n");
                    }
                }
                break;

            case 0:
                printf("End of the program.");
                break;
        }

    } while(choix != 0);

    return 0;
}
