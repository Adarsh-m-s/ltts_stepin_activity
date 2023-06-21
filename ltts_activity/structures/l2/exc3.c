//  Implement structures to read, write and compute average- marks and the students scoring above
//  and below the average marks for a class of N students.

#include <stdio.h>

struct Student {
    char name[50];
    float marks;
};

void readStudents(struct Student students[], int n) {
    printf("Enter details of students:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%f", &students[i].marks);
    }
}

void writeStudents(struct Student students[], int n) {
    printf("\nStudent details:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
    }
}

float calculateAverage(struct Student students[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].marks;
    }
    return sum / n;
}

void printAboveAverage(struct Student students[], int n, float average) {
    printf("\nStudents scoring above average:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks > average) {
            printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
        }
    }
}

void printBelowAverage(struct Student students[], int n, float average) {
    printf("\nStudents scoring below average:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks < average) {
            printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    struct Student students[n];
    
    readStudents(students, n);
    writeStudents(students, n);
    
    float average = calculateAverage(students, n);
    printf("\nAverage marks: %.2f\n", average);
    
    printAboveAverage(students, n, average);
    printBelowAverage(students, n, average);
    
    return 0;
}


