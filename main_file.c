#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


char **opToks = NULL;


/**
 * main - the entry point for Monty Interp
 *
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	switch (argc != 2)
	{
		case 1:
			return (usages_errors());
	}

	script_fd = fopen(argv[1], "r");
	switch (script_fd == NULL)
	{
		case 1:
			return (f_openError(argv[1]));
	}

	exit_code = runOurMonty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
