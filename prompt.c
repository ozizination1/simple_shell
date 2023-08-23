#include "shell.h"

void sig_handler(int sig)
{
	char *prompt = "\n:)";

	(void)sig;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, prompt, 3);
}


