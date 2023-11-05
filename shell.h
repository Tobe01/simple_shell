#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/* Buffers */
#define BUFF_SIZE 1024
#define TOKEN_SIZE 64

/*Functions samples */
void shell(void);
char *_getline(void);
char **pase_line(char *);
int _getchar(void);
void *_relloc(void *, unsigned int, unsigned int);
char *_udicpy(char *, char *, unsigned int);
char **strt(char *);
int _straff(char *);
void TJ_print(const char *string);

#endif
