#include <stdio.h>

int multi() {
    int res, n1, n2;
    printf("Enter 2 nums: ");
    scanf("%d %d", &n1, &n2);
    res = n1 * n2;
    return res;
}