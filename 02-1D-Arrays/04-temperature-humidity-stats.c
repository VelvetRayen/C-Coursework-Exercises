#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n , choix , i,num ;
    float tr[100];
    float th[100];

    do {
        printf("Enter the number of measurements (1-15): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 15);

    printf("Enter the temperatures:\n");
    for (i = 0; i < n; i++) {
        printf("tr[%d] = ", i + 1);
        scanf("%f", &tr[i]);
    }

    printf("Enter the humidity values:\n");
    for (i = 0; i < n; i++) {
        printf("th[%d] = ", i + 1);
        scanf("%f", &th[i]);
    }

    do {
        do {
            printf("\n Menu:\n");
            printf("1- Display the temperature measurements\n");
            printf("2- Display the humidity measurements\n");
            printf("3- Modify a reading given its number\n");
            printf("4- Calculate and display the maximum and minimum humidity and their reading numbers.\n");
            printf("5- Calculate and display the average humidity and temperature.\n");
            printf("6- Calculate the standard deviation of the humidity.\n");
            printf("0- Quit\n");

            printf("\n Enter your choice: ");
            scanf("%d", & choix);
        } while (choix < 0 || choix > 6);

        switch (choix) {
            case 0:
                printf("Thank you, end of program");
                break;
            case 1:
                printf("\nTemperature measurements\n");
                for (i = 0; i < n; i++) {
                    printf("tr[%d] = %f\n", i + 1, tr[i]);
                }
                break;

            case 2:
                printf("\nHumidity measurements\n");
                for (i = 0; i < n; i++) {
                    printf("th[%d] = %f\n", i + 1, th[i]);
                }
                break;
            case 3:
                printf("\n Enter the reading number: ");
                scanf("%d",&num);
                printf("\n Enter the new temperature value: ");
                scanf("%f",&tr[num-1]);
                printf("Temperature updated successfully");
                printf("\n Enter the new humidity value: ");
                scanf("%f",&th[num-1]);
                printf("Humidity updated successfully");
                printf("\nNew temperature measurements\n");
                for (i = 0; i < n; i++) {
                    printf("tr[%d] = %.2f\n", i + 1, tr[i]);
                }
                printf("\n New humidity measurements\n");
                for (i = 0; i < n; i++) {
                    printf("th[%d] = %.2f\n", i + 1, th[i]);
                }
                break;
            case 4:
                float maxh=th[0],maih=th[0];
                int prism = 1 , prisx=1;

                for (i=1 ; i<n ; i++){
                    if (th[i]>maxh){
                        maxh=th[i];
                        prisx = i+1;
                    }

                }
                for (i=1 ; i<n ; i++){
                    if (th[i]>maih){
                        maih=th[i];
                        prism = i+1;
                    }

                }
                printf("\n Maximum humidity: %.2f",maxh);
                printf("\nMinimum humidity: %.2f",maih);

                break;
            case 5:
                float sumt,sumh,moynt,moynh;
                for (i=0;i<n;i++){
                    sumt+=tr[i];
                    sumh+=th[i];
                }
                moynt=sumt/n;
                moynh=sumh/n;
                printf("\n Average humidity: %.2f",moynh);
                printf("\n Average temperature: %.2f",moynt);
                break;
            case 6:
                float sum = 0, l = 0, variance = 0, ec = 0;
                for (i = 0; i < n; i++) {
                        sum += th[i];
                }
                l = sum / n;
                float diff = th[i] - l;
                for (i = 0; i < n; i++) {
                        variance =variance + (diff * diff);
                }
                variance = variance /n;
                ec = sqrt(variance);
                printf("The standard deviation of the humidity is: %f \n", ec);
                break;

        }

    } while (choix != 0);

    return 0;
}
