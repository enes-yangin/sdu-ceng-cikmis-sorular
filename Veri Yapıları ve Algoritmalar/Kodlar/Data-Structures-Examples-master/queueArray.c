#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    int *array;
    unsigned capacity;
};

struct Queue *
createQueue(unsigned capacity) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

    queue->capacity = capacity;
    queue->size = 0;
    queue->rear = queue->capacity - 1;
    queue->front = 0;
    queue->array = (int *)malloc(sizeof(int) * queue->capacity);

    return queue;
}

int isFull(struct Queue *queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int data) {
    if (isFull(queue)) return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;
    queue->size++;

    printf("%d enqueued to queue\n", data); 
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) return -1;

    int data = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;

    return data;
}

int main() {
    
    return 0;
}