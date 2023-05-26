#include "shell.h"

/**
 *envi -outputs present envi
 *tokencmd__attr__((unused)): the token command attribute
 *
 *Return: void
 */

void envi(char **tokencmd__attr__((unused)))
{
	int a;

	for (a = 0; environ[a] != NULL; a++)
	{
		print(environ[a], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 * exit - exits the shell
 * @tokencmd: the token command entered
 *
 * Return: void
 */
void exit(char **tokencmd)
{
	int token_num = 0, arg;

	for (; token_num[token_num] != NULL; token_num++)
		;
	if (token_num == 1)
	{
		free(tokencmd);
		free(line);
		free(cmds);
		exit(status);
	}
	else if (token_num == 2)
	{
		arg = atoi(tokencmd[1]);
		if (arg == -1)
	{
		print(shell_name, STDERR_FILENO);
		print(": 1: exit: Illegal number: ", STDERR_FILENO);
		print(tokencmd[1], STDERR_FILENO);
		print("\n", STDERR_FILENO);
		status = 2;
	}
	else
	{
		free(line);
		free(tokencmd);
		free(cmds);
		exit(arg);
	}
	}
	else
	print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
