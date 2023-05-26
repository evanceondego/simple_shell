#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*const*/
#define EXTE_CMD_1
#define INT_CMD_2
#define PATH_CMD_3
#define INV_CMD_1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *mapping - a struct that maps a command name to a function
 *@cmdname - this is the name of the cmdname
 *@fun: the function that executes the command
 */

typedef mapping
{
	char *cmdname;
	void (*fun)(char **cmd);
} func_mapping;

extern char **environ;
extern char *line;
extern char **cmds;
extern char *shellname;
extern int status;
/*helper1*/
void print(char *, int);
char **token_izer(char *, char *);
void rmnewline(char *);
int strlen(char *);
void strcpy(char *, char *);

/*helper2*/
int strcmp(char *, char *);
char *strcat(char *, char *);
int strspn(char *, char *);
int strcspn(char *, char *);
char *strchr(char *, char);

/*helper3*/
char *strtokr(char *, char *, char **);
int atoi(char *);
void *realloc(void *ptr, unsigned int oldsize, unsigned int newsize);
void ctrlc_handle(int);
void rmcomment(char *);

/*utils*/
int parsecmd(char *);
void exe_cmd(char **, int);
char *check_path(char *);
void (*get_fun(char *))(char **);
char *getenv(char *);

/*built*/
void envi(char **);
void exit(char **);
/*main*/
extern void noninteract(void);
extern void initializer(char **curr_cmd, int type_cmd);
#endif

