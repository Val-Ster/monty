Stack11.c

#include "monty.h"
#include <string.h>


void freeeStack(stack_t **stack);
int initStackk(stack_t **stack);
int checkOurMode(stack_t *stack);


/**
 * freeeStack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void freeeStack(stack_t **stack)
{
    stack_t *tmmp = *stack;


    while (*stack)
    {
        tmmp = (*stack)->next;
        free(*stack);
        *stack = tmmp;
    }
}


/**
 * initStackk - Initializes a stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int initStackk(stack_t **stack)
{
    stack_t *ss;


    ss = malloc(sizeof(stack_t));
    if (ss == NULL)
        return (mallocError());


    ss->n = STACK;
    ss->prev = NULL;
    ss->next = NULL;


    *stack = ss;


    return (EXIT_SUCCESS);
}


/**
 * checkOurMode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int checkOurMode(stack_t *stack)
{
    if (stack->n == STACK)
        return (STACK);
    else if (stack->n == QUEUE)
        return (QUEUE);
    return (2);
}



