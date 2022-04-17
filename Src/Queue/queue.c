#include "queue.h"

#include <stdlib.h>

/**
 * @brief Initalizes a Queue and returns a pointer to it
 *
 * @return Queue* Pointer to the queue
 */
Queue *QueueInit() {
    Queue *q = malloc(sizeof(Queue));
    q->size = 0;
    q->front = NULL;
    q->back = NULL;
    return q;
}

/**
 * @brief Initalizes a node in the Queue dll structure.
 * Not defined in the header file since this is an internal function
 * So it should not be available for external use
 *
 * @param d The data for the node
 * @return QueueNode* Pointer to the node
 */
QueueNode *QueueNodeInit(QueueData d) {
    QueueNode *n = malloc(sizeof(QueueNode));
    n->data = d;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

/**
 * @brief Returns the number of elements in a queue
 *
 * @param q Pointer to the queue
 * @return int Number of elements in the queue
 */
int QueueSize(Queue *q) { return q->size; }

/**
 * @brief Checks if a queue is empty
 *
 * @param q Pointer to the queue
 * @return int 1 if the queue is empty, 0 otherwise
 */
int QueueEmpty(Queue *q) { return (q->size == 0); }

/**
 * @brief Add an element to the back of a queue
 *
 * @param q Pointer to the Queue
 * @param d Data to add to the back of the queue
 */
void QueueEnqueue(Queue *q, QueueData d) {
    QueueNode *n = QueueNodeInit(d);
    if (q->size == 0) {
        q->front = n;
        q->back = n;
    } else {
        q->back->next = n;
        n->prev = q->back;
        q->back = n;
    }
    q->size += 1;
}

/**
 * @brief Remove and return the element at the front of the Queue
 * Exits with error 101 if the queue is empty
 *
 * @param q Pointer to the Queue
 * @return QueueData The element removed from the queue
 */
QueueData QueueDequeue(Queue *q) {
    if (q->size == 0) {
        exit(101);
    }
    q->size -= 1;
    QueueNode *old_front, *new_front;
    old_front = q->front;
    new_front = old_front->next;
    if (new_front == NULL) {
        q->back = NULL;
    } else {
        new_front->prev = NULL;
    }
    q->front = new_front;
    QueueData ret_val = old_front->data;
    free(old_front);
    return ret_val;
}

/**
 * @brief Returns the element at the front of the queue
 *
 * @param q Pointer to the queue
 * @return QueueData The element at the front of the queue
 */
QueueData QueueFront(Queue *q) {
    if (q->size == 0) {
        exit(102);
    }
    return q->front->data;
}