// Task: change 3rd byte (0xCC) in variable "a" to 0xEE.
// Date: 14.06.23

#include <stdio.h>

int main(void) {
    int a = 0xDDCCBBAA;
    unsigned char* ptr;                         // NOT signed or it'll be ffffffXX !
    ptr = (char*)&a;                            // need to be casted to type char* !
    printf("var \"a\" before changes: %x\n", a);
    *(ptr + 2) = 0xEE;                          // "shifing" by 16 bits to the rigth side and changing it's value
    printf("var \"a\" after changes: %x\n", a);
    printf("\n\n");
}