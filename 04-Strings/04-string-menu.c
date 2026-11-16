#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int choix,i,j,nb,ord=0;
    char phrase[200];
    char mot[200];
    char voy[200];
    char tabchan[7][10]={'sixieme','notre','pour','cest','annUé','prosit','cette'};
    int ordre[7];

    do {
        do {
            printf("\nSelection Menu\n");
            printf("1- Display the words of a sentence\n");
            printf("2- Display the vowels of a word and how many there are\n");
            printf("3- Build a sentence\n");
            printf("0- Quit\n");
            printf("Please enter your choice: ");
            scanf("%d", &choix);
        } while (choix < 0 || choix > 5);

        switch (choix) {

            case 0:
                printf("Thank you, end of program!\n");
                break;

            case 1:
                printf("Sentences must end with a period\n");
                printf("Enter a sentence: ");
                getchar();
                gets(phrase);
                for (i=0;phrase[i]!='\0';i++){

                    if (phrase[i]!=' '&& phrase[i]!='.'){
                        mot[j]=phrase[i];
                        j++;
                    }
                    else{
                        mot[j]='\0';
                        nb++;
                        printf("word %d: ",nb);
                        puts(mot);
                        j=0;
                    }
                }

                break;
            case 2:
                printf("Enter a word: ");
                getchar();
                gets(mot);
                for (i=0;i<strlen(mot);i++){
                    if (mot [i]=='a'|| mot [i]=='e' || mot [i]=='i'|| mot [i]=='o'|| mot [i]=='u'|| mot [i]=='y'){
                        nb++;
                        voy[j] = mot[i];
                        j++;
                    }
                voy[j]='\0';
                printf("The number of vowels is: %d\n", nb);
                printf("The vowels found are: %s\n", voy);
                }
            case 3:
                printf("Here is the list of words:\n");
                for (i=0;i<7;i++){
                    printf("%s",tabchan[i]);
                }
                for (i=0;i<7;i++){
                    printf("Enter the position of the word %s in the sentence: ",tabchan[i]);
                    scanf("%d",&ordre[i]);
                }






        }

    } while (choix != 0);
}
