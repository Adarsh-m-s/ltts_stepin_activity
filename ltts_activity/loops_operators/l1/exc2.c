#include <stdio.h>

void printBits(unsigned int num) {
    int i;
    unsigned int mask = 1 << 31; 

    for (i = 0; i < 32; i++) {
        if (num & mask) {
            printf("1");
        } else {
            printf("0");
        }

        mask >>= 1;

        if ((i + 1) % 8 == 0) {
            printf(" ");
        }
    }

    printf("\n");
}

int main() {
    unsigned int num;

    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Binary representation: ");
    printBits(num);

    return 0;
}
