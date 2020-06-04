#include <stdio.h>
int main(void) {
    printf("Enter an operand: ");
    int invalid = 1;
    char op;
    do {
        op = getchar();
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '\n')
            invalid = 0;
        else if (op != ' ') printf("Invalid operator. Please enter one of {+, -, *, /}");
    }
    while (invalid);
    printf("\nYou have entered the operand: %c", op);
    return 0;
}