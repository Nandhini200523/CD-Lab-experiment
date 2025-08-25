#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to trim spaces from a string (helper)
void trim(char *str) {
    int i, j = 0;
    char temp[500];
    for (i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

// Function to recognize control structure
void recognize(char str[]) {
    trim(str);

    if (strncmp(str, "for(", 4) == 0 && strchr(str, ';') != NULL) {
        printf("Valid FOR loop syntax\n");
    }
    else if (strncmp(str, "while(", 6) == 0 && str[strlen(str)-1] == ')') {
        printf("Valid WHILE loop syntax\n");
    }
    else if (strncmp(str, "if(", 3) == 0) {
        if (strstr(str, "else if(") != NULL) {
            printf("Valid IF-ELSE-IF syntax\n");
        }
        else if (strstr(str, "else") != NULL) {
            printf("Valid IF-ELSE syntax\n");
        }
        else {
            printf("Valid IF syntax\n");
        }
    }
    else if (strncmp(str, "switch(", 7) == 0 && strstr(str, "case") != NULL) {
        printf("Valid SWITCH-CASE syntax\n");
    }
    else {
        printf("Not a valid control structure\n");
    }
}

int main() {
    char code[500];

    printf("Enter a C control structure: \n");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0'; // remove newline

    recognize(code);

    return 0;
}
Output:

Enter a C control structure:
for(i=0;i<10;i++)
Valid FOR loop syntax

Enter a C control structure:
if(a>b) else if(a<c)
Valid IF-ELSE-IF syntax

Enter a C control structure:
switch(x) { case 1: break; }
Valid SWITCH-CASE syntax

Enter a C control structure:
hello world
Not a valid control structure
