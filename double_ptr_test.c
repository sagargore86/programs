#include <stdio.h>
#include <stdlib.h>


void double_ptr_alloc(int **dp) {
    int i = 0;
    dp = (int **) malloc (sizeof(int *));

    printf("&dp= %p dp= %p\n", &dp, dp);
    //for (i = 0; i < 16; i++)
        *dp = (int *) malloc(sizeof(int)*16);

    *dp[0] = 26;
//    *dp[1] = 16;
//    *dp[15] = 6;
    printf("dp %p,, *dp %p **dp %d\n", dp, *dp, **(dp + 0));
    return;
}

int main() {
    int **dp;
    double_ptr_alloc(dp);
//    printf("**dp %d\n", **dp);
    return 1;
}