#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


/* Operators */
#define BUFF_SIZE 1024
#define TOKEN_SIZE 64
#define DELIMITERS \
{\
";", "#", "&&", "||" \
}


/*Functions samples */
void shell(void);
char *_getline(void);
char **parse_line(char *);
int _getchar(void);
void *_realloc(void *, unsigned int, unsigned int);
char *_memcpy(char *, char *, unsigned int);
char **strtow(char *);
char **strtow2(char *, char);
int _strlen(char *);
void TJ_print(const char *string);
#endif
