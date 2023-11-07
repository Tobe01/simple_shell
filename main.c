#include "shell.h"
/**
 * main - entry point
 * @ac: indicates arg count
 * @av: indicates arg vector
 *
 * Return: 0 on success,and 1 on error
 */
int main(void)
{
shell();
populate_env_list(info);
read_history(info);
hsh(info);
return (EXIT_SUCCESS);
}

