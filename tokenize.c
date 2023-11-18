#include <stdlib.h>


char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);


/**
 * strtow - takes a string and seperates its wordds
 *
 * @str: string to seperate into wordds
 * @delims: delimitors to use to delimit wordds
 *
 * Return: 2D array of pointers to each word
 */
char **strtow(char *str, char *delims)
{
	char **wordds = NULL;
	int wcc, word_len, nn, i = 0;

	switch (str == NULL || !*str)
	{
		case 1:
			return (NULL);
	}

	wcc = get_word_count(str, delims);

	switch (wcc == 0)
	{
		case 1:
			return (NULL);
	}

	wordds = malloc((wcc + 1) * sizeof(char *));
	if (wordds == NULL)
		return (NULL);

	while (i < wcc)
	{
		word_len = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		wordds[i] = malloc((word_len + 1) * sizeof(char));
		if (wordds[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(wordds[i]);
			}
			free(wordds);
			return (NULL);
		}
		nn = 0;
		while (nn < word_len)
		{
			wordds[i][nn] = *(str + nn);
			nn++;
		}
		wordds[i][nn] = '\0'; /* set end of str */
		str = get_next_word(str, delims);
		i++;
	}
	wordds[i] = NULL; /* last element is null for iteration */
	return (wordds);
}


/**
 * is_delim - checks if stream has delimitor char
 *
 * @ch: character in stream
 *
 * @delims: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */
int is_delim(char ch, char *delims)
{
	int ii = 0;

	while (delims[ii])
	{
		if (delims[ii] == ch)
			return (1);
		ii++;
	}
	return (0);
}


/**
 * get_word_length - gets the word length of cur word in str
 *
 * @str: string to get word length from current word
 * @delims: delimitors to use to delimit wordds
 *
 * Return: word length of current word
 */
int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, ii = 0;

	while (*(str + ii))
	{
		if (is_delim(str[ii], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[ii], delims))
			break;
		ii++;
	}
	return (wLen);
}


/**
 * get_word_count - gets the word count of a string
 *
 * @str: string to get word count from
 * @delims: delimitors to use to delimit wordds
 *
 * Return: the word count of the string
 */

int get_word_count(char *str, char *delims)
{
	int wcc = 0, pending = 1, ii = 0;

	while (*(str + ii))
	{
		if (is_delim(str[ii], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wcc++;
		}
		ii++;
	}
	return (wcc);
}



/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimitors to use to delimit wordds
 *
 * Return: pointer to first char of next word
 */
char *get_next_word(char *str, char *delims)
{
	int pending = 0, ii = 0;

	while (*(str + ii))
	{
		if (is_delim(str[ii], delims))
			pending = 1;
		else if (pending)
			break;
		ii++;
	}
	return (str + ii);
}
