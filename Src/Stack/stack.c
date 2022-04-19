#include "stack.h"

#include <stdlib.h>

/**
 * @brief Initalizes a Stack and returns a pointer to it
 *
 * @return Stack* Pointer to the Stack
 */
Stack *StackInit() {
    Stack *s = malloc(sizeof(Stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

/**
 * @brief Initalizes a node in the Stack dll structure.
 * Not defined in the header file since this is an internal function
 * So it should not be available for external use
 *
 * @param d The data for the node
 * @return StackNode* Pointer to the node
 */
StackNode *StackNodeInit(StackData d) {
    StackNode *n = malloc(sizeof(StackNode));
    n->data = d;
    n->down = NULL;
    n->up = NULL;
    return n;
}

/**
 * @brief Returns the number of elements in a stack
 *
 * @param s Pointer to the stack
 * @return int Number of elements in the stack
 */
int StackSize(Stack *s) { return s->size; }

/**
 * @brief Checks if a stack is empty
 *
 * @param s Pointer to the stack
 * @return int 1 if the stack is empty, 0 otherwise
 */
int StackEmpty(Stack *s) { return (s->size == 0); }

/**
 * @brief Add an element to the top of a stack
 *
 * @param s Pointer to the stack
 * @param d Data to add to the top of the stack
 */
void StackPush(Stack *s, StackData d) {
    StackNode *n = StackNodeInit(d);
    if (s->size == 0) {
        s->top = n;
    } else {
        s->top->up = n;
        n->down = s->top;
        s->top = n;
    }
    s->size += 1;
}

/**
 * @brief Remove and return the element at the top of the stack
 * Exits with error 201 if the stack is empty
 *
 * @param s Pointer to the stack
 * @return StackData The element removed from the stack
 */
StackData StackPop(Stack *s) {
    if (s->size == 0) {
        exit(101);
    }
    s->size -= 1;
    StackNode *old_top, *new_top;
    old_top = s->top;
    new_top = old_top->down;
    if (new_top != NULL) {
        new_top->up = NULL;
    }
    s->top = new_top;
    StackData ret_val = old_top->data;
    free(old_top);
    return ret_val;
}

/**
 * @brief Returns the element at the top of a stack
 *
 * @param s Pointer to the stack
 * @return StackData The element at the top of the stack
 */
StackData StackTop(Stack *s) {
    if (s->size == 0) {
        exit(102);
    }
    return s->top->data;
}