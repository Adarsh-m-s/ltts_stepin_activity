// DS1307 has its time registers in BCD format as shown in the image found in the above link, To set the time we need to convert the decimal number to BCD format, hence, write a fucntion to convert decimal to BCD

// Concepts to be used.
// - Operators
// - Preprocessor

#include <stdio.h>

#define DECIMAL_TO_BCD(dec) (((dec / 10) << 4) | (dec % 10))

unsigned char decimalToBCD(unsigned char dec) {
    return (((dec / 10) << 4) | (dec % 10));
}

int main() {
    unsigned char decimal = 25;
    unsigned char bcd = decimalToBCD(decimal);
    printf("Decimal: %d\n", decimal);
    printf("BCD: 0x%02X\n", bcd);

    return 0;
}
