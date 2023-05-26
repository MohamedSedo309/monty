#include "monty.h"
/**
*get_mod- mod 2 elements
*@stack: pointer to pointer of stack
*@line_number: number of line
*
*Return: void
*/
void get_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_then_exit(stack);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_then_exit(stack);
	}
	temp->next->n /= temp->n;
	*stack = temp;
	pop_node(stack, line_number);
}
/**
*first_to_laast_node - move head to the last positon
*@stack: pointer to pointer of stack
*@line_number: number of line
*
*Return: void
*/
void first_to_laast_node(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	first_to_last_stack(stack);
}
/**
*my_putchar- prints first letter
*@stack: pointer to pointer of stack
*@line_number: number to be added
*
*Return: void
*/
void my_putchar(stack_t **stack, unsigned int line_number)
{
	print_header_data(stack, line_number);
}
