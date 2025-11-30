#include <stdio.h>
#include <stdlib.h>
#define MAX 3

char cq[MAX];
int front = -1, rear = -1;

void insert(char item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("\nCircular Queue Overflow");
        return;
    }
    if (front == -1)             // first element
        front = rear = 0;
    else
        rear = (rear + 1) % MAX; // circular increment
    cq[rear] = item;
}

void deleteQ() {
    char item;
    if (front == -1) {
        printf("\nCircular Queue Underflow");
        return;
    }
    item = cq[front];
    printf("\nDeleted element: %c", item);
    if (front == rear)           // only one element
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    int i;
    if (front == -1) {
        printf("\nCircular Queue Empty");
        return;
    }
    printf("\nCircular Queue: ");
    i = front;
    while (1) {
        printf(" %c", cq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int ch;
    char item;
    while (1) {
        printf("\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf(" %c", &item);   // note space before %c
                insert(item);
                break;
            case 2: deleteQ(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice");
        }
    }
}
