#include "shell.h"

void free_args(char **args, char **front);
char *get_pid(void);
char *get_env_value(char *beginning, int len);
void variable_replacement(char **args, int *exe_ret);

void free_args(char **args, char **front)
{
	size_t i;

	for (i = 0; args[i] || args[i + 1]; i++)
		free(args[i]);

	free(front);
}


char *get_pid(void)
{
	size_t i = 0;
	char *buffer;
	ssize_t file;

	file = open("/proc/self/stat", O_RDONLY);
	if (file == -1)
	{
		perror("Can't read file");
		return (NULL);
	}
	buffer = malloc(121);
	if (!buffer)
	{
		close(file);
		return (NULL);
	}
	read(file, buffer, 120);
	while (buffer[i] != ' ')
		i++;
	buffer[i] = '\0';

	close(file);
	return (buffer);
}



char *get_env_value(char *beginning, int len)
{
	char **var_addr;
	char *replacement = NULL, *temp, *var;

	var = malloc(len + 1);
	if (!var)
		return (NULL);

	var[0] = '\0';
	_strncat(var, beginning, len);

	var_addr = _getenv(var);
	free(var);
	if (var_addr)
	{
		temp = *var_addr;
		while (*temp != '=' && *temp != '\0')
			temp++;
		temp++;
		replacement = malloc(_strlen(temp) + 1);
		if (replacement)
			_strcpy(replacement, temp);
	}
	return (replacement);
}


void variable_replacement(char **line, int *exe_ret)
{
	int j, k = 0, len;
	char *replacement = NULL, *o_line = NULL, *n_line;

	o_line = *line;
	for (j = 0; o_line[j]; j++)
	{
		if (o_line[j] == '$' && o_line[j + 1]
				&& o_line[j + 1] != ' ')
		{
			if (o_line[j + 1] == '$')
			{
				replacement = get_pid();
				k = j + 2;
			}
			else if (o_line[j + 1] == '?')
			{
				replacement = _itoa(*exe_ret);
				k = j + 2;
			}
			else if (o_line[j + 1])
			{
				for (k = j + 1; o_line[k] && o_line[k]
						!= '$' && o_line[k] != ' '; k++)
					;

				len = k - (j + 1);
				replacement = get_env_value(&o_line[j + 1], len);
			}
			n_line = malloc(j + _strlen(replacement) + _strlen(&o_line[k]) + 1);

			if (!line)
				return;
			n_line[0] = '\0';
			_strncat(n_line, o_line, j);
			if (replacement)
			{
				_strcat(n_line, replacement);
				free(replacement);
				replacement = NULL;
			}
			_strcat(n_line, &o_line[k]);
			free(o_line);
			*line = n_line;
			o_line = n_line;
			j = -1;
		}
	}
}
