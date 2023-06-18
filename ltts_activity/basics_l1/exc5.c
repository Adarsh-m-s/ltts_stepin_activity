#include <stdio.h>

int bit_operations(int num, int oper_type) {
    int result = num;

    switch (oper_type) {
        case 1:
            result |= 1;
            break;
        case 2:
            result &= ~(1 << 31);
            break;
        case 3:
            result ^= (1 << 16);
            break;
        default:
            printf("Error: Invalid operation type.\n");
            break;
    }

    return result;
}

int main() {
    int num, oper_type;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter the operation type (1, 2, or 3): ");
    scanf("%d", &oper_type);

    int result = bit_operations(num, oper_type);
    printf("Result: %d\n", result);

    return 0;
}
