#include "main.h"

void print_error(vars_t *vars, char *msg)
{
	char *count;

	_puts2(vars->argv[0]);
	_puts2(": ");
	count - _uitoa(vars->count);
	_puts2(count);
	free(count);
	_puts2(": ");
	_puts2(vrs->av[0]);
	if (msg)
	{
		_puts2(msg);
	}
	else
		perror("");
}

void _puts2(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDERR_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal error");
		exit(1);
	}
}

char *_uitoa(unsigned int count)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count;
	for (digits = 0; tmp != 0; digit++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}
	return (numstr);
}
