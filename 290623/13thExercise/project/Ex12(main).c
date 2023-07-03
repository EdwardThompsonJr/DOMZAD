// Task: 
#include <stdio.h>
#include "../library/mylib.h"

int main(void) {
    int choose = 0;
    printf("C A L C U L A T O R !!!\n");
    printf("1. Summ%17c2. Multiply\n" \
    "3. Substraction%9c4. Division\n", " ", " ");
    while(scanf("%d", &choose) && choose != 5) {
        int res;
        switch (choose)
        {
        case 1:
            res = summ();
            printf("Result: %d\n", res);
            break;
        case 2:
            res = multi();
            printf("Result: %d\n", res);
            break;
        case 3:
            res = subs();
            printf("Result: %d\n", res);
            break;
        case 4:
            res = div();
            printf("Result: %d\n", res);
            break;    
        default:
            break;
        }
        printf("1. Summ%17c2. Multiply\n" \
        "3. Substraction%9c4. Division\n", " ", " ");
    }
    printf("\n\n");
}