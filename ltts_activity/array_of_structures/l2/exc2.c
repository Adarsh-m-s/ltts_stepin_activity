// Write a function to delete a member at the start of the above array of structures
// Note : Code must use Dynamic Memory concept
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

struct Student* deleteStudent(struct Student* students, int* size) {
    if (*size == 0) {
        printf("No students to delete.\n");
        return students;
    }

    for (int i = 0; i < *size - 1; i++) {
        students[i] = students[i + 1];
    }

    (*size)--;
    students = realloc(students, (*size) * sizeof(struct Student));

    printf("Deleted the first student.\n");
    return students;
}

int main() {
    struct Student* students = NULL;
    int size = 0;

    students = deleteStudent(students, &size);

    return 0;
}
