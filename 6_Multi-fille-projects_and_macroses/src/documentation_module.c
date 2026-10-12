#include "documentation_module.h"

#include <stdlib.h>

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    int* result = NULL;
    if (validate != NULL && document_count > 0) {
        result = (int*)malloc(sizeof(int) * (size_t)document_count);
        if (result != NULL) {
            va_list args;
            va_start(args, document_count);
            int i = 0;
            while (i < document_count) {
                char* doc = va_arg(args, char*);
                result[i] = validate(doc);
                i++;
            }
            va_end(args);
        }
    }
    return result;
}

int validate(char* data) {
    int validation_result = 0;
    if (data != NULL && strcmp(data, AVAILABLE_DOCUMENT) == 0) {
        validation_result = 1;
    }
    return validation_result;
}