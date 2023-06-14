// Task: output given array N-sized in reverse order
// Date: 14.06.23
#include <stdio.h>
#define N 5                                     // using directive define to create an array N-sized

int main(void) {
    int arr[N];                                 // creating base given N-sized array
    int rev_arr[N];                             // creating required array
    for(int i = 0; i < N; i++) {                // using loop for moving along arrays
        arr[i] = i + 1;                         // filling base given array
        rev_arr[N - (i + 1)] = arr[i];          // filling required array by taking value of base array by index (N - (i + 1))
    }                                           // and moving it to direct order in reversed array, what finally giving us a reversive order
    printf("base given array: {");              // outputting base array
    for(int i = 0; i < N; i++) {
        printf("%d", arr[i]);
        if(i != 4) {
            printf(", ");
        } else {
            printf("}.");
        }
    }
    printf("\nreversed array: {");              // and reversed
    for(int i = 0; i < N; i++) {
        printf("%d", rev_arr[i]);
        if(i != 4) {
            printf(", ");
        } else {
            printf("}.");
        }
    }
    printf("\n\n");
}