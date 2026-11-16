#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,o,p,i,j,S=0,S1=0;
    int M1[100][100];
    int M2[100][100];

    printf("Enter the value of m (rows) and n (columns) for M1: ");
    scanf("%d %d", &m, &n);
    for (i=0 ; i<m ; i++){
        for (j=0;j<n;j++){
            printf("Enter the value of T[%d][%d]: ",m+1,n+1);
            scanf("%d",&M1[m][n]);
        }
    }
    printf("Enter the value of m (rows) and n (columns) for M2: ");
    scanf("%d %d", &o, &p);
    for (i=0 ; i<o ; i++){
        for (j=0;j<p;j++){
            printf("Enter the value of T[%d][%d]: ",o+1,p+1);
            scanf("%d",&M2[o][p]);
        }
    }
    for (i=0;i<m;i++){
        for (j=0;j<n;j++){
            S1+=M1[i][j];
        }
    }

    for (i=0;i<o;i++){
        for (j=0;j<p;j++){
            S+=M1[o][p];
        }
    }

    printf("The sum of the two matrices is",S1+S);
    return 0;

}
