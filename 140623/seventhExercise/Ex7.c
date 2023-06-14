// Task: output every single byte of variable "a", which
// have integer data type.
// Date: 14.06.23

#include <stdio.h>

int main(void) {
    int a = 0xDDCCBBAA;
    unsigned char* ptr;                         // NOT signed or it'll be ffffffXX !
    ptr = (char*)&a;                            // need to be casted to type char* !
    for(int i = 0; i < 4; i++) {
        printf("%d byte of var \"a\" is %x\n", i+1, *ptr);
        ptr++;
    }
    printf("\n\n");
}