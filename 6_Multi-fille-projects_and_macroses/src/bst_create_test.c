#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

#define SUCCESS 0
#define FAIL 1

int test_create_node_positive(void);
int test_create_node_negative(void);

int main(void) {
    int result = SUCCESS;
    if (test_create_node_positive() == FAIL) {
        result = FAIL;
    }
    if (test_create_node_negative() == FAIL) {
        result = FAIL;
    }
    return result;
}

int test_create_node_positive(void) {
    int result = FAIL;
    t_btree *n = bstree_create_node(7);
    if (n != NULL && n->item == 7 && n->left == NULL && n->right == NULL) {
        printf("Created node with item = %d\n", n->item);
        result = SUCCESS;
    }
    free(n);
    return result;
}

int test_create_node_negative(void) {
    int result = FAIL;
    t_btree *n = bstree_create_node(-5);
    if (n != NULL && n->item == -5 && n->left == NULL && n->right == NULL) {
        printf("Created node with item = %d\n", n->item);
        result = SUCCESS;
    }
    free(n);
    return result;
}