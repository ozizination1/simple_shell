#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include<sys/stat.h>

extern char **environ /* Global environ */

/*String functions*/
int _strcmp(const char *s1, const char *s2);
char *_strtok(char *str, const char *delim);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
size_t strlen(const char* str);
char *_strchr(const char *str, int c);
char *_strncat(char *dest, const char *src, size_t n);

#endif
