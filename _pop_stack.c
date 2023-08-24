#include "monty.h"

/**
* pop - removes the top element of the stack
* @stack: double pointer to the top of the stack
* @line_number: line number where the opcode is located
* Return: nothing
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_global();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
