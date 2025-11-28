#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int s[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("\n~~~~Stack overflow~~~~");
        return;
    }
    top++;
    s[top] = item;
}

int pop() {
    if (top == -1) {
        printf("\n~~~~Stack underflow~~~~");
        return -1;
    }
    return s[top--];
}

void display() {
    if (top == -1) {
        printf("\n~~~~Stack is empty~~~~");
        return;
    }
    printf("\nStack elements are:\n");
    for (int i = top; i >= 0; i--)
        printf("| %d |\n", s[i]);
}

void palindrome() {
    if (top == -1) {
        printf("\n~~~~Stack is empty~~~~");
        return;
    }
    int flag = 1;
    printf("\nStack content are:\n");
    for (int i = top; i >= 0; i--)
        printf("| %d |\n", s[i]);

    printf("\nReverse of stack content are:\n");
    for (int i = 0; i <= top; i++)
        printf("| %d |\n", s[i]);

    for (int i = 0; i <= top / 2; i++) {
        if (s[i] != s[top - i]) {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("\nIt is palindrome number");
    else
        printf("\nIt is not a palindrome number");
}

int main() {
    int choice, item;

    while (1) {
        printf("\n\n~~~~~~Menu~~~~~~ : ");
        printf("\n=>1.Push an Element to Stack and Overflow demo ");
        printf("\n=>2.Pop an Element from Stack and Underflow demo");
        printf("\n=>3.Palindrome demo ");
        printf("\n=>4.Display ");
        printf("\n=>5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter an element to be pushed:");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1)
                    printf("\nElement popped is: %d", item);
                break;
            case 3:
                palindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nPlease enter valid choice ");
        }
    }
    return 0;
}
