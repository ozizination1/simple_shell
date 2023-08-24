#include "shell.h"

char **_getenv(const char *name)
{
	int i, len;

	len = _strlen(name);
	for(i = 0; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], len) == 0)
			return(environ + i);
	}
	return(NULL);
}


char **_copyenv(void)
{
	char **new_environ;
	size_t size;
	int i;

	for (size = 0; environ[size]; size++)
		;
	
	new_environ = malloc(sizeof(char *) * (size + 1));

	if (!new_environ)
		return (NULL);

	for (i = 0; environ[i]; i++)
	{
		new_environ[i] = malloc(_strlen(environ[i]) + 1);

		if (!new_environ[i])
		{
			for (i--; i >= 0; i--)
				free(new_environ[i]);
			free(new_environ);
			return (NULL);
		}
		_strcpy(new_environ[i], environ[i]);
	}
	new_environ[i] = NULL;

	return (new_environ);
}

void free_env(void)
{
	int i;

	for (i = 0; environ[i]; i++ )
		free(environ[i]);
	free(environ);
}
