// Write a program to find both smallest and largest digits in given n numbers
// For example let's say we have n = 3, and n1 = 8, n2 = 156, n3 = 123450, the result will be "Not Valid", 1 and 6, 0 and 5

#include <stdio.h>
#include <stdarg.h>

int getSmallestDigit(int num) {
    int smallest_digit = 9;
    while (num != 0) {
        int digit = num % 10;
        if (digit < smallest_digit) {
            smallest_digit = digit;
        }
        num /= 10;
    }
    return smallest_digit;
}

int getLargestDigit(int num) {
    int largest_digit = 0;
    while (num != 0) {
        int digit = num % 10;
        if (digit > largest_digit) {
            largest_digit = digit;
        }
        num /= 10;
    }
    return largest_digit;
}

void findSmallestAndLargestDigits(int n, ...) {
    va_list numbers;
    va_start(numbers, n);

    int smallest_digit = 9;
    int largest_digit = 0;

    for (int i = 0; i < n; i++) {
        int num = va_arg(numbers, int);
        int current_smallest = getSmallestDigit(num);
        int current_largest = getLargestDigit(num);

        if (current_smallest < smallest_digit) {
            smallest_digit = current_smallest;
        }
        if (current_largest > largest_digit) {
            largest_digit = current_largest;
        }
    }

    va_end(numbers);

    if (smallest_digit == 9 || largest_digit == 0) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallest_digit);
        printf("Largest Digit: %d\n", largest_digit);
    }
}

int main() {
    findSmallestAndLargestDigits(3, 8, 156, 123450);
    return 0;
}

