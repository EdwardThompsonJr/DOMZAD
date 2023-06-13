// Task: output every single byte of variable "a", which
// have integer data type.
#include <stdio.h>

int main(void) {
    // 1st way to solve problem:
    int a = 0xDDCCBBAA;                                             // declaring and initializing variable "a"
    unsigned char c = (a & 0xFF);                                   // finding the least significant byte from the variable a
    printf("1st byte of a = %x\n", c);                              // outputting found value
    c = ((a >> 8) & 0xFF);                                          // shifting the value of var "a" by 8 bits and finding 2nd byte
    printf("2nd byte of a = %x\n", c);                              // outputting found value
    c = ((a >> 16) & 0xFF);                                         // repeating shiftings, outputting values...
    printf("3rd byte of a = %x\n", c);
    c = ((a >> 24) & 0xFF);
    printf("4th byte of a = %x\n\n", c);
    // 2nd way:
    for(int i = 0; i < 4; i++) {                                    // creating a loop, where the number of iterations is the same as the number of bytes in int "a"
        unsigned char c = ((a >> (i*8)) & 0xFF);                    // shifting "a" by (i*8) bits and finding the least significant byte
        char ending[2];                                             // trying to choose an ending...
        switch (i)
        {
        case 0:
            ending[0] = 's';
            ending[1] = 't';
            break;
        case 1:
            ending[0] = 'n';
            ending[1] = 'd';
            break;
        case 2:
            ending[0] = 'r';
            ending[1] = 'd';
            break;
        default:
            ending[0] = 't';
            ending[1] = 'h';
            break;
        }
        printf("%d%c%c byte of a = %x\n", i+1, ending[0], ending[1], c);
    }
    printf("\n\n");
}