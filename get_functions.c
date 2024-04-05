#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_func - function that gives a pointer to string.
 *
 * @content: the content of the pointer to function.
 *
 * @stack: the instructure from header file stack implementation.
 *
 * @line_number: the number of the lines.
 *
 * @file: the file of the processes
 *
 * @data: the global variables initialization.
 * Return: return (0), or (1) in failure.
 */
int get_func(char *content, stack_t
	**stack, unsigned int line_number, FILE *file, data_file_t *data)
{

	instruction_t op[] = {
			{"push", push},
			{NULL, NULL}
		};
	unsigned int i;
	char *tkn;

	tkn = strtok(content, " \n\t");
	dat.temp = strtok(NULL, " \n\t");

	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(tkn, op[i].opcode) == 0)
		{
			op[i].f(stack, line_number);
			return (0);
		}
	}
	if (tkn && op[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tkn);
		fclose(file);
		free(content);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
