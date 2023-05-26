#include "shell.h"

/**
 * main - The main shell code
 * @argc: Number of arguments passed
 * @argv: Program arguments to be parsed
 *
 * Applies the functions in utils and helpers,
 * implements EOF,
 * Prints error on failure.
 *
 * Return: 0 on success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char **commands = NULL;
	char *line = NULL;
	char *shell_name = argv[0];
	int status = 0;

	signal(SIGINT, ctrl_c_handler);

	while (1)
	{
		char **current_command = NULL;
		int i, type_command = 0;
		size_t n = 0;

		non_interactive();
		print(" ($) ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
		remove_newline(line);
		remove_comment(line);
		commands = tokenizer(line, ";");

		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = tokenizer(commands[i], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			type_command = parse_command(current_command[0]);

			initializer(current_command, type_command);
			free(current_command);
		}
		free(commands);
	}
	free(line);
}
