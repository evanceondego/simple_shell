#include "shell.h"

int main(int argc __attribute__((unused)), char **argv)
{
	char **commands = NULL;
	char *line = NULL;
	char *shell_name = argv[0];
	int status = 0;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);

	while (1)
	{
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

	for (int i = 0; commands[i] != NULL; i++)
	{
	char **current_command = tokenizer(commands[i], " ");

	if (current_command[0] == NULL)
	{
		free(current_command);
		break;
	}
	int type_command = parse_command(current_command[0]);

	/* initializer -   */
		initializer(current_command, type_command);
		free(current_command);
	}
		free(commands);
	}
	free(line);
}
