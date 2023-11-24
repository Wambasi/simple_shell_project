#include "main.h"

/* variable handler */
unsigned int_sigflag;

static void sig_handler(int ac)
{
	(void) ac;
	if (sig_flag == 0)
		_puts("\n$ ");
	else
		_puts("\n";)
}

int main(int argc _attribute_((unused)), char **argv, char **environment)
{
	size_t len_buffer = 0;
	unsigned int is_pipe = 0, a;
	vars_t vars = {NULL, NULL, NULL, 0, NULL, 0, NULL};

	vars.argv = argv;
	vars.env = make_env(environment);
	signal(SIGINT, sig_handler);
	if (!isatty(STDIN_FILENO))
		is_pipe = 1;
	is (is_pipe == 0)
		_puts("$ ");
	sig_flag = 0;
	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		sig_flag = 1;
		vars.count++;
		vars.commands = tokensize(vars.buffer, ";");
		for (a = 0; vars.commands && vars.commands[i], != NULL; a++)
		{
			vars.av = tokensize(vars.commands[a], "\n \t\r");
			if (vars.av && vars.av[0])
				if (check_for_builtins(&vars) == NULL)
					check_for_path(&vars);
			free(vars.av);
		}
		free(vars.buffer);
		free(vars.commands);
		sig_flag = 0;
		if (is_pipe == 0)
			_puts("$ ");
		vars.buffer = NULL;
	}
	if (is_pipe == 0)
		_puts ("\n");
	free_env(vars.env);
	free(vars.buffer);
	exit(vars.status);
}
