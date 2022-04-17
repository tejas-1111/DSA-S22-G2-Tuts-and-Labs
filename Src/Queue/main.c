#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/**
 * @brief Prints a  queue
 * Notice how I am not accessing or traversing the elements of the queue
 * since there is no such operation defined for the queue
 * instead I am only using the operations defined for the queue to print all the elements
 *
 * @param q Pointer to the queue
 */
void QueuePrint(Queue *q) {
    Queue *temp = QueueInit();
    printf("Queue: ");
    while (!QueueEmpty(q)) {
        QueueData ele = QueueDequeue(q);
        printf("%d ", ele.val);
        QueueEnqueue(temp, ele);
    }
    printf("\n");
    while (!QueueEmpty(temp)) {
        QueueData ele = QueueDequeue(temp);
        QueueEnqueue(q, ele);
    }
    free(temp);
}

int main() {
    QueueData d1, d2, d3;
    d1.val = 1;
    d2.val = 2;
    d3.val = 3;

    Queue *q = QueueInit();

    printf("Enqueue: %d\n", d1.val);
    QueueEnqueue(q, d1);
    QueuePrint(q);
    printf("Empty:%d   Size:%d\n", QueueEmpty(q), QueueSize(q));
    printf("Front: %d\n", QueueFront(q));
    printf("Dequeue: %d\n", QueueDequeue(q));
    QueuePrint(q);
    printf("Empty:%d   Size:%d\n", QueueEmpty(q), QueueSize(q));
    printf("___________________\n");

    printf("Enqueue: %d\n", d1.val);
    QueueEnqueue(q, d1);
    QueuePrint(q);
    printf("Empty:%d   Size:%d\n", QueueEmpty(q), QueueSize(q));
    printf("Enqueue: %d\n", d2.val);
    QueueEnqueue(q, d2);
    QueuePrint(q);
    printf("Empty:%d   Size:%d\n", QueueEmpty(q), QueueSize(q));
    printf("Enqueue: %d\n", d3.val);
    QueueEnqueue(q, d3);
    QueuePrint(q);
    printf("Empty:%d   Size:%d\n", QueueEmpty(q), QueueSize(q));
    printf("___________________\n");

    printf("Front: %d\n", QueueFront(q));
    printf("Dequeue: %d\n", QueueDequeue(q));
    QueuePrint(q);
    printf("Empty:%d   Size:%d\n", QueueEmpty(q), QueueSize(q));
    printf("Front: %d\n", QueueFront(q));
    printf("Dequeue: %d\n", QueueDequeue(q));
    QueuePrint(q);
    printf("Empty:%d   Size:%d\n", QueueEmpty(q), QueueSize(q));
    printf("Front: %d\n", QueueFront(q));
    printf("Dequeue: %d\n", QueueDequeue(q));
    QueuePrint(q);
    printf("Empty:%d   Size:%d\n", QueueEmpty(q), QueueSize(q));
    printf("___________________\n");
    // QueueDequeue(q); // error 101
    // QueueFront(q); // error 102
}