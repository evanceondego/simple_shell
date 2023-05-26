#include "shell.h"

/**
 * token_izer - creates the token
*and input and store it in an array
 *@inputstring: input to be parsed
 *@dlim: delimiter to be used, needs to be one character string
 *
 *Return: array of tokens
 */

char **token_izer(char *inputstring, char *dlim)
{
	int delim_num = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = strtokr(inputstring, dlim, &save_ptr);

	while (token != NULL)
	{
		av = realloc(av, sizeof(*av) * delim_num, sizeof(*av) * (delim_num + 1));
		av[delim_num] = token;
		token = strtokr(NULL, dlim, &save_ptr);
		delim_num++;
	}

	av = realloc(av, sizeof(*av) * delim_num, sizeof(*av) * (delim_num + 1));
	av[delim_num] = NULL;

	return (av);
}
/**
 *print - prints a string to stdout
 *@string: string to be printed
 *@stream: stream to print out to
 *
 *Return: void, NULL
 */
void print(char *string, int stream)
{
	int a = 0;

	for (; string[a] != '\0'; a++)
		write(stream, &string[a], 1);
}

/**
 *rmnewline - removes the new line from a string
 *@str: string to be used
 *
 *
 *Return: void
 */

void rmnewline(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		if (str[a] == '\n')
		break;
		a++;
	}
	str[a] = '\0';
}
/**
 *strcpy - copies a string to another buffer
 *@src: source to copy from
 *@des: destination to copy
*
* Return: void
 */

void strcpy(char *src, char *des)
{
	int a = 0;

	for (; src[a] != '\0'; a++)
		des[a] = src[a];
	des[a] = '\0';
}

/**
 *strlen - counts string length
 *@string: string to be counted
 *
 * Return: length of the string
 */

int strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
	;
	return (len);
}
