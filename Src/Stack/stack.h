#ifndef STACK_H
#define STACK_H

/*
exit code -> meaning
201 -> Tried to pop an empty stack
202 -> Using top on an empty stack
*/

// Change as per requirements
typedef struct StackData {
    int val;
} StackData;

typedef struct StackNode {
    StackData data;
    struct StackNode *down;
    struct StackNode *up;
} StackNode;

typedef struct Stack {
    int size;
    StackNode *top;
} Stack;

Stack *StackInit();
int StackSize(Stack *s);
int StackEmpty(Stack *s);
void StackPush(Stack *s, StackData);
StackData StackPop(Stack *s);
StackData StackTop(Stack *s);

#endif