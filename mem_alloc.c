#include "main.h"

char **_realloc(char **ptr, size_t *size)
{
	char **new;
	size_t a;

	new = malloc(sizeof(char *) * ((*size) + 10));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (a = 0; a < (*size); a++)
	{
		new[a] = ptr[a];
	}
	*size += 10;
	free(ptr);
	return (new);
}
