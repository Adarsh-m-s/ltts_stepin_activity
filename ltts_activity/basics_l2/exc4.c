// Write a function to find the type of the character passed
//     - 'A' to 'Z', return 1
//     - 'a; to 'z', return 2
//     - '0' to '9', return 3
//     - Any Other printable symbols, return 4
//     - Non printable symbols, return 5

#include <stdio.h>

int charType(char c) {
    int type;

    if (c >= 'A' && c <= 'Z') {
        type = 1;
    } else if (c >= 'a' && c <= 'z') {
        type = 2;
    } else if (c >= '0' && c <= '9') {
        type = 3;
    } else if (c >= 32 && c <= 126) {
        type = 4;
    } else {
        type = 5;
    }

    return type;
}

int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    int result = charType(ch);

    switch (result) {
        case 1:
            printf("Type: Uppercase Alphabet\n");
            break;
        case 2:
            printf("Type: Lowercase Alphabet\n");
            break;
        case 3:
            printf("Type: Digit\n");
            break;
        case 4:
            printf("Type: Printable Symbol\n");
            break;
        case 5:
            printf("Type: Non-Printable Symbol\n");
            break;
    }

    return 0;
}
