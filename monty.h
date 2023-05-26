#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
extern char *line;
extern FILE *file;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
void nope(stack_t **stack, unsigned int line_number);
void add_to_stack(stack_t **stack, unsigned int line_number);
void get_mod(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void subtraction(stack_t **stack, unsigned int line_number);
void mutiply(stack_t **stack, unsigned int line_number);
void swap_nodes(stack_t **stack, unsigned int line_number);
void pop_node(stack_t **stack, unsigned int line_number);
void pint_node(stack_t **stack, unsigned int line_number);
void push_node(stack_t **stack, unsigned int line_number);
void print_all_nodes(stack_t **stack, __attribute__((unused))unsigned int line_number);
void first_to_laast_node(stack_t **stack, unsigned int line_number);
void my_putchar(stack_t **stack, unsigned int line_number);
char *parse_line(char *str);
instruct_func get_right_function(char *str);
void mread_file(char *filename, stack_t **stack);
void free_all_list(stack_t *head);
void print_all_2(stack_t **head);
void print_head(stack_t **head, int num);
void print_header_data(stack_t **head, int num);
void del_head_node(stack_t **head);
stack_t *add_header(stack_t **head, int n);
void free_then_exit(stack_t **stack);
stack_t *first_to_last_stack(stack_t **stack);
size_t new_getline(char **lineptr, size_t *n, FILE *stream);
int is_a_number(char *str);
#endif
