#include <stdio.h>

int main () {
    int sets;
    int no_ad, ad, cost;
    int i;

    scanf("%d", &sets);

    for (i = 0; i < sets; i++) {
        scanf ("%d %d %d", &no_ad, &ad, &cost);
        if (ad-no_ad < cost)
            printf("do not advertise\n");
        else if (ad-no_ad == cost)
            printf("does not matter\n");
        else
            printf("advertise\n");
    }

    return 0;
}