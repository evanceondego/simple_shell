#include "shell.h"

/**
 * initializer - starts executing everything
 * @current_command: try to check current token
 * @type_command: parse token
 *
 * Return: void function
 */
void initializer(char **current_command, int type_command)
{
	pid_t pid;

	if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
	{
		pid = fork();
		if (pid == 0)
		execute_command(current_command, type_command);
	else if (pid > 0)
	{
		int status;

		waitpid(pid, &status, 0);
		status >>= 8;
	}
	else
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	}
	else
	execute_command(current_command, type_command);
}
