// Task: change 3rd byte (0xCC) in variable "a" to 0xEE.
#include <stdio.h>

int main(void) {
    // 1st way to solve a problem:
    int a = 0xDDCCBBAA;
    unsigned char chars[4];                                     // creating an array to save our bytes-values
    chars[0] = (a & 0xFF);                                      // saving value of 1st byte and so on...
    printf("1st byte of a = %x\n", chars[0]);
    chars[1] = ((a >> 8) & 0xFF);
    printf("2nd byte of a = %x\n", chars[1]);
    chars[2] = ((a >> 16) & 0xFF);
    printf("3rd byte of a = %x\n", chars[2]);
    chars[2] = 0xEE;                                            // changing value of 3rd byte to 0xEE
    chars[3] = ((a >> 24) & 0xFF);
    printf("4th byte of a = %x\n", chars[3]);
    printf("value of \"a\" before changes: %x\n", a);
    a = ((a >> 24) & (chars[3] & 0xFF));                        // shifting by 3 bytes to the right side and changing the least significant byte
    a = ((a << 8) | (chars[2] & 0xFF));                         // changing 2nd byte and so on...
    a = ((a << 8) | (chars[1] & 0xFF));
    a = ((a << 8) | (chars[0] & 0xFF));
    printf("value of \"a\" after changes: %x\n\n", a);

    // 2nd way:
    a = 0xDDCCBBAA;
    for(int i = 0; i < 4; i++) {
        chars[i] = ((a >> (i*8)) & 0xFF);
        printf("%d byte of a = %x\n", i+1, chars[i]);
        if(i == 2) {                                             // changing value of 3rd byte of "a"
            chars[i] = 0xEE;
        }
    }
    printf("value of \"a\" before changes: %x\n", a);
    for(int i = 0; i < 4; i++) {                                 // cycle for changing values of the least significant byte
        a = ((a << 8) | (0xFF & chars[3-i]));                    // shifting by 1 byte to the left side and changing value of the least significant byte until whole var "a" will be rewrote
    }
    printf("value of \"a\" after changes: %x", a);
    printf("\n\n");
}