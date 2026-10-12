#ifndef STACK_H
#define STACK_H

typedef struct stack_node {
    int value;
    struct stack_node *next;
} stack_node;

typedef struct stack {
    stack_node *top;
    int size;
} stack;

void init(stack *s);
int push(stack *s, int value);
int pop(stack *s, int *value);
void destroy(stack *s);

#endif