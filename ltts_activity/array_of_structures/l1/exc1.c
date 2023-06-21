// Assume User will be providing input in the form of a string as show below. 
// Write a function to parse the string and initialize an array of structures. 

// Example String : "1001 Aron 100.00" 
// Example Structure : 
//     struct Student{
//         int rollno;
//         char name[20];
//         float marks;
//     };

// Note: User must be able define the no. of inputs/size of the array during runtime.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(char* inputString, struct Student* students, int size) {
    char* token = strtok(inputString, " ");
    int i = 0;
    
    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);
        
        token = strtok(NULL, " ");
        strcpy(students[i].name, token);
        
        token = strtok(NULL, " ");
        students[i].marks = atof(token);
        
        token = strtok(NULL, " ");
        i++;
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();
    
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));
    
    printf("Enter the student data (rollno name marks):\n");
    for (int i = 0; i < size; i++) {
        char inputString[100];
        fgets(inputString, sizeof(inputString), stdin);
        
        inputString[strcspn(inputString, "\n")] = '\0';
        
        initializeStudents(inputString, &students[i], 1);
    }
    
    printf("\nStudent Information:\n");
    printf("--------------------\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }
    
    free(students);
    
    return 0;
}
