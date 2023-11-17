#include "monty.h"


void montyPushFunc(stack_t **stack, unsigned int line_number);
void montyPallFunc(stack_t **stack, unsigned int line_number);
void montyPintFunc(stack_t **stack, unsigned int line_number);
void montyPopFunc(stack_t **stack, unsigned int line_number);
void montySwapFunc(stack_t **stack, unsigned int line_number);


/**
 * montyPushFunc - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void montyPushFunc(stack_t **stack, unsigned int line_number) 
{
	stack_t *temp, *newNode;
	int j;

	newNode = malloc(sizeof(stack_t));
	switch (newNode == NULL) {
		case 1:
			setOpTokError(mallocError());
			return;
	}

	switch (opToks[1] == NULL) 
	{
		case 1:
			setOpTokError(errorNoInt(line_number));
			return;
	}

	for (j = 0; opToks[1][j]; j++) 
	{
		switch (opToks[1][j] == '-' && j == 0) 
		{
			case 1:
				continue;
		}
		switch (opToks[1][j] < '0' || opToks[1][j] > '9') 
		{
			case 1:
				setOpTokError(errorNoInt(line_number));
				return;
		}
	}
	newNode->n = atoi(opToks[1]);

	switch (checkOurMode(*stack) == STACK) 
	{
		case 1: /* STACK mode insert at front */
			temp = (*stack)->next;
			newNode->prev = *stack;
			newNode->next = temp;
			if (temp)
				temp->prev = newNode;
			(*stack)->next = newNode;
			break;
		default: /* QUEUE mode insert at end */
			temp = *stack;
			while (temp->next)
				temp = temp->next;
			newNode->prev = temp;
			newNode->next = NULL;
			temp->next = newNode;
			break;
	}
}


/**
 * montyPallFunc - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void montyPallFunc(stack_t **stack, unsigned int line_number) 
{
	stack_t *temp = (*stack)->next;

	for (; temp != NULL; temp = temp->next) 
	{
		printf("%d\n", temp->n);
	}
	(void)line_number;
}


/**
 * montyPopFunc - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void montyPopFunc(stack_t **stack, unsigned int line_number) 
{
	stack_t *next = NULL;

	switch ((*stack)->next == NULL) 
	{
		case 1:
			setOpTokError(poppingError(line_number));
			return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	switch (next != NULL) {
		case 1:
			next->prev = *stack;
	}
	(*stack)->next = next;
}


/**
 * montyPintFunc - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void montyPintFunc(stack_t **stack, unsigned int line_number) 
{
	switch ((*stack)->next == NULL) 
	{
		case 1:
			setOpTokError(pintError(line_number));
			return;
	}

	printf("%d\n", (*stack)->next->n);
}



/**
 * montySwapFunc - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void montySwapFunc(stack_t **stack, unsigned int line_number) 
{
	stack_t *temp;

	switch ((*stack)->next == NULL || (*stack)->next->next == NULL) 
	{
		case 1:
			setOpTokError(errorShortStack(line_number, "swap"));
			return;
	}

	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
	switch (temp->next != NULL) 
	{
		case 1:
			temp->next->prev = (*stack)->next;
	}
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
