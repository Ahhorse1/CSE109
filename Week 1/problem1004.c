#include <stdio.h>

int main () {
    float sum = 0;
    int i;

    for (i = 0; i < 12; i++ ) {
        float input;
        scanf("%f", &input);
        sum += input;
    }
    sum = sum / 12;
    printf("$%.2f", sum);
    return 0;
}