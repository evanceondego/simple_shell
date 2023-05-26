#include "shell.h"

/**
 * Description-the extended functions for main.c
 */


/**
 * parse_cmd - this finds the type of command
 *@cmd -determne the command to be parsed
 * Return: command type
 */

int parse_cmd(char *cmd)
{
	int a;
	char *int_cmd_2[] = {"envi", "exit", NULL};
	char *path = NULL;

	for (a = 0; cmd[a] != '\0'; a++)
	{
		if (cmd[a] == '/')
			return (EXTE_CMD_1);
	}
	for (a = 0; *int_cmd_2[a] != NULL; a++)
	{
		if (_strcmp(cmd, *int_cmd_2[a]) == 0)
			return (INT_CMD_2);
	}
	/* @checkpath - checks if a command is found in the PATH */
	path = checkpath(cmd);
	if (path != NULL)
	{
		free(path);
		return (PATH_CMD);
	}

	return (INV_CMD_1);
}

/**
 * execute_command - executes a command based on it's type
 * @tokenized_command: tokenized form of the command (ls -l == {ls, -l, NULL})
 * @command_type: type of the command
 *
 * Return: void
 */
void execute_command(char **tokenized_command, int command_type)
{
	void (*func)(char **command);

	if (command_type == EXTE_CMD_1)
	{
		if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == PATH_CMD_3)
	{
		if (execve(check_path(tokenized_command[0]), tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == INT_CMD_2)
	{
		func = getfunc(tokenized_command[0]);
		func(tokenized_command);
	}
	if (command_type == INV_CMD_1)
	{
		print(shell_, STDERR_FILENO);
		print(": 1: ", STDERR_FILENO);
		print(tokenized_command[0], STDERR_FILENO);
		print(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * checkpath - checks if a command is found in the PATH
 * @cmd: command to be used
 *
 * Return: path where the command
 */
char *checkpath(char *cmd)
{
	char **patharray = NULL;
	char *temp, *temp2, *path_cpy;
	char *path = getenv("PATH");
	int a;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	pathcpy = malloc(sizeof(*path_cpy) * (strlen(path) + 1));
	strcpy(path, path_cpy);
	path_array = tokenizer(path_cpy, ":");
	for (a = 0; path_array[a] != NULL; a++)
	{
		temp2 = astrcat(path_array[a], "/");
		temp = astrcat(temp2, command);
		if (access(temp, F_OK) == 0)
		{
			free(temp2);
			free(patharray);
			free(pathcpy);
			return (temp);
		}
		free(temp);
		free(temp2);
	}
	free(pathcpy);
	free(patharray);
	return (NULL);
}

/**
 * getfunc - retrieves a function based on the command given and a mapping
 * @cmd: string to check against the mapping
 *
 * Return: pointer to the proper function, or null on fail
 */
void (*getfunc(char *cmd))(char **)
{
	int a;
	function_map mapping[] = {
		{"envi", envi}, {"exit", quit}
	};

	for (a = 0; a < 2; a++)
	{
		if (strcmp(command, mapping[a].command_name) == 0)
			return (mapping[a].func);
	}
	return (NULL);
}

/**
 * getenv - gets the value of an environment
 * @name: name of the environment variable
 *
 * Return: the value of the variable as a string
 */
char *getenv(char *name)
{
	char **myenviron;
	char *pairptr;
	char *namecpy;

	for (myenviron = environ; *myenviron != NULL; myenviron++)
	{
		for (pairptr = *myenviron, namecpy = name;
		     *pairptr == *namecpy; pairptr++, namecpy++)
		{
			if (*pairptr == '=')
				break;
		}
		if ((*pairptr == '=') && (*namecpy == '\0'))
			return (pairptr + 1);
	}
	return (NULL);
}
