// 1. Write a program to print exponent part of double variable in hexadecimal and binary format.
// lets say we have x = 0.7 the exponent in hex is 0x3FE and Ob01111111110

#include <stdio.h>

void printExponent(double *ptr)
{
    unsigned long long *bits = (unsigned long long *)ptr;
    unsigned long long exponentMask = 0x7FF0000000000000ULL;
    unsigned long long exponent = (*bits & exponentMask) >> 52;

    printf("Exponent in hexadecimal: 0x%llX\n", exponent);

    printf("Exponent in binary: ");
    for (int i = 11; i >= 0; i--)
    {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}

int main()
{
    double x = 0.7;
    printExponent(&x);

    return 0;
}
