#include "monty.h"
/**
 * free_then_exit - Frees list then exit program
 * @head: head pointer
 *
 * Return: void
 */
void free_then_exit(stack_t **head)
{
    if (line)
        free(line);
    if (file)
        fclose(file);
    if (*head != NULL)
        free_all_list(*head);
    exit(EXIT_FAILURE);
}
