#include "monty.h"


void montyNopFunc(stack_t **stack, unsigned int line_number);
void montyPcharFunc(stack_t **stack, unsigned int line_number);
void montyPstrFunc(stack_t **stack, unsigned int line_number);


/**
 * montyNopFunc - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void montyNopFunc(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * montyPcharFunc - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void montyPcharFunc(stack_t **stack, unsigned int line_number) {
    switch ((*stack)->next == NULL) {
        case 1:
            setOpTokError(pcharError(line_number, "stack empty"));
            return;
    }
    switch ((*stack)->next->n < 0 || (*stack)->next->n > 127) {
        case 1:
            setOpTokError(pcharError(line_number, "value out of range"));
            return;
    }

    printf("%c\n", (*stack)->next->n);
}


/**
 * montyPstrFunc - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
 void montyPstrFunc(stack_t **stack, unsigned int line_number) {
    stack_t *tmp = (*stack)->next;

    for (; tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127); tmp = tmp->next) {
        printf("%c", tmp->n);
    }

    printf("\n");

    (void)line_number;
}

