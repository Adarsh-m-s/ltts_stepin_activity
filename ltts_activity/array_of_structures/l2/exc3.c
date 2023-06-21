// Write a function to swap 2 members in different indexes (based on user input) in the above array of structures

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void swapStudents(struct Student* students, int index1, int index2) {
    struct Student temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;
}

int main() {
    struct Student students[3];

    students[0].rollno = 1001;
    strcpy(students[0].name, "John");
    students[0].marks = 85.5;

    students[1].rollno = 1002;
    strcpy(students[1].name, "Jane");
    students[1].marks = 92.0;

    students[2].rollno = 1003;
    strcpy(students[2].name, "Alex");
    students[2].marks = 78.5;

    printf("Before swapping:\n");
    for (int i = 0; i < 3; i++) {
        printf("Student %d\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("------------------\n");
    }

    int index1, index2;
    printf("Enter the indexes to swap (0-2): ");
    scanf("%d %d", &index1, &index2);

    if (index1 >= 0 && index1 < 3 && index2 >= 0 && index2 < 3) {
        swapStudents(students, index1, index2);
        printf("Swapping successful.\n");
    } else {
        printf("Invalid indexes.\n");
    }

    printf("\nAfter swapping:\n");
    for (int i = 0; i < 3; i++) {
        printf("Student %d\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("------------------\n");
    }

    return 0;
}
