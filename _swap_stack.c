#include "monty.h"

/**
* swap - swaps the top two elements of the stack
* @stack: double pointer to the top of the stack
* @line_number: line number where the opcode is located
* Return: nothing
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_global();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
