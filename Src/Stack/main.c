#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/**
 * @brief Prints a stack
 * Notice how I am not accessing or traversing the elements of the queue
 * since there is no such operation defined for the stack
 * instead I am only using the operations defined for the stack to print all the elements
 *
 * @param s Pointer to the stack
 */
void StackPrint(Stack *s) {
    Stack *temp = StackInit();
    printf("Stack: ");
    while (!StackEmpty(s)) {
        StackData ele = StackPop(s);
        printf("%d ", ele.val);
        StackPush(temp, ele);
    }
    printf("\n");
    while (!StackEmpty(temp)) {
        StackData ele = StackPop(temp);
        StackPush(s, ele);
    }
    free(temp);
}

int main() {
    StackData d1, d2, d3;
    d1.val = 1;
    d2.val = 2;
    d3.val = 3;

    Stack *s = StackInit();

    printf("Push: %d\n", d1.val);
    StackPush(s, d1);
    StackPrint(s);
    printf("Empty:%d   Size:%d\n", StackEmpty(s), StackSize(s));
    printf("Top: %d\n", StackTop(s));
    printf("Pop: %d\n", StackPop(s));
    StackPrint(s);
    printf("Empty:%d   Size:%d\n", StackEmpty(s), StackSize(s));
    printf("___________________\n");

    printf("Push: %d\n", d1.val);
    StackPush(s, d1);
    StackPrint(s);
    printf("Empty:%d   Size:%d\n", StackEmpty(s), StackSize(s));
    printf("Push: %d\n", d2.val);
    StackPush(s, d2);
    StackPrint(s);
    printf("Empty:%d   Size:%d\n", StackEmpty(s), StackSize(s));
    printf("Push: %d\n", d3.val);
    StackPush(s, d3);
    StackPrint(s);
    printf("Empty:%d   Size:%d\n", StackEmpty(s), StackSize(s));
    printf("___________________\n");

    printf("Top: %d\n", StackTop(s));
    printf("Pop: %d\n", StackPop(s));
    StackPrint(s);
    printf("Empty:%d   Size:%d\n", StackEmpty(s), StackSize(s));
    printf("Top: %d\n", StackTop(s));
    printf("Pop: %d\n", StackPop(s));
    StackPrint(s);
    printf("Empty:%d   Size:%d\n", StackEmpty(s), StackSize(s));
    printf("Top: %d\n", StackTop(s));
    printf("Pop: %d\n", StackPop(s));
    StackPrint(s);
    printf("Empty:%d   Size:%d\n", StackEmpty(s), StackSize(s));
    printf("___________________\n");
    // StackPop(s); // error 201
    // StackTop(s); // error 202
}