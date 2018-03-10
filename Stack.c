//
// Created by Remi Robert on 09/03/2018.
//

#include <stdlib.h>
#include "Stack.h"

struct s_stack {
    int *values;
    int capacity;
    int top;
};

struct s_stack *make_stack(int capacity) {
    if (capacity < 0) {
        return NULL;
    }
    struct s_stack *stack = malloc(sizeof(struct s_stack));
    stack->values = malloc(capacity * sizeof(int));
    stack->capacity = capacity;
    stack->top = 0;
    return stack;
}

int stack_length(struct s_stack *stack) {
    return stack->top;
}

int stack_push(struct s_stack *stack, int value) {
    if (stack->top + 1 > stack->capacity) {
        return -1;
    }
    stack->values[++stack->top] = value;
    return 0;
}

int stack_pop(struct s_stack *stack) {
    if (stack->top == 0) {
        return INT32_MIN;
    }
    return stack->values[stack->top--];
}