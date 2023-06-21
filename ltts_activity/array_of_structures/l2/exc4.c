//  Write a function to rotate the above array of structures by K positions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void rotateStudents(struct Student* students, int size, int k) {
    struct Student* temp = (struct Student*)malloc(k * sizeof(struct Student));

    for (int i = 0; i < k; i++) {
        temp[i] = students[i];
    }

    for (int i = k; i < size; i++) {
        students[i - k] = students[i];
    }

    for (int i = 0; i < k; i++) {
        students[size - k + i] = temp[i];
    }

    free(temp);
}

int main() {
    struct Student students[5];

    rotateStudents(students, 5, 2);

    return 0;
}



