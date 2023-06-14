// Task: output squared matrix by given N
// Date: 14.06.23
#include <stdio.h>
#define N 3                                         // using directive define to create matrix NxN

int main(void) {
    int matrix[N][N];                               // creating matrix
    int var = 1;                                    // variable for filling a matrix
    for(int i = 0; i < N; i++) {                    // 1st loop moving control by columns 
        for(int o = 0; o < N; o++) {                // 2nd loop moving control by lines
            matrix[i][o] = var++;                   // filling matrix from 1 to 9 by incrementing variable for each loop
        }
    }
    for(int i = 0; i < N; i++) {                    // using same principles to output result
        for(int o = 0; o < N; o++) {
            printf("%d ", matrix[i][o]);            // outputting 1st line, then "\n" to transfer output to the next line
        }
        printf("\n");                               // we need this for correct matrix building in terminal
    }
    printf("\n\n");
}