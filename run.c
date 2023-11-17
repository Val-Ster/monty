#include "monty.h"
#include <string.h>


void freeOurTokens(void);
unsigned int tokenArrLen(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int runOurMonty(FILE *script_fd);


/**
 * freeOurTokens - Frees the global opToks array of strings.
 */
void freeOurTokens(void) {
    size_t ii = 0;

    switch (opToks == NULL) {
        case 1:
            return;
    }

    for (ii = 0; opToks[ii]; ii++)
        free(opToks[ii]);

    free(opToks);
}


/**
 * tokenArrLen - Gets the length of current opToks.
 *
 * Return: Length of current opToks (as int).
 */
unsigned int tokenArrLen(void) {
    unsigned int toks_len = 0;

    while (opToks[toks_len])
        toks_len++;

    return (toks_len);
}


/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims) {
    int ii, jj;

    for (ii = 0; line[ii]; ii++) {
        for (jj = 0; delims[jj]; jj++) {
            if (line[ii] == delims[jj])
                break;
        }
        if (delims[jj] == '\0')
            return (0);
    }

    return (1);
}


/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int) {
    instruction_t op_funcs[] = {
        // ... (Same code as before)
    };
    int ii;

    for (ii = 0; op_funcs[ii].opcode; ii++) {
        if (strcmp(opcode, op_funcs[ii].opcode) == 0)
            return (op_funcs[ii].f);
    }

    return (NULL);
}



/**
 * runOurMonty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int runOurMonty(FILE *script_fd) {
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0, exit_status = EXIT_SUCCESS;
    unsigned int line_number = 0, prev_tok_len = 0;
    void (*op_func)(stack_t**, unsigned int);

    switch (initStackk(&stack) == EXIT_FAILURE) {
        case 1:
            return (EXIT_FAILURE);
    }

    while (getline(&line, &len, script_fd) != -1) {
        line_number++;
        opToks = strtow(line, DELIMS);
        switch (opToks == NULL) {
            case 1:
                if (is_empty_line(line, DELIMS))
                    continue;
                freeeStack(&stack);
                return (mallocError());
        }
        if (opToks[0][0] == '#') { /* comment line */
            freeOurTokens();
            continue;
        }
        op_func = get_op_func(opToks[0]);
        switch (op_func == NULL) {
            case 1:
                freeeStack(&stack);
                exit_status = unknownOpErrors(opToks[0], line_number);
                freeOurTokens();
                break;
        }
        prev_tok_len = tokenArrLen();
        op_func(&stack, line_number);
        if (tokenArrLen() != prev_tok_len) {
            if (opToks && opToks[prev_tok_len])
                exit_status = atoi(opToks[prev_tok_len]);
            else
                exit_status = EXIT_FAILURE;
            freeOurTokens();
            break;
        }
        freeOurTokens();
    }
    freeeStack(&stack);

    if (line && *line == 0) {
        free(line);
        return (mallocError());
    }

    free(line);
    return (exit_status);
}




