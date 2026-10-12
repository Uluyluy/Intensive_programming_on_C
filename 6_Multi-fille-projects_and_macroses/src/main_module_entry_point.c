#include <stdio.h>
#include <stdlib.h>

#include "documentation_module.h"
#include "print_module.h"

int main(void) {
    int result = 0;
    char* docs[DOCUMENTS_COUNT] = {"Linked lists", "Queues", "Maps", "Binary Trees"};
    int count = DOCUMENTS_COUNT;

    print_log(print_char, "Module load success");

    int* availability_mask =
        check_available_documentation_module(validate, count, docs[0], docs[1], docs[2], docs[3]);

    if (availability_mask != NULL) {
        int i = 0;
        while (i < count) {
            const char* status = availability_mask[i] == 1 ? "available" : "unavailable";
            printf("[%-15s : %s]\n", docs[i], status);
            i++;
        }
        free(availability_mask);
    } else {
        result = 1;
    }

    return result;
}