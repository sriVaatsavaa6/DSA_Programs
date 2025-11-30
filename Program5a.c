#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

double compute(char op, double a, double b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return (int)a % (int)b;   // for integer remainder
        case '^':
        case '$': return pow(a, b);
    }
    return 0;
}

int main() {
    char postfix[50], ch;
    double stack[50], op1, op2, res;
    int top = -1, i;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; i < strlen(postfix); i++) {
        ch = postfix[i];

        if (isdigit(ch)) {                 // operand
            stack[++top] = ch - '0';
        } else {                           // operator
            op2 = stack[top--];
            op1 = stack[top--];
            res = compute(ch, op1, op2);
            stack[++top] = res;
        }
    }

    printf("Result = %g\n", stack[top]);
    return 0;
}
