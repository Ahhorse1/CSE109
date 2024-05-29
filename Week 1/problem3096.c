#include <stdio.h>
#include <string.h>

int main () {
    char string[80];
    char * end = "*\n";
    int pairs[26][26] = {0};
    int i = 0;
    int isSuprising = 1;

    fgets(string, 80, stdin);

    while(strcmp(string, end) != 0){

        printf("%s", string);
        printf("Result: %d", strcmp(string, end));
        
        fgets(string, 80, stdin);
    }

    return 0;
}