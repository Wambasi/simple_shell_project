#include "main.h"

char **make_env(char **env)
{
	char **newenv = NULL;
	size_t a;

	for (a = 0; env[a] != NULL; a++)
		;
	newenv = malloc(sizeof(char *) * (a + 1));
	if (newenv == NULL)
	{
		perror("Fatal error");
		exit(1);
	}
	for (a = 0; env[a] != NULL; a++)
		newenv[a] = _strdup(env[a]);
	newenv[a] = NULL;
	return (newenv);
}

void free_env(char **env)
{
	unsigned int a;

	for (a = 0; env[a] != NULL; a++)
		free(env[a]);
	free(env);
}
