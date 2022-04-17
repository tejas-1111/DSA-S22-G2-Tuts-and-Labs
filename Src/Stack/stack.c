#include "stack.h"

#include <stdlib.h>

StackNode *StackNodeInit() {
    StackNode *n = malloc(sizeof(StackNode));
    n->down = NULL;
    n->up = NULL;
    return n;
}

Stack *StackInit() {
    Stack *s = malloc(sizeof(Stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

int StackSize(Stack *s) { return s->size; }

int StackEmpty(Stack *s) { return (s->size == 0); }

void StackPush(Stack *s, StackNode *n) {
    if (s->size == 0) {
        s->top = n;
    } else {
        s->top->up = n;
        n->down = s->top;
        s->top = n;
    }
    s->size += 1;
}

StackNode StackPop(Stack *s) {
    if (s->size == 0) {
        exit(201);
    }
    StackNode *to_remove = s->top;
    StackNode *new_top = to_remove->down;
    to_remove->down = NULL;
    s->size -= 1;
    if (new_top != NULL) {
        new_top->up = NULL;
    }
    s->top = new_top;
    StackNode poped_value = *to_remove;
    free(to_remove);
    return poped_value;
}

StackNode StackTop(Stack *s) {
    if (s->size == 0) {
        exit(202);
    }
    StackNode top_value = *(s->top);
    top_value.down = NULL;
    top_value.up = NULL;
    return top_value;
}


void StackPrint(Stack *s) {
    StackNode *iter = s->top;
    while (iter != NULL) {
        StackNodePrint(iter);
        iter = iter->down;
    }
}
