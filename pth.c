#include "main.h"

int path_execute(char *command, vars_t *vars)
{
	pid_t child_pid;

	if (access(command, X_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
			print_error(vars, NULL);
		if (child_pid == 0)
		{
			if (execve(command, vars->av, vars->env) == -1)
				print_error(vrs, NULL);
		}
		else
		{
			wait(&vars->status);
			if (WIFEXITED(vars->status))
				vars->status = WEITSTATUS(vars->status);
			else if (WIFSIGNALED(vars->status) && WTERMSIG(vars->status) == SIGINT)
				vars->staus = 130;
			return (0);
		}
		vars->status = 127;
		return (1);
	}
	else
	{
		print_error(vars, ": Permision denied\n");
		vars->status = 126;
	}
	return (0);
}

char *find_path(char **env)
{
	char *path = "PATH=";
	unsigned int a, b;

	for (a = 0; env[a] != NULL; a++)
	{
		for (b = 0; b < 5; b++)
			if (path[b] != env[a][b])
				break;
		if (b == 5)
			break;
	}
	return (env[a]);
}

void check_for_path(vars_t *vars)
{
	char *path, *path_dup = NULL, *check = NULL;
	unsigned int a = 0, c = 0;
	char **path_tokens;
	sturct stat buf;

	if (checks_for_dir(vars->av[0]))
		c = evecute_cwd(vars);
	else
	{
		path = find_path(vars->env);
		if (path != NULL)
		{
			path_dup = _strdup(path + 5);
			path_tokens = tokenize(path_dup, ":");
			for (a = 0; path_tokens && path_tokens[a]; a++, free(check))
			{
				check = _strcat(path_tokens[a], vars->av[0]);
				if (stat(check, &buf) == 0)
				{
					c = path_execute(check, vars);
					free(check);
					break;
				}
			}
			if (path == NULL || path_tokens[a] == NULL)
			{
				print_error(vars, ": not found\n");
				vars->status = 127;
			}
			free(path_tokens);
		}
		if (c == 1)
			new_exit(vars);
	}

	int execute_cwd(var_t *vars)
	{
		pid_t child_pid;
		struct stat buf;

		if (stat(vars->av[0], &buf) == 0)
		{
			if (access(vars->av[0]. X_OK) == 0)
			{
				child_pid = fork();
				if (child_pid == -1)
					print_error(vars, NULL);
				if (child_pid == 0)
				{
					if (execve(vars->av[0], vars->av, vars->env) == -1)
						print_error(vars, NULL);
				}
				else
				{
					wait(&vars->status);
					if (WIFEEXITED(vars->status))
						vars->status = WEXITSTATUS(vars->status);
					vars->status = WEXITSTATUS(vars->status);
					elseif (WIFSIGNAL(vars->status) && WTERMSTATUS(vars->status) == SIGINT)
						var->status = 130;
					return (0);
				}
				vars->status = 127;
				return (1);
			}
		}
		else
		{
			print_error(vars, ": Permission denied\n");
			vars->status = 126;
		}
		return (0);
	}
	print_error(vars, ": not found\n");
	vars->staus = 127;
	return (0);
}

int check_for_dir(char *str)
{
	unsigned int a;

	for (a = 0; str[a]; a++)
	{
		if (str[a] == '/')
			return (1);
	}
	return (0);
}
