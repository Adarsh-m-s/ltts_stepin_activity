// Write a function to add a member at the end of the above array of structures
// Note : Code must use Dynamic Memory concept

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

struct Student* addStudent(struct Student* students, int* size) {
    (*size)++;
    students = realloc(students, (*size) * sizeof(struct Student));
    
    printf("\nEnter details for new student:\n");
    printf("Roll No: ");
    scanf("%d", &students[*size - 1].rollno);
    getchar();
    printf("Name: ");
    fgets(students[*size - 1].name, sizeof(students[*size - 1].name), stdin);
    students[*size - 1].name[strcspn(students[*size - 1].name, "\n")] = '\0';
    printf("Marks: ");
    scanf("%f", &students[*size - 1].marks);
    getchar();
    
    return students;
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();
    
    struct Student* students = malloc(size * sizeof(struct Student));
    
    for (int i = 0; i < size; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        getchar();
        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        getchar();
    }
    
    students = addStudent(students, &size);
    
    printf("\nUpdated Students List:\n");
    printf("--------------------\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }
    
    free(students);
    
    return 0;
}
