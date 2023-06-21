#include <stdio.h>

unsigned char setBit(unsigned char num, int pos) {
    unsigned char mask = (1 << pos);
    return num | mask;
}

unsigned char clearBit(unsigned char num, int pos) {
    unsigned char mask = ~(1 << pos);
    return num & mask;
}

unsigned char toggleBit(unsigned char num, int pos) {
    unsigned char mask = (1 << pos);
    return num ^ mask;
}

int main() {
    unsigned char num = 0b10101010;

    unsigned char setResult = setBit(num, 2);
    printf("%u\n", setResult);

    unsigned char clearResult = clearBit(num, 5);
    printf("%u\n", clearResult);

    unsigned char toggleResult = toggleBit(num, 3);
    printf("%u\n", toggleResult);

    return 0;
}
