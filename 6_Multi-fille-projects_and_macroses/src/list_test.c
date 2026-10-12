#include "list.h"

#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

int test_add_door(void);
int test_remove_door(void);

int main(void) {
    int result = SUCCESS;
    if (test_add_door() == FAIL) {
        printf("test_add_door: FAIL\n");
        result = FAIL;
    } else {
        printf("test_add_door: SUCCESS\n");
    }
    if (test_remove_door() == FAIL) {
        printf("test_remove_door: FAIL\n");
        result = FAIL;
    } else {
        printf("test_remove_door: SUCCESS\n");
    }
    return result;
}

int test_add_door(void) {
    int result = FAIL;
    struct door d1 = {1, 0};
    struct door d2 = {2, 1};
    struct node* root = init(d1);
    if (root != NULL) {
        struct node* added = add_door(root, d2);
        if (added != NULL && root->next == added && added->data.id == 2) {
            result = SUCCESS;
        }
        destroy(root);
    }
    return result;
}

int test_remove_door(void) {
    int result = FAIL;
    struct door d1 = {1, 0};
    struct door d2 = {2, 0};
    struct door d3 = {3, 0};
    struct node* root = init(d1);
    if (root != NULL) {
        struct node* n2 = add_door(root, d2);
        struct node* n3 = add_door(n2, d3);
        root = remove_door(n2, root);
        if (root != NULL && root->next == n3 && root->next->data.id == 3) {
            result = SUCCESS;
        }
        destroy(root);
    }
    return result;
}