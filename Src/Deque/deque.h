#ifndef DEQUE_H
#define DEQUE_H

/*
exit code -> meaning
301 -> Tried to pop back on empty deque
302 -> Tried to pop front on empty deque
303 -> Tried to access front on empty deque
304 -> Tried to access back on empty deque
*/

// Change as per requirements
typedef struct DequeData {
    int val;
} DequeData;

typedef struct DequeNode {
    DequeData data;
    struct DequeNode *prev;
    struct DequeNode *next;
} DequeNode;

typedef struct Deque {
    int size;
    DequeNode *front;
    DequeNode *back;
} Deque;

Deque *DequeInit();
int DequeSize(Deque *d);
int DequeEmpty(Deque *d);
void DequePushBack(Deque *d, DequeData);
void DequePushFront(Deque *d, DequeData);
DequeData DequeBack(Deque *d);
DequeData DequeFront(Deque *d);
DequeData DequePopBack(Deque *d);
DequeData DequePopFront(Deque *d);

#endif
