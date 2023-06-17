// 4. Write a program to find total number of bits set in a given array.
// Say we have a array of 3 elements a[3] = {0x1, 0xF4, 0x10001);
// The total number of set bits in the given array is
// 1 bit in 0x01, 5 in 0xF * 4 2 in Ox10001, so the total is 1 + 5 + 2 = 8 bits

#include <stdio.h>

int countSetBits(int num) {
    int count = 0;
    while (num != 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int arr[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(arr) / sizeof(arr[0]);
    int totalBits = 0;

    for (int i = 0; i < size; i++) {
        totalBits += countSetBits(arr[i]);
    }

    printf("Total number of set bits: %d\n", totalBits);

    return 0;
}
