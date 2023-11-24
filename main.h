#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <signal.h>

/**
 * @env: environment for variables
 * @argv: arguements when opening the simple shell
 * @status: exiting status
 * @commands: execution commands
 * @count: count for commands entered
 */
typedef struct variables
{
	char **av;
	char *buffer;
	char **env;
	char **argv;
	size_t count;
	int status;
	char **command;
}
vars_t;
typedef struct builtins
{
	void (*f)(vars_t *);
	char *name;
}
builtins_t;
char **make_env(char **env);
void free_env(char **env);

size_t _puts(char *str);
char *_strdup(char *strtodup);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strcat(char *strc1, char *strc2);
unsigned int _strlen(char *str);

char **tokenize(char *buffer, char *delimiter);
char **_realloc(char **ptr, size_t *size);
char *new_strtok(char *str, const char *delim);

void (*check_for_builtins(var_t *vars))(vars_t *vars);
void new_exit(vars_t *vars);
void _env(vars_t *vars);
void new_setenv(vars_t *vars);
void new_unsetenv(vars_t *vars);

void add_key(vars_t *vars);
char **find_key(char **env, char *key);
char *add_value(char *key, char *value);
int _atoi(char *str);

void check_for_path(vars_t *vars);
int path_execute(char *command, vars_t *vars);
char *find_path(char **env);
int execute_cwd(vars_t *vars);
int check_for_dir(char *str);

void print_error(vars_t *vars, char *msg);
void _puts2(char *str);
char *uitoa(unsigned int count);


#endif
/* _MAIN_H_ */
