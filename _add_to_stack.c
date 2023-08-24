#include "monty.h"

/**
* add - Adds the top two elements of the stack.
* @stack: Double pointer to the top of the stack.
* @line_number: The line number currently being run.
* Return: nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_global();
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n + (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = result;
	free(temp);
}
