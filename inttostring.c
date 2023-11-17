#include <stdlib.h>


char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base, char *buff, int buff_size);


/**
 * get_int - gets a character pointer to new string containing int
 * @num: number to convert to string
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_int(int num)
{
    unsigned int tempo;
    int ourLength = 0;
    long firstNum = 0;
    char *rett;


    tempo = _abs(num);
    ourLength = get_numbase_len(tempo, 10);


    if (num < 0 || firstNum < 0)
        ourLength++; /* negative sign */
    rett = malloc(ourLength + 1); /* create new string */
    if (!rett)
        return (NULL);


    fill_numbase_buff(tempo, 10, rett, ourLength);
    if (num < 0 || firstNum < 0)
        rett[0] = '-';


    return (rett);
}


/**
 * _abs - gets the absolute value of an integer
 * @i: integer to get absolute value of
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int _abs(int i)
{
    if (i < 0)
        return (-(unsigned int)i);
    return ((unsigned int)i);
}


/**
 * get_numbase_len - gets ourLength of buffer needed for an unsigned int
 * @num: number to get ourLength needed for
 * @base: base of number representation used by buffer
 *
 * Return: integer containing ourLength of buffer needed (doesn't contain null bt)
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
    int lenn = 1; /* all numbers contain atleast one digit */


    while (num > base - 1)
    {
        lenn++;
        num /= base;
    }
    return (lenn);
}


/**
 * fill_numbase_buff - fills buffer with correct numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
            char *buff, int buff_size)
{
    int remm, i = buff_size - 1;


    buff[buff_size] = '\0';
    while (i >= 0)
    {
        remm = num % base;
        if (remm > 9) /* return lowercase ascii val representation */
            buff[i] = remm + 87; /* 10 will be a, 11 = b, ... */
        else
            buff[i] = remm + '0';
        num /= base;
        i--;
    }
}


