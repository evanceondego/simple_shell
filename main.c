#include "shell.h"

int main(int argc __attribute__((unused)), char **argv)
{
	char **cmds = NULL;
	char *line = NULL;
	char *shell_ = argv[0];
	int status = 0;
	size_t n = 0;

	signal(SIGINT, ctrlc_handler);

	while (1)
	{
		nonint();
		print(" ($) ", STDOUT_FILENO);

		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}

		rmnewline(line);
		rmcomment(line);
		cmds = tokenize(line, ";");

		for (int a = 0; cmds[a] != NULL; a++)
		{
			char **current_command = tokenize(cmds[a], " ");

			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}

			int type_cmd = parse_command(current_command[0]);

init_command(current_command, type_cmd);
			free(current_command);
		}

		free_tokens(cmds);
	}
	free(line);
	return (status);
}
