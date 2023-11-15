#include "shell.h"
/**
 * main - entry point
 * @ac: indicates arg count
 * @arv: indicates arg vector
 *
 * Return: 0 on success,and 1 on error
 */
int main(int ac, char *arv[])
{
if (ac == 2)
{
return (handle_file(arv[1], arv[0]));
}
else
return (shell(arv[0]));
}

