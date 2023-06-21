// Write a function to perform a search operation on the array of structures based on name of the student

#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStudent(const struct Student* student) {
    printf("Roll No: %d\n", student->rollno);
    printf("Name: %s\n", student->name);
    printf("Marks: %.2f\n", student->marks);
    printf("--------------------\n");
}

void searchByName(const struct Student* students, int size, const char* searchName) {
    int found = 0;
    
    printf("\nSearch Results for '%s':\n", searchName);
    printf("--------------------\n");
    
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            displayStudent(&students[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No matching student found.\n");
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();
    
    struct Student students[size];
    
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
    
    char searchName[20];
    printf("\nEnter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    
    searchByName(students, size, searchName);
    
    return 0;
}
