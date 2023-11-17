#include "monty.h"


int usages_errors(void);
int mallocError(void);
int f_openError(char *filename);
int unknownOpErrors(char *opcode, unsigned int line_number);
int errorNoInt(unsigned int line_number);


/**
 * usages_errors - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int usages_errors(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}


/**
 * mallocError - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int mallocError(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}


/**
 * f_openError - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int f_openError(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}


/**
 * unknownOpErrors - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int unknownOpErrors(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}


/**
 * errorNoInt - Prints invalid montyPushFunc argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int errorNoInt(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
