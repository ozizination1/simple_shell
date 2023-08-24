#include "shell.h"

char *_strchr(char *str, char c);
int _strspn(char *str, char *accept);
int _strncmp(const char *str1, const char *str2, size_t n);

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: If c is found - a pointer to the first occurence.
 *         If c is not found - NULL.
 */

char *_strchr(char *str, char c)
{
	int i;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
			return (str + i);
	}
	return (NULL);
}

int _strspn(char *str, char *accept)
{
	int bytes = 0;
	size_t i = 0;

	while (*str != '\0')
	{
		for (i = 0; accept[i]; i++)
		{
			if (*str == accept[i])
			{
				bytes++;
				break;
			}
		}
		if (!accept[i])
			break;

		str++;
	}
	return (bytes);
}


int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; str1[i] && str2[i] && i<n; i++)
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		else if (str1[i] < str2[i])
			return (str1[i] - str2[i]);
	}
	if (i == n)
		return (0);
	else
		return ((int)(str1[i] - str2[i]));
}
