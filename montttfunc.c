#include "monty.h"


void montyAddFunc(stack_t **stack, unsigned int line_number);
void montySubFunc(stack_t **stack, unsigned int line_number);
void montyDivFunc(stack_t **stack, unsigned int line_number);
void montyMulFunc(stack_t **stack, unsigned int line_number);
void montyModFunc(stack_t **stack, unsigned int line_number);


/**
 * montyAddFunc - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void montyAddFunc(stack_t **stack, unsigned int line_number) {
	switch ((*stack)->next == NULL || (*stack)->next->next == NULL) {
		case 1:
			setOpTokError(errorShortStack(line_number, "add"));
			return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	montyPopFunc(stack, line_number);
}


/**
 * montySubFunc - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void montySubFunc(stack_t **stack, unsigned int line_number) {
	switch ((*stack)->next == NULL || (*stack)->next->next == NULL) {
		case 1:
			setOpTokError(errorShortStack(line_number, "sub"));
			return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	montyPopFunc(stack, line_number);
}


/**
 * montyMulFunc - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void montyMulFunc(stack_t **stack, unsigned int line_number) {
	switch ((*stack)->next == NULL || (*stack)->next->next == NULL) {
		case 1:
			setOpTokError(errorShortStack(line_number, "mul"));
			return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	montyPopFunc(stack, line_number);
}


/**
 * montyModFunc - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void montyModFunc(stack_t **stack, unsigned int line_number) {
	switch ((*stack)->next == NULL || (*stack)->next->next == NULL) {
		case 1:
			setOpTokError(errorShortStack(line_number, "mod"));
			return;
	}

	switch ((*stack)->next->n == 0) {
		case 1:
			setOpTokError(divError(line_number));
			return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	montyPopFunc(stack, line_number);
}


/**
 * montyDivFunc - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void montyDivFunc(stack_t **stack, unsigned int line_number) {
	switch ((*stack)->next == NULL || (*stack)->next->next == NULL) {
		case 1:
			setOpTokError(errorShortStack(line_number, "div"));
			return;
	}

	switch ((*stack)->next->n == 0) {
		case 1:
			setOpTokError(divError(line_number));
			return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	montyPopFunc(stack, line_number);
}

