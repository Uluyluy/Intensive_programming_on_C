#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

#define SUCCESS 0
#define FAIL 1

static int cmp_int(int a, int b);
static void print_int(int v);
static void free_tree(t_btree *root);
static t_btree *build_sample(void);

int main(void) {
    int result = SUCCESS;
    t_btree *root = build_sample();
    if (root != NULL) {
        printf("Infix: ");
        bstree_apply_infix(root, print_int);
        printf("\n");

        printf("Prefix: ");
        bstree_apply_prefix(root, print_int);
        printf("\n");

        printf("Postfix: ");
        bstree_apply_postfix(root, print_int);
        printf("\n");

        free_tree(root);
    } else {
        result = FAIL;
    }
    return result;
}

static int cmp_int(int a, int b) {
    int result = 0;
    if (a < b) {
        result = -1;
    } else if (a > b) {
        result = 1;
    }
    return result;
}

static void print_int(int v) { printf("%d ", v); }

static void free_tree(t_btree *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

static t_btree *build_sample(void) {
    t_btree *root = bstree_create_node(10);
    if (root != NULL) {
        bstree_insert(root, 5, cmp_int);
        bstree_insert(root, 15, cmp_int);
        bstree_insert(root, 2, cmp_int);
        bstree_insert(root, 7, cmp_int);
    }
    return root;
}