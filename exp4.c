#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidVariable(char str[]) {
    int i;

    // empty string is not valid
    if (strlen(str) == 0) return 0;

    // check first character
    if (!isalpha(str[0]))
        return 0;

    // check rest of the characters
    for (i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]))   // not letter or digit
            return 0;
    }

    return 1; // valid
}

int main() {
    char var[100];

    printf("Enter a variable name: ");
    scanf("%s", var);

    if (isValidVariable(var))
        printf("Valid variable name\n");
    else
        printf("Invalid variable name\n");

    return 0;

}

OUTPUT:

Enter a variable name: a1b2
Valid variable name

Enter a variable name: 1abc
Invalid variable name

Enter a variable name: abc@12
Invalid variable name
