#include <stdio.h>
#include <stdlib.h>

int main () {
    int set = 1;
    int * bricks;
    int n, numBricks, moves, stackSize, stack;
    int i;
    scanf("%d", &n);

    while (n != 0) {

        bricks = (int *)malloc(sizeof(int) * n);
        numBricks = 0;

        for (i = 0; i < n; i++) {
            scanf("%d", &stack);
            numBricks += stack;
            bricks[i] = stack;
        }

        stackSize = numBricks / n;
        moves = 0;

        for (i = 0; i < n; i++) {
            if (bricks[i] > stackSize)
                moves += bricks[i] - stackSize;
        }

        printf("Set #%d\n", set);
        printf("The minimum number of moves is %d.\n\n", moves);

        free(bricks);

        scanf("%d", &n);
        
        set++;
    }

    return 0;
}