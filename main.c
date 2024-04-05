#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
data_file_t data = {NULL, NULL, NULL};
/**
 * main - the main function
 *
 * @argc: the arguments
 *
 * @argv: the argument vector
 *
 * Return: (0) on success, (1) failure.
*/
int main(int argc, char **argv)
{
	FILE *file;
	size_t read_line = 1;
	char *command_line;
	size_t size = 0;
	char *content = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fclose(data.file);
		fprintf(stderr, "usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	data.file = file;

	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		command_line = NULL;
		data.content = content;
		read_line = getline(&command_line, &size, file);
		line_number++;
		if (read_line > 0)
		{
			get_func(content, &stack, line_number, file);
		}
		free(command_line);
	}
	free(stack);
	fclose(data.file);
	return (0);
}
