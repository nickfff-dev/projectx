#include "monty.h"

/**
* free_stack - frees a stack_t stack
* @stack: stack to be freed
* Return: nothing
*/
void free_stack(stack_t **stack)
{
	stack_t *current;

	while (*stack)
	{
		current = (*stack)->next;
		free(*stack);
		*stack = current;
	}
}
/**
* free_global - the function name
* Return:
*/
void free_global(void)
{
	free(global.line);
	if (global.file)
	{
		fclose(global.file);
	}
}
