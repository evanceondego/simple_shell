#include "shell.h"

/**
 *strcmp - this will compare two strings
 *@f_str: first string to be compared
 *@s_str: second string to be compared
 *
 * Return: subb between two strings
 */

int strcmp(char *f_str, char *s_str)
{
	int a = 0;

	while (f_str[a] != '\0')
	{
		if (f_str[a] != s_str[a])
			break;
		a++;
	}
	return (f_str[a] - s_str[a]);
}

/**
 *strcat - concatenates the two strings
 *@dest: string to be concatenated
 *@src:  string to concatenate
 *
 * Return: address
 */
char *strcat(char *dest, char *src)
{
	char *newstring =  NULL;
	int len_dest = strlen(dest);
	int len_src = strlen(src);

	newstring = malloc(sizeof(*newstring) * (len_dest + len_src + 1));
	strcpy(dest, newstring);
	strcpy(src, newstring + len_dest);
	newstring[len_dest + len_src] = '\0';
	return (newstring);
}

/**
 *strspn - gets the length of a prefix
 *@s_str1: string to be searched
 *@s_str2: string to be used
 *
 *Return: number of bytes
 */

int strspn(char *s_str1, char *s_str2)
{
	int a = 0;
	int match = 0;

	while (s_str1[a] != '\0')
	{
		if (strchr(s_str2, s_str1[a]) == NULL)
			break;
		match++;
		a++;
	}
	return (match);
}
/**
 *strcspn - computes segment of str1 which consists of char not in str2
 *@s_str1: string to be searched
 *@s_str2: string to be used
 *
 *Return:char in str1 exists in str2
 */


int strcspn(char *s_str1, char *s_str2)
{
	int len = 0, a;

	for (a = 0; s_str1[a] != '\0'; a++)
	{
		if (strchr(s_str2, s_str1[a]) != NULL)
			break;
		len++;
	}
	return (len);
}

/**
 *strchr - locates a char in a string
 *@_str: string to be searched
 *@c: char to be checked
 *
 *Return: pointer
 */
char *strchr(char *_str, char c)
{
	int i = 0;

	for (; _str[i] != c && _str[i] != '\0'; i++)
		;
	if (_str[i] == c)
		return (_str + i);
	else
		return (NULL);
}
