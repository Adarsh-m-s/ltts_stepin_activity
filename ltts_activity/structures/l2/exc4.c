//  Write a program to pass a pointer to a structure as a parameter to a function and return back a pointer to structure 
// to the calling function after modifying the members of structure.

#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

struct Person* modifyPerson(struct Person* person) {
    printf("Enter new name: ");
    scanf("%s", person->name);
    printf("Enter new age: ");
    scanf("%d", &person->age);
    
    return person;
}

int main() {
    struct Person* person = (struct Person*)malloc(sizeof(struct Person));
    
    printf("Enter name: ");
    scanf("%s", person->name);
    printf("Enter age: ");
    scanf("%d", &person->age);
    
    printf("\nBefore modification:\n");
    printf("Name: %s, Age: %d\n", person->name, person->age);
    
    struct Person* modifiedPerson = modifyPerson(person);
    
    printf("\nAfter modification:\n");
    printf("Name: %s, Age: %d\n", modifiedPerson->name, modifiedPerson->age);
    
    free(person);
    
    return 0;
}
