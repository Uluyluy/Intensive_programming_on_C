#ifndef DOCUMENTATION_MODULE_H
#define DOCUMENTATION_MODULE_H

#include <stdarg.h>
#include <string.h>

#define DOCUMENTS_COUNT 4
#define AVAILABLE_DOCUMENT "Binary Trees"

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...);
int validate(char* data);

#endif