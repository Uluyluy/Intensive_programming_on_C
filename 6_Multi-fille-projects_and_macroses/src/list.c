#include "list.h"

#include <stdlib.h>

struct node* init(struct door d) {
    struct node* result = NULL;
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if (n != NULL) {
        n->data = d;
        n->next = NULL;
        result = n;
    }
    return result;
}

struct node* add_door(struct node* elem, struct door d) {
    struct node* result = NULL;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node != NULL) {
        new_node->data = d;
        new_node->next = NULL;
        if (elem != NULL) {
            new_node->next = elem->next;
            elem->next = new_node;
        }
        result = new_node;
    }
    return result;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* result = NULL;
    struct node* curr = root;
    int found = 0;
    while (curr != NULL && found == 0) {
        if (curr->data.id == door_id) {
            result = curr;
            found = 1;
        } else {
            curr = curr->next;
        }
    }
    return result;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* result = root;
    if (elem != NULL && root != NULL) {
        if (elem == root) {
            result = root->next;
            free(elem);
        } else {
            struct node* prev = root;
            int found = 0;
            while (prev != NULL && found == 0) {
                if (prev->next == elem) {
                    prev->next = elem->next;
                    free(elem);
                    found = 1;
                } else {
                    prev = prev->next;
                }
            }
        }
    }
    return result;
}

void destroy(struct node* root) {
    struct node* curr = root;
    while (curr != NULL) {
        struct node* next = curr->next;
        free(curr);
        curr = next;
    }
}