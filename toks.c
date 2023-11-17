#include "monty.h"


/**
 * setOpTokError - Sets last element of opToks to be an error code.
 * @error_code: Integer to store as a string in opToks.
 */
void setOpTokError(int error_code) {
	int toksLen = 0, ii = 0;
	char *exitStr = NULL;
	char **newToks = NULL;

	switch (!(opToks)) {
		case 1:
			mallocError();
			return;
	}

	toksLen = tokenArrLen();
	newToks = malloc(sizeof(char *) * (toksLen + 2));
	switch (!newToks) {
		case 1:
			mallocError();
			return;
	}

	while (ii < toksLen) {
		newToks[ii] = opToks[ii];
		ii++;
	}

	exitStr = get_int(error_code);
	switch (!exitStr) {
		case 1:
			free(newToks);
			mallocError();
			return;
	}

	newToks[ii++] = exitStr;
	newToks[ii] = NULL;
	free(opToks);
	opToks = newToks;
}
