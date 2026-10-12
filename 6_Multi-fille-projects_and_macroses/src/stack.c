#include "stack.h"

#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1

void init(struct stack* s) {
    if (s != NULL) {
        s->top = NULL;
        s->size = 0;
    }
}

int push(struct stack* s, int value) {
    int result = FAIL;
    if (s != NULL) {
        struct stack_node* n = (struct stack_node*)malloc(sizeof(struct stack_node));
        if (n != NULL) {
            n->value = value;
            n->next = s->top;
            s->top = n;
            s->size++;
            result = SUCCESS;
        }
    }
    return result;
}

int pop(struct stack* s, int* value) {
    int result = FAIL;
    if (s != NULL && s->top != NULL) {
        struct stack_node* tmp = s->top;
        if (value != NULL) {
            *value = tmp->value;
        }
        s->top = tmp->next;
        s->size--;
        free(tmp);
        result = SUCCESS;
    }
    return result;
}

void destroy(struct stack* s) {
    if (s != NULL) {
        int dummy;
        while (pop(s, &dummy) == SUCCESS) {
        }
    }
}