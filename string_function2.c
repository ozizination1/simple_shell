#include "shell.h"

char *_strchr(char *str, char c);
int _strspn(char *str, char *accept);
int _strncmp(const char *str1, const char *str2, size_t n);

/**
 * _strchr - Locates a character in a string.
 * @str: The string to be searched.
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

/**
 * _strspn - Finds the length of the prefix of str1 with characters from str2.
 * @str: String to be scanned
 * @accept: string containing the list of characters to match in str
 *
 * Return: the number of characters in the initial segment of
 *	str1 which consist only of characters from str2.
 */

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

/**
 * _strncmp - Compares at most the first n bytes of str1 and str2.
 * @str1: String 1
 * @str2: String 2
 * @n: The maximum number of characters to be compared
 *
 * Return: < 0 then it indicates str1 is less than str2.
 *	> 0 then it indicates str2 is less than str1.
 *	= 0 then it indicates str1 is equal to str2.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; str1[i] && str2[i] && i < n; i++)
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
