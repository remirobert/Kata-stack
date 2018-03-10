#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include "stack.h"

struct s_stack *stack;

#define run_test(fn_name) \
    printf("%s\n", #fn_name); \
    fn_name(); \
    tear_down();

void tear_down() {
    free(stack);
}

void test_empty_stack() {
    stack = make_stack(10);

    assert(stack != NULL);
    assert(stack_length(stack) == 0);
}

void test_make_stack_with_incorrect_capacity() {
    stack = make_stack(-10);

    assert(stack == NULL);
}

void test_push_element() {
    stack = make_stack(10);

    assert(stack_push(stack, 1) == 0);
    assert(stack_length(stack) == 1);
}

void test_push_element_over_capacity() {
    stack = make_stack(1);

    assert(stack_push(stack, 1) == 0);
    assert(stack_push(stack, 1) == -1);
    assert(stack_length(stack) == 1);
}

void test_pop_element() {
    stack = make_stack(1);

    assert(stack_push(stack, 5) == 0);
    assert(stack_length(stack) == 1);
    assert(stack_pop(stack) == 5);
    assert(stack_length(stack) == 0);
}

void test_pop_element_under_capacity() {
    stack = make_stack(1);

    assert(stack_pop(stack) == INT32_MIN);
    assert(stack_length(stack) == 0);
}

void test_pop_correct_order() {
    stack = make_stack(3);

    assert(stack_push(stack, 1) == 0);
    assert(stack_push(stack, 2) == 0);
    assert(stack_push(stack, 3) == 0);
    assert(stack_length(stack) == 3);
    assert(stack_pop(stack) == 3);
    assert(stack_pop(stack) == 2);
    assert(stack_pop(stack) == 1);
    assert(stack_length(stack) == 0);
}

void test_with_empty_stack_zero_capacity() {
    stack = make_stack(0);

    assert(stack_push(stack, 5) == -1);
    assert(stack_pop(stack) == INT32_MIN);
    assert(stack_length(stack) == 0);
}

int main(int argc, char *argv[]) {
    run_test(test_empty_stack);
    run_test(test_make_stack_with_incorrect_capacity);
    run_test(test_push_element);
    run_test(test_push_element_over_capacity);
    run_test(test_pop_element);
    run_test(test_pop_element_under_capacity);
    run_test(test_with_empty_stack_zero_capacity);
    run_test(test_pop_correct_order);
    printf("\nOK\n");
    return 0;
}