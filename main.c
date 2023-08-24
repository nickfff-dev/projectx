#include "monty.h"
/**
* main - The entry point of the program
* @argc: parameter of type int .
* @argv: parameter of type char **.
* Return: int .
*/
global_t global;

/**
  * main - The entry point of the program
  * @argc: parameter of type int .
  * @argv: parameter of type char **.
  * Return: int .
 */
int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.file = fopen(argv[1], "r");
	if (global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	global.line = malloc(256 * sizeof(char));
	while (fgets(global.line, 256, global.file))
	{
		line_number++;
		parse_line(line_number, &stack);
	}
	fclose(global.file);
	free(global.line);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
