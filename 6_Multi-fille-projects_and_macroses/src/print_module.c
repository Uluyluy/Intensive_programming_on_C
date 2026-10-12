#include "print_module.h"

#include <stdio.h>
#include <time.h>

int print_char(char ch) {
    int result = putchar(ch);
    return result;
}

void print_log(int (*print)(char), char* message) {
    if (print != NULL && message != NULL) {
        time_t now = time(NULL);
        struct tm* t = localtime(&now);
        char header[32];
        int len = snprintf(header, sizeof(header), "[LOG] %02d:%02d:%02d ", t->tm_hour, t->tm_min, t->tm_sec);
        int i = 0;
        while (i < len) {
            print(header[i]);
            i++;
        }
        i = 0;
        while (message[i] != '\0') {
            print(message[i]);
            i++;
        }
        print('\n');
    }
}