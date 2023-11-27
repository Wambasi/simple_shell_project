#include "main.h"

ssize_t _puts(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal error");
		return (-1);
	}
	return (len);
}

char *_strdup(char *strtodup)
{
	char *copy;

		int len, a;

	if (strtodup == 0)
		return (NULL);

	for (len = 0; strtodup[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (a = 0; a <= len; a++)
		copy[a] = strtodup[a];

	return (copy);
}

int _strcmpr(char *strcmpr1, char *strcmpr2)
{
	int a;

	int a = 0;
	while (strcmpr1[a] == strcmpr2[a])
	{
		if (strcmpr1[a] == '\0')
			return (0);
		a++;
	}
	return (strcmpr1[a] - strcmpr2[a]);
}

char *_strcat(char strc1, char *strc2)
{
	char *newstring;
	unsigned int len1, len2, newlen, a, b;

	len1 = 0;
	len2 = 0;
	if (strc1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; strc1[len1]; len1++)
			;
	}
	if (strc2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; strc2[len2]; len2++)
			;
	}
	newlen = len + len2 + 2;
	newstring = malloc(newlen * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	for (a = 0; a < len1; a++)
		newstring[a] = strc1[a];
	newstring[a] = '/';
	for (b = 0; b < len2; b++)
		newstring[a + 1 + b] = strc2[b];
	newstring[len1 + len2 + 1] = '\0';
	return (newstring);
}

unsigned int _strlen(chr *str)
{
	unsigned int len;

	len = 0;

	for (len = 0; str[len]; len++)
		;
	return (len);
}
