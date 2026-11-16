#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int rech;
    int i;
    int t[100];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for ( i= 0; i < n; i++) {
        printf("t[%d] = ", i);
        scanf("%d", &t[i]);
    }


    printf("Enter the integer to search for: ");
    scanf("%d", &rech);

    int max = 0;
    int db = -1;
    int nuv = 0;
    int dbn = 0;

    for (i = 0; i < n; i++) {
        if (t[i] == rech) {
            if (nuv == 0) {
                dbn = i;
            }
            nuv++;
        } else {
            if (nuv > max) {
                max = nuv;
                db = dbn;
            }
            nuv = 0;
        }
    }

    if (nuv > max) {
        max = nuv;
        db = dbn;
    }

    if (max > 0) {
        printf("The longest consecutive run of %d has length %d and starts at index %d.\n",
               rech, max, db);
    }

    return 0;
}
