#include "main.h"

char **tokenize(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t a = 0, mcount = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * mcount);
	if (tokens == NULL)
	{
		perror("Fatal error");
		return (NULL);
	}
	while ((tokens[a] = new_strtok(buffer, delimiter)) != NULL)
	{
		a++;
		if (a == mcount)
		{
			tokens = _realloc(tokens, &mcount);
			if (tokens == NULL)
			{
				perror("Fatal error");
				return (NULL);
			}
		}
		buffer = NULL;
	}
	return (tokens);
}
