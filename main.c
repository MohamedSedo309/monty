#include "monty.h"
/**
*main - entry point
*@argc: args count
*@argv: args list
*
*Return: 0 on success
*/
int main(int argc, char *argv[])
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_then_exit(&stack);
	}
	mread_file(argv[1], &stack);
	free_all_list(stack);
	return (0);
}
