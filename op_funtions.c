#include "monty.h"
/**
*push_node- adds to top of a stack
*@stack: pointer to pointer of stack
*@line_number: number to be added
*
*Return: void
*/
void push_node(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;

	arg = strtok(NULL, "\n ");
	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_then_exit(stack);
	}
	if (is_a_number(arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_then_exit(stack);
	}
	value = atoi(arg);

	add_header(stack, value);
}

/**
*pint_node- print first element in stack
*@stack: pointer to pointer of stack
*@line_number: number to be added
*
*Return: void
*/
void pint_node(stack_t **stack, unsigned int line_number)
{
	print_head(stack, line_number);
}

/**
*print_all_nodes- prints all stack
*@stack: pointer to pointer of stack
*@line_number: number to be added to stack
*
*Return: void
*/
void print_all_nodes(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	print_all_2(stack);
}
/**
*pop_node- deletes stack top
*@stack: pointer to pointer of stack
*@line_number: number to be added
*
*Return: void
*/

void pop_node(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_then_exit(stack);
	}
	del_head_node(stack);
}
/**
*swap_nodes- swaps 2 elements
*@stack: pointer to pointer of stack
*@line_number: number to be added
*
*Return: void
*/

void swap_nodes(stack_t **stack, unsigned int line_number)
{
	int store;
	stack_t *temp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_then_exit(stack);
	}
	store = temp->n;
	temp->n = temp->next->n;
	temp->next->n = store;
}
