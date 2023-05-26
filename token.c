#include "shell.h"

/**
 * initializer - starts executing everything
 * @current_command: try to check the current token
 * @type_cmd: token type
 *
 * Return: void
 */

void initializer(char **current_command, int type_cmd)
{
	pidt TID;

	if (type_cmd == EXTE_CMD_1 || type_command == PATH_CMD_3)
	{
		TID = fork();
		if (TID == 0)
			execute_command(current_command, type_cmd);
		else
		{
			waitpidt(TID, &status, 0);
			status >>= 8;
		}
	}
	else
		execute_command(current_command, type_cmd);
}
