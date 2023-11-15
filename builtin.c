#include "shell.h"
/**
 * _customexit - exits the shell
 * @info: Structure containing potential arguments.
 * Return: exits with a given exit status
 * filename: name of file to be processed
 * s: just a function
 * stat: just status
 *(0) if info.argv[0] != "exit"
 */
int _customexit(char **s, char *filename, int stat)
{
int stat;
if (s[1] != NULL)
{
status = _atoi(s[1]);
if (status < 0)
exit_error_handler(filename, s[1], 2);
}
else
status = stat;
free_array(s);
exit(status);
}
/**
 * custom_env - prints the environment
 * Return: 0
 */
int custom_env(void)
{
pid_t pid;
char *file = "env.cs";
int stat;
char *args[] = {"env", NULL};
pid = fork();
if (pid == 0)
{
if (execve(file, args, environ) == -1)
{
perror("sh");
exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
perror("fork failed");
status = -1;
}
else
wait(&status);
return (status);
}
/**
 * custom_echo - handles echo command
 * @line: argument passed to echo
 * Return: int
 */
int custom_echo(char **line)
{
int i = 1;
while (line[i])
{
write(STDOUT_FILENO, line[i], _strlen(line[i]));
if (line[i + 1] != NULL)
write(STDOUT_FILENO, " ", 1);
i++;
}
write(STDOUT_FILENO, "\n", 1);
return (0);
}
/**
 * _prepenv - sets an environment variable
 * @name: name of environment variable
 * @value: value of environment variable
 * @overwrite: overwrite flag
 * Return: 0, -1 on failure
 */
int _prepenv(char *name, char *value, int overwrite)
{
int name_existss = 0, i = 0, fount_idx;
char **env_name;
if (!name || !value)
return (-1);
if (!overwrite)
overwrite = 1;
while (environ[i])
{
env_name = strtow(environ[i], '=');
if (!env_name)
return (-1);
if (_strcmp(env_name[0], name) == 0)
{
name_existss = 1;
fount_idx = i;
free_array(env_name);
break;
}
free_array(env_name);
i++;
}
if (name_existss)
{
if (overwrite)
return (update_env(name, value, fount_idx));
return (0);
}
return (create_env(name, value, i));
}
/**
 * _unprepenv - removes an environment variable
 * @name: name of environment variable
 * Return: 0, -1 on failure
 */
int _unprepenv(char *name)
{
int i = 0, j = 0, name_existss = 0;
char **env;
if (!name)
return (-1);
while (environ[i])
if (_strstr(environ[i++], name))
{
name_existss = 1;
break;
}
if (!name_existss)
return (0);
env = malloc(sizeof(char *) * i);
if (!env)
return (-1);
i = 0;
while (environ[i])
{
if (!_strstr(environ[i], name))
{
env[j] = _strdup(environ[i]);
if (!env[j])
{
while (j >= 0)
free(env[j--]);
free(env);
return (-1);
}
j++;
}
i++;
}
env[j] = NULL;
environ = env;
return (0);
}

