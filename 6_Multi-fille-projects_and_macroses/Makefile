CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
SRC = src
BUILD = build

all: build_dir q1 q2 q3 q4 q5 q6 q7 q8

build_dir:
	mkdir -p $(BUILD)

q1: $(SRC)/dmanager_module.c
	$(CC) $(CFLAGS) $(SRC)/dmanager_module.c -o $(BUILD)/Quest_1

q2: $(SRC)/list.c $(SRC)/list_test.c
	$(CC) $(CFLAGS) $(SRC)/list.c $(SRC)/list_test.c -o $(BUILD)/Quest_2

q3: $(SRC)/stack.c $(SRC)/stack_test.c
	$(CC) $(CFLAGS) $(SRC)/stack.c $(SRC)/stack_test.c -o $(BUILD)/Quest_3

q4: $(SRC)/print_module.c $(SRC)/main_print.c
	$(CC) $(CFLAGS) $(SRC)/print_module.c $(SRC)/main_print.c -o $(BUILD)/Quest_4

q5: $(SRC)/documentation_module.c $(SRC)/main_module_entry_point.c $(SRC)/print_module.c
	$(CC) $(CFLAGS) $(SRC)/documentation_module.c $(SRC)/main_module_entry_point.c $(SRC)/print_module.c -o $(BUILD)/Quest_5

q6: $(SRC)/bst.c $(SRC)/bst_create_test.c
	$(CC) $(CFLAGS) $(SRC)/bst.c $(SRC)/bst_create_test.c -o $(BUILD)/Quest_6

q7: $(SRC)/bst.c $(SRC)/bst_insert_test.c
	$(CC) $(CFLAGS) $(SRC)/bst.c $(SRC)/bst_insert_test.c -o $(BUILD)/Quest_7

q8: $(SRC)/bst.c $(SRC)/bst_traverse_test.c
	$(CC) $(CFLAGS) $(SRC)/bst.c $(SRC)/bst_traverse_test.c -o $(BUILD)/Quest_8

clean:
	rm -rf $(BUILD)

re: clean all

.PHONY: all build_dir clean re q1 q2 q3 q4 q5 q6 q7 q8