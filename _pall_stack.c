#include "monty.h"

/**
* pall - prints all the values on the stack, starting from the top
* @stack: double pointer to the top of the stack
* @line_number: line number
* Return: nothing
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
