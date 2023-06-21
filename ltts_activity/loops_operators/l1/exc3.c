// Find the largest number by deleting single digit in a 4 digit number 5872 - 872, 9856 - 986

#include <stdio.h>

int findLargestNumber(int num) {
    char num_str[5];
    sprintf(num_str, "%d", num);
    int largest_num = -1;

    for (int i = 0; i < 4; i++) {
        char temp_num_str[4];
        int index = 0;

        for (int j = 0; j < 4; j++) {
            if (j != i) {
                temp_num_str[index] = num_str[j];
                index++;
            }
        }

        temp_num_str[index] = '\0';
        int temp_num = atoi(temp_num_str);

        if (temp_num > largest_num) {
            largest_num = temp_num;
        }
    }

    return largest_num;
}

int main() {
    int num1 = 5872;
    int largest1 = findLargestNumber(num1);
    printf("Largest number after deleting a digit from %d: %d\n", num1, largest1);

    int num2 = 9856;
    int largest2 = findLargestNumber(num2);
    printf("Largest number after deleting a digit from %d: %d\n", num2, largest2);

    return 0;
}
