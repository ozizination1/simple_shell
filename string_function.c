#include "shell.h"

int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
size_t strlen(const char *str);
char *_strncat(char *dest, const char *src, size_t n);


int _strcmp(const char *s1, const char *s2)
{
	int op = 0;

	while ((*s1 != '\0') && (s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			op = (*s1 - *s2);
			return (op);
		}
		s1++;
		s2++;
	}
}


size_t _strlen(const char str)
{
	size_t i = 0;

	while (*str)
	{
		i++;
		str++;
	}

	return (i);
}

char *_strncat(char *dest, const char *src, size_t n)
{
	int i = 0, j = 0;

	while (dest[j] != '\0')
	{
		j++;
	}
	for (; src[i] != '\0' && i < n; i++)
	{
		dest[j] = src[i];
		j++;
	}
	dest[j] = '\0';

	return (dest);
}

char *_strcat(char *dest, const char *src)
{
	int i = 0, j = 0;

	while (dest[j] != '\0')
	{
		j++;
	}
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';

	return (dest);
}

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (src == NULL)
		return (NULL);

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
