// 5. Write a program to encode any given string such that it gets converted into an unrecognizable form.
// Also write a decode function to get back the original string.

#include <stdio.h>
#include <string.h>

void encode(char *str)
{
    char *ptr = str;
    while (*ptr != '\0')
    {
        *ptr = *ptr + 1;
        ptr++;
    }
}

void decode(char *str)
{
    char *ptr = str;
    while (*ptr != '\0')
    {
        *ptr = *ptr - 1;
        ptr++;
    }
}

int main()
{
    char originalStr[] = "Hello, World!";
    char encodedStr[100];

    strcpy(encodedStr, originalStr);
    encode(encodedStr);
    printf("Encoded string: %s\n", encodedStr);

    decode(encodedStr);
    printf("Decoded string: %s\n", encodedStr);

    return 0;
}
