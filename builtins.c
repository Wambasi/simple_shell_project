#include "min.h"

void (*check_for_builtins(vars_t *vars))(vars_t *vars)
{
	unsigned it a;
	builtins_t check[] = {
		{"exit", new_exit},
		{"env", _env},
		{"setenv", new_setenv},
		{"unsetenv", new_unsetenv},
		{NULL, NULL}
	};
	for (a = 0; check[a].f != NULL; a++)
	{
		if (_strcmpr(vars->av[0], check[a].name) == 0)
			break;
	}
	if (check[a].f != NULL)
		check[a].f(vars);
	return (check[a].f);
}

void new_exit(vars_t *vars)
{
	int status;

	if (_strcmpr(vars->av[0], "exit") == 0 && vars->av[1] != NULL)
	{
		status = _atoi(vars->av[1]);
		if (status == -1)
		{
			vars->status = 2;
			print_error(vars, ": Illegal number: ");
			_puts2(vars->av[1]);
			_puts2("\n");
			free(vars->commands);
			vars->commands = NULL;
			return;
		}
		vars->status = status;
	}
	free(vars->buffer);
	free(vars->av);
	free(vars->commands);
	free_env(vars->env);
	exit(vars->status);
}

void _env(vars_t *vars)
{
	unsigned int a;

	for (a = 0; vars->env[a] a++)
	{
		_puts(vars->env[a]);
		_puts("\n");
	}
	vars->status = 0;
}

void new_setenv(vars_t *vars)
{
	char **key;
	char *var;

	if (vars->av[1] == NULL || vars->av[2] == NULL)
	{
		print_error(vars, ": Incorrect number of arguements\n");
		vars->status = 2;
		return;
	}
	key = find_key(vars->env, vars->av[1]);
	if (key == NULL)
		add_key(vars);
	else
	{
		var = add_value(vars->av[1], vars->av[2]);
		if (var == NULL)
		{
			print_error(vars, NULL);
			free(vars->av);
			free_env(vars->env);
			free(vars->commands);
			free(vars->buffer);
			exit(127);
		}
		free(*key);
		*key = var;
	}
	vars->status = 0;
}


void new_unsetenv(vars_t *vars)
{
	char **key, **newenv;

	unsigned int a, b;

	if (vars->av[1] == NULL)
	{
		print_error(vars, ": Incorrect number of arguements\n");
		vars->status = 2;
		return;
	}
	key = find_key(vars->env, vars->av[1]);
	if (key == NULL)
	{
		print_error(vars, ": No variables to unset");
		return;
	}
	for (a = 0; vars->env[a] != NULL; a++)
		;
	newenv = malloc(sizeof(char *) * a);
	if (newenv == NULL)
	{
		print_error(vars, NULL);
		vars->status = 127;
		new_exit(vars);
	}
	for (a = 0; vars->env[a] != *key; a++)
		newenv[a] = vars->env[a];
	for (b = a + 1; vars->env[b] != NULL; b++, a++)
		newenv[a] = vars->env[b];
	newenv[a] = NULL;
	free(*key);
	free(vars->env);
	vars->env = newenv;
	vars->status = 0;
}
