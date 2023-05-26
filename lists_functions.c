#include "monty.h"
/**
 * add_header - Adds a new node to head
 * @head: head pointer
 * @n: stack-n
 *
 * Return: A pointer to the new head of the list
 */
stack_t *add_header(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		free_then_exit (head);
	}
	new_node->n = n;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*head = new_node;
		return (*head);
	}
	(*head)->prev = new_node;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
	return (*head);
}
/**
 * del_head_node - Deletes header
 * @head: A pointer to the head of the list
 *
 * Return: Void
 */
void del_head_node(stack_t **head)
{
	stack_t *temp_node;

	if (*head == NULL)
	{
		printf("Error");
		free_then_exit(head);
	}
	temp_node = *head;
	if (temp_node->next != NULL)
	{
		*head = temp_node->next;
		(*head)->prev = NULL;
		free(temp_node);
	}
	if (temp_node->next == NULL)
	{
		free(temp_node);
		*head = NULL;
	}
}
/**
 * print_head - Prints the head node
 * @head: head pointer
 * @n: stack-n
 *
 * Return: void
 */
void print_head(stack_t **head, int n)
{
    stack_t *current = *head;

    if (current == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", n);
        free_then_exit(head);
    }
    printf("%d\n", current->n);
}
/**
 * print_all_2 - Prints all elements in a doubly linked list
 * @head:  head pointer
 *
 * Return: void
 */
void print_all_2(stack_t **head)
{
    stack_t *current = *head;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
*free_all_list - frees whole list
* @head:  head pointer
*
*Return: void
*/
void free_all_list(stack_t *head)
{
	stack_t *temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}
