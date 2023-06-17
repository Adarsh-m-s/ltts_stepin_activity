// 2. Write a program to swap any type of data passed to an function.

#include <stdio.h>

void swap(void *ptr1, void *ptr2, size_t size) {
    char *temp = (char *)malloc(size);
    memcpy(temp, ptr1, size);
    memcpy(ptr1, ptr2, size);
    memcpy(ptr2, temp, size);
    free(temp);
}

int main() {
    int a = 5;
    int b = 10;
    
    printf("Before swap: a = %d, b = %d\n", a, b);
    
    swap(&a, &b, sizeof(int));
    
    printf("After swap: a = %d, b = %d\n", a, b);
    
    double x = 3.14;
    double y = 2.71;
    
    printf("Before swap: x = %f, y = %f\n", x, y);
    
    swap(&x, &y, sizeof(double));
    
    printf("After swap: x = %f, y = %f\n", x, y);
    
    return 0;
}
