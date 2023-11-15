#include "shell.h"
/**
 * main - entry point
 * @ac: indicates arg count
 * @av: indicates arg vector
 *
 * Return: 0 on success,and 1 on error
 */
int main(int ac, char *av[])
{
if (argc == 2)
{
return (handle_file(argv[1], argv[0]));
}
else
return (shell(argv[0]));
}

