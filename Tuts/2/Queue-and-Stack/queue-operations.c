#include <stdio.h>

#include "queue.h"

void QueueNodePrint(QueueNode *n) { printf("%d\t %p \t %p\t %p\n", n->val, n->prev, n, n->next); }

int main() {
    QueueNode *n1, *n2, *n3, *n4, ret;
    n1 = QueueNodeInit();
    n2 = QueueNodeInit();
    n3 = QueueNodeInit();
    n4 = QueueNodeInit();
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    Queue *q;
    q = QueueInit();
    printf("%d %d\n\n", QueueSize(q), QueueEmpty(q));

    QueueEnqueue(q, n1);
    printf("%d %d\n\n", QueueSize(q), QueueEmpty(q));
    QueuePrint(q);
    ret = QueueFront(q);
    QueueNodePrint(&ret);
    ret = QueueDequeue(q);
    QueueNodePrint(&ret);
    QueuePrint(q);
    printf("%d %d\n\n", QueueSize(q), QueueEmpty(q));

    QueueEnqueue(q, n2);
    QueueEnqueue(q, n3);
    QueueEnqueue(q, n4);
    printf("%d %d\n\n", QueueSize(q), QueueEmpty(q));

    QueuePrint(q);
    ret = QueueFront(q);
    QueueNodePrint(&ret);
    ret = QueueDequeue(q);
    QueueNodePrint(&ret);
    QueuePrint(q);
    printf("%d %d\n\n", QueueSize(q), QueueEmpty(q));

    QueuePrint(q);
    ret = QueueFront(q);
    QueueNodePrint(&ret);
    ret = QueueDequeue(q);
    QueueNodePrint(&ret);
    QueuePrint(q);
    printf("%d %d\n\n", QueueSize(q), QueueEmpty(q));

    QueuePrint(q);
    ret = QueueFront(q);
    QueueNodePrint(&ret);
    ret = QueueDequeue(q);
    QueueNodePrint(&ret);
    QueuePrint(q);
    printf("%d %d\n\n", QueueSize(q), QueueEmpty(q));

    // error 101
    // QueueDequeue(q);
    // error 102
    // QueueFront(q);
}