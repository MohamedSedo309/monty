#include "monty.h"
/**
*nope- nothing to do
*@stack: pointer to pointer of stack
*@line_number: number to be added
*
*Return: void
*/
void nope(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
*add_to_stack- add element to stack
*@stack: pointer to pointer of stack
*@line_number: number to be added
*
*Return: void
*/

void add_to_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_then_exit(stack);
	}
	temp->next->n += temp->n;
	*stack = temp;
	pop_node(stack, line_number);
}
/**
*subtraction- make sub opration
*@stack: pointer to pointer of stack
*@line_number: number to be added
*
*Return: void
*/

void subtraction(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_then_exit(stack);
	}
	temp->next->n -= temp->n;
	*stack = temp;
	pop_node(stack, line_number);
}
/**
*divide- div d 1st 2 elemnts of a stack stores d result in d 2nd elemnt, del 1st
*@stack: pointer to pointer of double linked list
*@line_number: number to be added to stack
*
*Return: void
*/
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
*mutiply- mutiply 2 elements
*@stack: pointer to pointer of stack
*@line_number: number to be added
*
*Return: void
*/

void mutiply(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_then_exit(stack);
	}
	temp->next->n *= temp->n;
	*stack = temp;
	pop_node(stack, line_number);
}
