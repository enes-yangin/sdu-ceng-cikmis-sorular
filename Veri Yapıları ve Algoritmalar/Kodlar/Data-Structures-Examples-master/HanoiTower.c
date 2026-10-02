#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    unsigned capacity;
    int top;
    int *array;
};

struct Stack *createStack(unsigned capacity) {
    struct Stack *yeni = (struct Stack *)malloc(sizeof(struct Stack));

    yeni->capacity = capacity;
    yeni->top = -1;
    yeni->array = (int *)malloc(yeni->capacity * sizeof(int));
    return yeni;
}

void moveDisk(char x, char y, int disk) {
    printf("% disk: \'%d' den \'%c\' hareketi\n", disk, x, y);
}

void push(struct Stack *q, int x) {
    q->array[++q->top] = x;
}

int pop(struct Stack *q) {
    return q->array[q->top--];
}

void mDBTP(struct Stack *q1, struct Stack *q2, char s, char d) {
    int pole1TopDisk = pop(q1);
    int pole2TopDisk = pop(q2);

    if (pole1TopDisk == INT_MIN) {
        push(q1, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    } else if (pole2TopDisk == INT_MIN) {
        push(q2, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    } else if (pole1TopDisk > pole2TopDisk) {
        push(q1, pole1TopDisk);
        push(q1, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    } else {
        push(q2, pole2TopDisk);
        push(q2, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
}

void tahIterative(int numOfDisks, struct Stack *src, struct Stack *aux, struct Stack *dest) {
    int i, totalNumOfMoves;
    char s = 'S', d = 'D', a = 'A';

    if (numOfDisks % 2 == 0) {
        char temp = d;
        d = a;
        a = temp;
    }

    totalNumOfMoves = pow(2, numOfDisks) - 1;

    for (i = numOfDisks; i >= 1; i--){}
        push(src, i);

    for (i = 1; i <= totalNumOfMoves; i++) {
        if (i % 3 == 1)
            mDBTP(src, dest, s, d);
        else if (i % 3 == 2)
            mDBTP(src, aux, s, a);
        else if (i % 3 == 0)
            mDBTP(aux, dest, a, d);
    }
}

int main() {
    unsigned numOfDisks = 3;
    struct Stack *x, *y, *z;

    x = createStack(numOfDisks);
    y = createStack(numOfDisks);
    z = createStack(numOfDisks);

    tahIterative(numOfDisks, x, y, z);

    return 0;
}