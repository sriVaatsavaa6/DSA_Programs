#include <stdio.h>
#include <math.h>

void tower(int n, char from, char aux, char to) {
    if (n == 0)
        return;
    tower(n - 1, from, to, aux);                 // move n-1 from 'from' to 'aux'
    printf("Move disc %d from peg %c to peg %c\n", n, from, to);
    tower(n - 1, aux, from, to);                 // move n-1 from 'aux' to 'to'
}

int main() {
    int n;
    printf("Enter number of discs: ");
    scanf("%d", &n);

    tower(n, 'A', 'B', 'C');
    printf("Total moves = %d\n", (int)pow(2, n) - 1);
    return 0;
}
