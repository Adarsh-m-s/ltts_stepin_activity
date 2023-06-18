#include <stdio.h>

int main() {
    int rollNo, physicsMarks, mathMarks, chemistryMarks;
    char name[50];
    float totalMarks, percentage;

    printf("Enter Roll No: ");
    scanf("%d", &rollNo);
    
    printf("Enter Name: ");
    scanf(" %[^\n]s", name);
    
    printf("Enter Marks in Physics: ");
    scanf("%d", &physicsMarks);
    
    printf("Enter Marks in Math: ");
    scanf("%d", &mathMarks);
    
    printf("Enter Marks in Chemistry: ");
    scanf("%d", &chemistryMarks);
    
    totalMarks = physicsMarks + mathMarks + chemistryMarks;
    percentage = (totalMarks / 300) * 100;
    
    printf("\nSummary:\n");
    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Physics Marks: %d\n", physicsMarks);
    printf("Math Marks: %d\n", mathMarks);
    printf("Chemistry Marks: %d\n", chemistryMarks);
    printf("Total Marks: %.2f\n", totalMarks);
    printf("Percentage: %.2f%%\n", percentage);
    
    return 0;
}
