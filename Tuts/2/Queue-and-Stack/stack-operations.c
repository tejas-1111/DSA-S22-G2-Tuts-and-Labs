#include <stdio.h>

#include "stack.h"

void StackNodePrint(StackNode *n) { printf("%d\t %p \t %p\t %p\n", n->val, n->down, n, n->up); }

int main() {
    StackNode *n1, *n2, *n3, *n4, ret;
    n1 = StackNodeInit();
    n2 = StackNodeInit();
    n3 = StackNodeInit();
    n4 = StackNodeInit();
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    Stack *s;
    s = StackInit();
    printf("%d %d\n\n", StackSize(s), StackSize(s));

    StackPush(s, n1);
    printf("%d %d\n\n", StackSize(s), StackSize(s));
    StackPrint(s);
    ret = StackTop(s);
    StackNodePrint(&ret);
    ret = StackPop(s);
    StackNodePrint(&ret);
    StackPrint(s);
    printf("%d %d\n\n", StackSize(s), StackSize(s));

    StackPush(s, n2);
    StackPush(s, n3);
    StackPush(s, n4);
    printf("%d %d\n\n", StackSize(s), StackSize(s));

    StackPrint(s);
    ret = StackTop(s);
    StackNodePrint(&ret);
    ret = StackPop(s);
    StackNodePrint(&ret);
    StackPrint(s);
    printf("%d %d\n\n", StackSize(s), StackSize(s));

    StackPrint(s);
    ret = StackTop(s);
    StackNodePrint(&ret);
    ret = StackPop(s);
    StackNodePrint(&ret);
    StackPrint(s);
    printf("%d %d\n\n", StackSize(s), StackSize(s));

    StackPrint(s);
    ret = StackTop(s);
    StackNodePrint(&ret);
    ret = StackPop(s);
    StackNodePrint(&ret);
    StackPrint(s);
    printf("%d %d\n\n", StackSize(s), StackSize(s));

    // error 201
    // StackPop(s);
    // error 202
    // StackTop(s);
}