#include "monty.h"

/**
* pint - prints the value at the top of the stack
* @stack: double pointer to the top of the stack
* @line_number: line number where the opcode is located
* Return: nothing
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_global();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
