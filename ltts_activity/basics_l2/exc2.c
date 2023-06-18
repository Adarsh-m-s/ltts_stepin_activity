// Write a function to return the grade of the given student using switch case statements
// 90 to 100 -> 'A'
// 75 to 89 -> 'B'
// 60 to 74 -> 'C'
// 50 to 59 -> 'D'
// 36 to 49 -> 'E'
// 0 to 35 -> 'F'

// In main check the return value and print the below
// 65 -> "Grade A"
// 66 -> "Grade B"
// 67 -> "Grade C"
// 68 -> "Grade D"
// 69 -> "Grade E"
// 70 -> "Grade F"


#include <stdio.h>

char calculateGrade(int marks) {
    char grade;
    int lowerBound = marks / 10 * 10; // Round down to the nearest multiple of 10

    switch (lowerBound) {
        case 90:
        case 100:
            grade = 'A';
            break;
        case 75:
        case 89:
            grade = 'B';
            break;
        case 60:
        case 74:
            grade = 'C';
            break;
        case 50:
        case 59:
            grade = 'D';
            break;
        case 36:
        case 49:
            grade = 'E';
            break;
        case 0:
        case 35:
            grade = 'F';
            break;
        default:
            grade = 'X'; // Invalid grade
            break;
    }

    return grade;
}

int main() {
    int marks;
    printf("Enter the marks: ");
    scanf("%d", &marks);

    char grade = calculateGrade(marks);
    printf("Grade: %c\n", grade);

    return 0;
}
