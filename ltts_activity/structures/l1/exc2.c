// Write a C program that uses functions to perform the following operations: 
//      i) Reading a complex number 
//      ii) Writing a complex number 
//      iii) Addition of two complex numbers 
//      iv) Multiplication of two complex numbers 
//   (Note: represent complex number using a structure.

#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

void readComplex(struct Complex *c) {
    printf("Enter the real part: ");
    scanf("%f", &c->real);
    printf("Enter the imaginary part: ");
    scanf("%f", &c->imag);
}

void writeComplex(struct Complex c) {
    printf("Complex number: %.2f + %.2fi\n", c.real, c.imag);
}

struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

struct Complex multiplyComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int main() {
    struct Complex num1, num2, sum, product;

    readComplex(&num1);
    readComplex(&num2);

    writeComplex(num1);
    writeComplex(num2);

    sum = addComplex(num1, num2);
    writeComplex(sum);

    product = multiplyComplex(num1, num2);
    writeComplex(product);

    return 0;
}
