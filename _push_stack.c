#include "monty.h"

/**
* push - pushes an element to the stack
* @stack: double pointer to the top of the stack
* @n: line number
* Return: nothing
*/
void push(stack_t **stack, unsigned int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
}
