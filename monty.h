#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct data_file_s - the operators of the files structure
* @file: te file what the processes will on
*
* @content: the content of the file to be read and edit and execute..etc
*
* @temp: temporary member in the strucutere.
*/
typedef struct data_file_s
{
	FILE *file;
	char *content;
	char *temp;
} data_file_t;
extern data_file_t data;

int main(int argc, char **argv);
void push(stack_t **stack, unsigned int line_number);
int get_func(char *content, stack_t
	**stack, unsigned int line_number, FILE *file);


#endif
