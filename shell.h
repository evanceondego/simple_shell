#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 * Struct map - maps a command name to a function
 *
 * @command_name: Name of the command
 * @func: The function that executes the command
 */
typedef struct map
{
    char *command_name;
    void (*func)(char **command);
} function_map;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

/* Helper1 */
void print(char *, int);
char **tokenizer(char *, char *);
void remove_newline(char *);
int _strlen(char *);
void _strcpy(char *, char *);

/* Helper2*/
int _strcmp(char *, char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);
int _strcspn(char *, char *);
char *_strchr(char *, char);

/* helper3 */
char *_strtok_r(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *, unsigned int, unsigned int);
void ctrl_c_handler(int);
void remove_comment(char *);

/* token3 */
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);

/* Built*/
void env(char **);
void quit(char **);

/* Main */
void non_interactive(void);
void initializer(char **, int);

#endif /* SHELL_H */

