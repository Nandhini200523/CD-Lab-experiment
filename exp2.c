#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lexicalAnalyzer(const char *expr) {
    int i = 0;
    while (expr[i] != '\0') {
        if (isspace(expr[i])) {
            i++; // skip spaces
            continue;
        }
        else if (isdigit(expr[i])) {
            printf("NUMBER\t");
            while (isdigit(expr[i]) || expr[i] == '.') {
                printf("%c", expr[i]);
                i++;
            }
            printf("\n");
            continue;
        }
        else if (expr[i] == '+') {
            printf("PLUS\t+\n");
        }
        else if (expr[i] == '-') {
            printf("MINUS\t-\n");
        }
        else if (expr[i] == '*') {
            printf("MUL\t*\n");
        }
        else if (expr[i] == '/') {
            printf("DIV\t/\n");
        }
        else if (expr[i] == '(') {
            printf("LPAREN\t(\n");
        }
        else if (expr[i] == ')') {
            printf("RPAREN\t)\n");
        }
        else {
            printf("INVALID\t%c\n", expr[i]);
        }
        i++;
    }
}

int main() {
    char expr[256];
    printf("Enter an arithmetic expression: ");
    fgets(expr, sizeof(expr), stdin);

    printf("\nTokens:\n");
    lexicalAnalyzer(expr);

    return 0;
}
