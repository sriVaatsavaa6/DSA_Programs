#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

/* PUSH - Add element to stack */
void push(char ch) {
    stack[++top] = ch;
}

/* POP - Remove and return element from stack */
char pop() {
    return stack[top--];
}

/* Get Operator Precedence */
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

/* Main Conversion Function */
void infix_to_postfix(char *infix, char *postfix) {
    int i = 0, k = 0;
    char ch;
    
    push('#');  // Stack base
    
    while ((ch = infix[i++]) != '\0') {
        
        /* If operand (letter/digit), add to postfix */
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        
        /* If '(', push to stack */
        else if (ch == '(') {
            push(ch);
        }
        
        /* If ')', pop until '(' found */
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();  // Remove '('
        }
        
        /* If operator, pop higher/equal precedence operators */
        else {
            while (precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    
    /* Pop remaining operators */
    while (stack[top] != '#')
        postfix[k++] = pop();
    
    postfix[k] = '\0';  // Null terminate
}

/* Main Program */
int main() {
    char infix[SIZE], postfix[SIZE];
    
    printf("\n=== Infix to Postfix Conversion ===\n");
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    
    infix_to_postfix(infix, postfix);
    
    printf("\nInfix:   %s\n", infix);
    printf("Postfix: %s\n\n", postfix);
    
    return 0;
}
