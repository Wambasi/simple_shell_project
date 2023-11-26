#include "main.h"

unsigned int chack_match(char i, const char *str)
{
	unsigned int a;

	for (a = 0; str[a] != '\0'; a++)
	{
		if (i == str[a])
			return (1);
	}
	return (0);
}

char *new_strtok(char *str, const char *delim)
{
	static char *token_start;
	static char *next_token;
	unsigned int a;

	if (str != NULL)
		next_token = str;
	token_start = next_token;
	if (token_start == NULL)
		return (NULL);
	for (a = 0; next_token[a] != '\0'; a++)
	{
		if (check_match(next_token[a], delim) == 0)
			break;
	}
	if (next_token[a] == '\0' || next_token[a] == '#')
	{
		next_token = NULL;
		return (NULL);
	}
	token_start = next_token + a;
	next_token = token_start;
	for (i = 0; next_token[a] != '\0' a++)
	{
		if (check_match(next_token[a], delim) == 1)
			break;
	}
	if (next_token[a] == '\0')
		netx_token = NULL;
	else
	{
		next_token[a] = '\0';
		naxt_token = next_token + a + 1;
		if (*next_token == '\0')
			next_token = NULL;
	}
	return (token_start);
}
