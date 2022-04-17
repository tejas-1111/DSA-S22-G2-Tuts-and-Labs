#ifndef QUEUE_H
#define QUEUE_H

/*
exit code -> meaning
101 -> Tried to Dequeue an empty queue
102 -> Using front on an empty queue
*/

// Change as per requirements
typedef struct QueueData {
    int val;
} QueueData;

typedef struct QueueNode {
    QueueData data;
    struct QueueNode *prev;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    int size;
    QueueNode *front;
    QueueNode *back;
} Queue;

Queue *QueueInit();
int QueueSize(Queue *q);
int QueueEmpty(Queue *q);
void QueueEnqueue(Queue *q, QueueData);
QueueData QueueDequeue(Queue *q);
QueueData QueueFront(Queue *q);

#endif