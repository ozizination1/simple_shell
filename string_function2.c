#include "shell.h"

char *_strchr(const char *str, int c);


char *_strchr(const char *str, int c)
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
