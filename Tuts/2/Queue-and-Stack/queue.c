#include "queue.h"

#include <stdlib.h>

/**
 * @brief Initalize an empty queue node and return a pointer to it, does not assign values
 *
 * @return QueueNode* -> Pointer to the queue node
 */
QueueNode *QueueNodeInit() {
    QueueNode *n = malloc(sizeof(QueueNode));
    n->prev = NULL;
    n->next = NULL;
    return n;
}

/**
 * @brief Initalize an empty queue and return a pointer to it
 *
 * @return Queue* -> Pointer to the queue
 */
Queue *QueueInit() {
    Queue *q = malloc(sizeof(Queue));
    q->size = 0;
    q->front = NULL;
    q->back = NULL;
    return q;
}

/**
 * @brief Returns the size of an queue
 *
 * @param q -> Pointer to the queue
 * @return int -> Size of the queue
 */
int QueueSize(Queue *q) { return q->size; }

/**
 * @brief Checks if a queue is empty
 *
 * @param q -> Pointer to the queue
 * @return int -> 1 if queue is empty, else 0
 */
int QueueEmpty(Queue *q) { return (q->size == 0); }

/**
 * @brief Adds an element to the back of a queue
 *
 * @param q -> Pointer to the queue
 * @param n -> Node to add to the back of the queue
 */
void QueueEnqueue(Queue *q, QueueNode *n) {
    if (q->size == 0) {
        q->front = n;
        q->back = n;
    } else {
        n->prev = q->back;
        q->back->next = n;
        q->back = n;
    }
    q->size += 1;
}

/**
 * @brief Removes and returns the element at the front of a queue
 *
 * @param q -> Pointer to the queue
 * @return QueueNode -> Element removed from the queue
 */
QueueNode QueueDequeue(Queue *q) {
    if (q->size == 0) {
        exit(101);
    }
    QueueNode *to_remove = q->front;
    QueueNode *new_head = q->front->next;
    to_remove->next = NULL;
    q->size -= 1;
    if (new_head == NULL) {
        q->front = NULL;
        q->back = NULL;
    } else {
        new_head->prev = NULL;
        q->front = new_head;
    }
    QueueNode dequeued_element = *to_remove;
    free(to_remove);
    return dequeued_element;
}

/**
 * @brief Returns the element at the front of a queue
 *
 * @param q -> Pinter to the queue
 * @return QueueNode -> Element at the front of the queue
 */
QueueNode QueueFront(Queue *q) {
    if (q->size == 0) {
        exit(102);
    } else {
        QueueNode front_element = *(q->front);
        front_element.next = NULL;
        front_element.prev = NULL;
        return front_element;
    }
}

/**
 * @brief Prints a queue, make sure that you have implemented the void NodePrint(QueueNode *n) function first
 *
 * @param q -> Pointer to the queue
 */
void QueuePrint(Queue *q) {
    QueueNode *iter = q->front;
    while (iter != NULL) {
        QueueNodePrint(iter);
        iter = iter->next;
    }
}
