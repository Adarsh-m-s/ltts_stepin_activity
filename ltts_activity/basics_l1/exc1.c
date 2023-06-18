#include <stdio.h>

int findMaxUsingIfElse(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int findMaxUsingTernary(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int main() {
    int a = 10;
    int b = 20;

    int maxUsingIfElse = findMaxUsingIfElse(a, b);
    int maxUsingTernary = findMaxUsingTernary(a, b);

    printf("Max using if-else: %d\n", maxUsingIfElse);
    printf("Max using ternary: %d\n", maxUsingTernary);

    return 0;
}
