Monty.h

#ifndef __MONTY_H__
#define __MONTY_H__


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"


/* GLOBAL OPCODE TOKENS */
extern char **opToks;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* PRIMARY INTERPRETER FUNCTIONS */
void freeeStack(stack_t **stack);
int initStackk(stack_t **stack);
int checkOurMode(stack_t *stack);
void freeOurTokens(void);
unsigned int tokenArrLen(void);
int runOurMonty(FILE *script_fd);
void setOpTokError(int error_code);


/* OPCODE FUNCTIONS */
void montyPushFunc(stack_t **stack, unsigned int line_number);
void montyPallFunc(stack_t **stack, unsigned int line_number);
void montyPintFunc(stack_t **stack, unsigned int line_number);
void montyPopFunc(stack_t **stack, unsigned int line_number);
void montySwapFunc(stack_t **stack, unsigned int line_number);
void montyAddFunc(stack_t **stack, unsigned int line_number);
void montyNopFunc(stack_t **stack, unsigned int line_number);
void montySubFunc(stack_t **stack, unsigned int line_number);
void montyDivFunc(stack_t **stack, unsigned int line_number);
void montyMulFunc(stack_t **stack, unsigned int line_number);
void montyModFunc(stack_t **stack, unsigned int line_number);
void montyPcharFunc(stack_t **stack, unsigned int line_number);
void montyPstrFunc(stack_t **stack, unsigned int line_number);
void montyRotlFunc(stack_t **stack, unsigned int line_number);
void montyRotrFunc(stack_t **stack, unsigned int line_number);
void montyStackFunc(stack_t **stack, unsigned int line_number);
void montyQueueFunc(stack_t **stack, unsigned int line_number);


/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);


/* ERROR MESSAGES & ERROR CODES */
int usages_errors(void);
int mallocError(void);
int f_openError(char *filename);
int unknownOpErrors(char *opcode, unsigned int line_number);
int errorNoInt(unsigned int line_number);
int poppingError(unsigned int line_number);
int pintError(unsigned int line_number);
int errorShortStack(unsigned int line_number, char *op);
int divError(unsigned int line_number);
int pcharError(unsigned int line_number, char *message);


#endif /* __MONTY_H__ */


