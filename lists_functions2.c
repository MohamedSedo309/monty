#include "monty.h"
/**
 * first_to_last_stack - Puts the first element of a stack at the end of the list
 * @head: head pointer
 *
 * Return: Pointer to the head of the list
 */
stack_t *first_to_last_stack(stack_t **head)
{
    stack_t *current, *last, *first;

    if (*head == NULL)
        free_then_exit(head);
    if ((*head)->next == NULL)
        return (*head);
    current = *head;
    last = current;
    first = current;

    while (last->next != NULL)
    {
        last = last->next;
    }
    *head = (*head)->next;
    first->next = NULL;
    last->next = first;
    first->prev = last;
    return (*head);
}
/**
 * print_header_data - Prints the char at the head
 * @head: head pointer
 * @num: Line number
 *
 * Return: void
 */
void print_header_data(stack_t **head, int num)
{
    stack_t *current = *head;
    int value;

    if (current == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
        free_then_exit(head);
    }
    value = current->n;
    if ((value < 65 || value > 91) && (value < 97 || value > 122))
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
        free_then_exit(head);
    }
    printf("%c\n", value);
}
