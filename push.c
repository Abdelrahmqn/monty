#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
* push - fuction that push the elements at the end.
*
* @stack: the stack
*
* @line_number: the number of the lines
*/
void push(stack_t **stack, unsigned int line_number)
{
	int value = 0;
	stack_t *new_element;

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed on line %u\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_element->n = value;
	*stack = new_element;
}
