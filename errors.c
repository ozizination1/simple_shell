#include "shell.h"

int num_len(int num);
char *_itoa(int num);
int create_error(char **args, int err);

/**
 * num_len - Counts the length of a number
 * @num: number
 *
 * Return: Digit length
 */

int num_len(int num)
{
	unsigned int num1;
	int len = 1;

	if (num < 0)
	{
		len++;
		num1 = num * -1;
	}
	else
	{
		num1 = num;
	}
	while (num1 > 9)
	{
		len++;
		num1 /= 10;
	}
	return (len);
}

/**
 * _itoa - Converts integer to string
 * @num: integer
 *
 * Return: Converted string
 */

char *_itoa(int num)
{
	char *buffer;
	int len;
	unsigned int num1;

	len = num_len(num);

	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);

	buffer[len] = '\0';

	if (num < 0)
	{
		num  = num * -1;
		buffer[0] = '-';
	}
	else
	{
		num1 = num;
	}

	len--;
	do {
		buffer[len] = (num1 % 10) + '0';
		num1 /= 10;
		len--;
	} while (num1 > 0);

	return (buffer);
}

/**
 * create_error - Writes error message to standard error
 * @args: Array of arguments
 * @err: Error value
 *
 * Return: err
 */

int create_error(char **args, int err)
{
	char *error;

	switch (err)
	{
		case -1:
			error = error_env(args);
			break;
		case 1:
			error = error_1(args);
			break;
		case 2:
			if (*(args[0]) == 'e')
				error = error_2_exit(++args);
			else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
				error = error_2_syntax(args);
			else
				error = error_2_cd(args);
			break;
		case 126:
			error = error_126(args);
			break;
		case 127:
			error = error_127(args);
			break;
	}
	write(STDERR_FILENO, error, _strlen(error));

	if (error)
		free(error);
	return (err);
}
