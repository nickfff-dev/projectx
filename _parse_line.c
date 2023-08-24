#include "monty.h"

/**
* parse_line - parses a line of bytecode and performs the opcode
* @line_number: line of bytecode
* @stack: double pointer to the top of the stack
* Return: 1 if usccesful -1 otherwise
*/
void parse_line(unsigned int line_number, stack_t **stack)
{
	char *opcode, *arg;
	size_t i;
instruction_t instructions[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", add},
{"nop", nop}
		};

		opcode = strtok(global.line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
		{
			return;
		}
		for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				if (i == 0)
				{
					arg = strtok(NULL, " \t\n");
					if (arg == NULL || strspn(arg, "0123456789") != strlen(arg))
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_number);
						free_global();
						exit(EXIT_FAILURE);
					}
					instructions[i].f(stack, atoi(arg));
				}
				else
				{
					instructions[i].f(stack, line_number);
				}
				return;
			}
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free_global();
		exit(EXIT_FAILURE);
	}
