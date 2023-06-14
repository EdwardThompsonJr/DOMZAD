// Task: Fill upper triangle by 1 and lower triangle by 0
// 0 0 1
// 0 1 1
// 1 1 1
// Date: 14.06.23
#include <stdio.h>
#define N 3

int main(void) {
    int triangle1[N][N] = {0};                                  // creating 2 result arrays for 2 ways to solve this problem
    int triangle2[N][N] = {0};                                  // filling both of them by zero-values
    for(int i = 0; i < N; i++) {                                // filling arrays according to the task
        for(int o = N-1; o >= N-(i+1); o--) {
            triangle1[i][o] = 1;
            triangle2[i][o] = 1;
        }
    }
    for(int i = 0; i < N; i++) {                                // outputting to check the result
        for(int o = 0; o < N; o++) {                            // P.S. result is OK
            printf("%d ", triangle1[i][o]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < N; i++) {
        for(int o = 0; o < N; o++) {
            printf("%d ", triangle2[i][o]);
        }
        printf("\n");
    }
    printf("\n");
    // 1st way to solve a problem: 
    for(int i = 0; i < N; i++) {                                // simply changing 0's to 1's and 1's to 0's
        for(int o = 0; o < N; o++) {                            // no need to complicate a solution as I'm sayin'
            triangle1[i][o] = triangle1[i][o] == 0 ? 1 : 0;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int o = 0; o < N; o++) {
            printf("%d ", triangle1[i][o]);
        }
        printf("\n");
    }
    printf("\n");
    // 2nd way:
    for(int i = 0; i < N; i++) {                                // but if you need "clever" one, then do this
        for(int o = 0; o < N-(i+1); o++) {                      // most important is to build right condition in loops
            triangle2[i][o] = 1;                                // I don't wanna explain this condition
        }                                                       // maybe I'll do it later...
        for(int o = N-1; o >= N-(i+1); o--) {
            triangle2[i][o] = 0;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int o = 0; o < N; o++) {
            printf("%d ", triangle2[i][o]);
        }
        printf("\n");
    }
    printf("\n\n");
}