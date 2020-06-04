/* This program is an implementation of a calculator,
 * dealing with expressions involving +, -, *, and /.
 * @author Ali Al-Musawi
 */

#include <stdio.h>
#include <stdlib.h>

char get_op(void);
float get_num(void);
float m_exp(float sub_exp, char op);
float s_exp(void);

int main(void) {
    int looping = 1;
    printf("Welcome to EVALUATE.\n");
    do {
        printf("Please enter an arithmetic expression: ");
        float result = s_exp();
        printf("\nResult: %f", result);
        int unconfirmed = 1;
        char reply;
        do {
            printf("\n\nWould you like to evaluate another expression? (Y/N): ");
            scanf(" %c", &reply);
            if (reply != 'y' && reply != 'Y' && reply != 'n' && reply != 'N')
                printf("\nYou must enter either 'Y' for yes or 'N' for no.");
            else {
                 if (reply == 'n' || reply == 'N') {
                     looping = 0;
                     printf("\nExiting EVALUATE...\n");
                 }
                 unconfirmed = 0;
            }
        }
        while (unconfirmed);

        
    }
    while (looping);
    return 0;
}

/* This functions extracts operators, i.e. +-/* from stdin.
 * @return the next arithmetic operator input by the user.
 */
char get_op(void) {
    int invalid = 1;
    char op;
    do {
        op = getchar();

        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '\n')
            invalid = 0;
        else if (op != ' ') {
            fprintf(stderr, "Invalid operator. Operator is one of {+, -, *, /}.\n");
            printf("Terminating program...\n");
            exit(EXIT_FAILURE);
        } 
    }
    while (invalid);
    return op;
}

/* This function extracts floats from stdin.
 * @return the next numeric value input by the user.
 */
float get_num(void) {
    float num;
    scanf(" %f", &num);
    return num;
}

/* This function evaluates multiplicative expressions recursively.
 * @param sub_exp the value of the expression to the left of op.
 * @param op an operand, one of {'+', '-', '*', '/', '\n'}.
 * @return the value of a subexpression.
 */
float m_exp(float sub_exp, char op) {
    if (op == '+' || op == '-' || op == '\n') {
        ungetc(op, stdin);
        return sub_exp;
    }
    else {
        float next_num = get_num();
        char next_op = get_op();
        float next_sub_exp;
        if (op == '*') next_sub_exp = sub_exp * next_num;
        else if (op == '/') next_sub_exp = sub_exp / next_num;
        return m_exp(next_sub_exp, next_op);
    }
}


/* This function reads an arithmetic expression from std in,
 * and repeatedly calls m_exp() until '\n' is read.
 * @return the result of the arithmetic expression.
 */
float s_exp(void) {
    float num = m_exp(1, '*');
    char op;
    do {
        op = get_op();
        if (op == '+') num = num + m_exp(1, '*');
        else if (op == '-') num = num - m_exp(1, '*');
        }
    while (op != '\n');
    return num;
}

