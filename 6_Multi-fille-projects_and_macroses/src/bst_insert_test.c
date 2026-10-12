#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

#define SUCCESS 0
#define FAIL 1

static int cmp_int(int a, int b);
static void free_tree(t_btree *root);
static int check_shape(t_btree *root, int root_v, int left_v, int right_v);
int test_insert_set1(void);
int test_insert_set2(void);

int main(void) {
    int result = SUCCESS;
    if (test_insert_set1() == FAIL) {
        result = FAIL;
    }
    if (test_insert_set2() == FAIL) {
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

static void free_tree(t_btree *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

static int check_shape(t_btree *root, int root_v, int left_v, int right_v) {
    int ok = 0;
    if (root != NULL && root->item == root_v && root->left != NULL && root->left->item == left_v &&
        root->right != NULL && root->right->item == right_v) {
        ok = 1;
    }
    return ok;
}

int test_insert_set1(void) {
    int result = FAIL;
    t_btree *root = bstree_create_node(10);
    if (root != NULL) {
        bstree_insert(root, 5, cmp_int);
        bstree_insert(root, 15, cmp_int);
        if (check_shape(root, 10, 5, 15)) {
            printf("Set1: root=10, left=5, right=15 OK\n");
            result = SUCCESS;
        }
        free_tree(root);
    }
    return result;
}

int test_insert_set2(void) {
    int result = FAIL;
    t_btree *root = bstree_create_node(20);
    if (root != NULL) {
        bstree_insert(root, 8, cmp_int);
        bstree_insert(root, 30, cmp_int);
        if (check_shape(root, 20, 8, 30)) {
            printf("Set2: root=20, left=8, right=30 OK\n");
            result = SUCCESS;
        }
        free_tree(root);
    }
    return result;
}