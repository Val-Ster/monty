
#include "monty.h"


void montyRotlFunc(stack_t **stack, unsigned int line_number);
void montyRotrFunc(stack_t **stack, unsigned int line_number);
void montyStackFunc(stack_t **stack, unsigned int line_number);
void montyQueueFunc(stack_t **stack, unsigned int line_number);


/**
 * montyRotlFunc - Rotates the topp value of a stack_t linked list to the bott.
 * @stack: A pointer to the topp mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void montyRotlFunc(stack_t **stack, unsigned int line_number) {
    stack_t *topp, *bott;

    switch ((*stack)->next == NULL || (*stack)->next->next == NULL) {
        case 1:
            return;
    }

    topp = (*stack)->next;
    bott = (*stack)->next;
    while (bott->next != NULL)
        bott = bott->next;

    topp->next->prev = *stack;
    (*stack)->next = topp->next;
    bott->next = topp;
    topp->next = NULL;
    topp->prev = bott;

    (void)line_number;
}


/**
 * montyRotrFunc - Rotates the bott value of a stack_t linked list to the topp.
 * @stack: A pointer to the topp mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
 void montyRotrFunc(stack_t **stack, unsigned int line_number) {
    stack_t *topp, *bott;

    switch ((*stack)->next == NULL || (*stack)->next->next == NULL) {
        case 1:
            return;
    }

    topp = (*stack)->next;
    bott = (*stack)->next;
    while (bott->next != NULL)
        bott = bott->next;

    bott->prev->next = NULL;
    (*stack)->next = bott;
    bott->prev = *stack;
    bott->next = topp;
    topp->prev = bott;

    (void)line_number;
}


/**
 * montyStackFunc - Converts a queue to a stack.
 * @stack: A pointer to the topp mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void montyStackFunc(stack_t **stack, unsigned int line_number) {
    (*stack)->n = STACK;
    (void)line_number;
}


/**
 * montyQueueFunc - Converts a stack to a queue.
 * @stack: A pointer to the topp mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void montyQueueFunc(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = QUEUE;
    (void)line_number;
}


