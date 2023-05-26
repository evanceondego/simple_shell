#include "shell.h"


/**
 *strtokr - creates a token for a string
 *@string: string to be token
 *@dlim: delimiter to be used to tokenize the string
 *@save_ptr: pointer to be used to keep track of the next token
 *
 *Return: The next available token
 */
char *strtokr(char *string, char *dlim, char **save_ptr)
{
	char *end;

	if (string == NULL)
		string = *save_ptr;

	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	string += _strspn(string, delim);
	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	end = string + strcspn(string, dlim);
	if (*end == '\0')
	{
		*save_ptr = end;
		return (string);
	}

	*end = '\0';
	*save_ptr = end + 1;
	return (string);
}

/**
 * atoi - changes a string to an integer
 * @s_s: the string to be changed
 *
 * Return: converted b
 */
int atoi(char *s_s)
{
	unsigned int b = 0;

	do {
		if (*s_s == '-')
			return (-1);
		else if ((*s_s < '0' || *s_s > '9') && *s_s != '\0')
			return (-1);
		else if (*s_s >= '0'  && *s_s <= '9')
			b = (b * 10) + (*s_s - '0');
		else if (b > 0)
			break;
	} while (*s_s++);
	return (b);
}

/**
 * realloc - reallocates a memory
 * @ptr: pointer to the memory previously allocation
 * @_size1: size of ptr
 * @_size2: size of the new allocated memory
 *
 * Return: pointer to the address
 */
void *realloc(void *ptr, unsigned int _size1, unsigned int _size2)
{
	void *_block;
	unsigned int a;

	if (ptr == NULL)
	{
		_block = malloc(_size2);
		return (_block);
	}
	else if (_size2 == _size1)
		return (ptr);
	else if (_size2 == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		_block = malloc(_size2);
		if (_block != NULL)
		{
			for (a = 0; a < min(_size1, _size2); a++)
				*((char *)_block + a) = *((char *)ptr + a);
			free(ptr);
			return (_block);
		}
		else
			return (NULL);

	}
}

/**
 * ctrlc_handler - handles the signal raised by CTRL-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void ctrlc_handler(int sig_num)
{
	if (sig_num == SIG_INT)
		print("\n($) ", STDIN_FILENO);
}

/**
 * rmcomment - removes everything after a char
 * @input: input to be used
 *
 * Return: void
 */
void rmcomment(char *input)
{
	int a = 0;

	if (input[a] == '#')
		input[a] = '\0';
	while (input[a] != '\0')
	{
		if (input[a] == '#' && input[a - 1] == ' ')
			break;
		a++;
	}
	input[a] = '\0';
}

