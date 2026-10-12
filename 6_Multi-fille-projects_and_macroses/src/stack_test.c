#include "stack.h"

#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

int test_push(void) {
    int result = FAIL;
    struct stack s;
    init(&s);
    if (push(&s, 42) == SUCCESS && s.size == 1 && s.top != NULL && s.top->value == 42) {
        result = SUCCESS;
    }
    destroy(&s);
    return result;
}

int test_pop(void) {
    int result = FAIL;
    struct stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    int v = 0;
    if (pop(&s, &v) == SUCCESS && v == 20 && s.size == 1) {
        result = SUCCESS;
    }
    destroy(&s);
    return result;
}

int main(void) {
    int rc = SUCCESS;
    if (test_push() == FAIL) {
        printf("test_push: FAIL\n");
        rc = FAIL;
    } else {
        printf("test_push: SUCCESS\n");
    }
    if (test_pop() == FAIL) {
        printf("test_pop: FAIL\n");
        rc = FAIL;
    } else {
        printf("test_pop: SUCCESS\n");
    }
    return rc;
}