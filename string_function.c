#include "shell.h"

int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int  _strlen(const char *str);
char *_strncat(char *dest, const char *src, size_t n);

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 = s2
 *         Negative byte difference if s1 < s2
 */

int _strcmp(const char *s1, const char *s2)
{
	int op = 0;

	while ((*s1 != '\0') && (*s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			op = (*s1 - *s2);
			return (op);
		}
			s1++;
			s2++;
	}
	return (0);
}

/**
 * _strlen - Returns the length of a string.
 * @str: A pointer to the characters string.
 *
 * Return: The length of the character string.
 */

int _strlen(const char *str)
{
	int i = 0;

	while (*str)
	{
		i++;
		str++;
	}

	return (i);
}

/**
 * _strncat - Concantenates two strings where n number
 *            of bytes are copied from source.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: n bytes to copy from src.
 *
 * Return: Pointer to destination string.
 */

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t i = 0, j = 0;

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


/**
 * _strcat - Concantenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */

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

/**
 * _strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */

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
