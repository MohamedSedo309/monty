#include "monty.h"
/**
*mread_file - opens file and reads it
*@filename: file name
*@stack: pointer to pointer of stack
*
*Return: void
*/
char *line = NULL;
FILE *file;
void mread_file(char *filename, stack_t **stack)
{
	size_t len = 0;
	int n_read;
	int line_count = 1;
	char *command;
	instruct_func s;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free_then_exit(stack);
	}
	while ((n_read = new_getline(&line, &len, file)) != -1)
	{
		command = parse_line(line);

		if (command == NULL || command[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_right_function(command);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, command);
			free_then_exit(stack);
		}
		s(stack, line_count);
		line_count++;
	}
	free(line);
	if ((fclose(file)) == -1)
		exit(-1);
}
/**
*get_right_function - selects right function
*@str: opcode
*
*Return: function pointer
*/
instruct_func get_right_function(char *str)
{
	int i;

	instruction_t instruct[] = {
			{"push", push_node},
			{"pint", pint_node},
			{"add", add_to_stack},
			{"swap", swap_nodes},
			{"pop", pop_node},
			{"pall", print_all_nodes},
			{"nop", nope},
			{"sub", subtraction},
			{"mul", mutiply},
			{"div", divide},
			{"mod", get_mod},
			{"rotl", first_to_laast_node},
			{"pchar", my_putchar},
			{NULL, NULL}
	};

	i = 0;

	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}
	return (instruct[i].f);
}
/**
*parse_line - tokenize line
*@str: line
*
*Return: a word, the opcode command
*/
char *parse_line(char *str)
{
	char *opcode;

	opcode = strtok(str, "\n ");
	if (opcode == NULL)
		return (NULL);
	return (opcode);
}

#define BUFFER_SIZE 1024
/**
*new_getline - getline()
*@lineptr: pointer to line
*@n: number of chars
*@stream: file or src
*
*Return: number of chars
*/
size_t new_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos;
	int c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = (char *)malloc(*n);
	}
	if (*lineptr == NULL)
	{
		return (-1);
	}
	pos = 0;

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (pos >= *n - 1)
		{
			char *new_lineptr;
			*n += BUFFER_SIZE;
			new_lineptr = (char *)realloc(*lineptr, *n);

			if (new_lineptr == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = new_lineptr;
		}
		(*lineptr)[pos++] = (char)c;
	}
	if (c == EOF && pos == 0)
	{
		return (-1);
	}
	(*lineptr)[pos] = '\0';
	return (pos);
}
/**
*is_a_number - checks for numbers
*@str: string to test
*
*Return: 1 on sucess or -1 on failure
*/
int is_a_number(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
