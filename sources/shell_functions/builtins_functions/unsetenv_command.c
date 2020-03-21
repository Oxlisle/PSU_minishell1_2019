/*
** EPITECH PROJECT, 2020
** unsetenv_command.c
** File description:
** unsetenv_command
*/

#include "function.h"
#include <stddef.h>
#include <unistd.h>

void make_up_environ(int k)
{
    int lenght = 0;

    for (int i = 0; __environ[i] != NULL; i++)
        lenght++;
    for (int i = k; i != lenght; i++) {
        if (i != (lenght - 1))
            __environ[i] = __environ[i + 1];
        else
            __environ[i] = NULL;
    }
}

void remove_variable(char *variable)
{
    int i = my_strlen(variable);

    for (int k = 0; __environ[k] != NULL; k++)
        if (!my_strncmp(variable, __environ[k], i) \
        && __environ[k][i + 1] == '=') {
            make_up_environ(k);
        }
}

int unsetenv_error(char **command)
{
    if (command[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return (0);
    }
    return (1);
}

int unsetenv_command(char **command)
{
    if (!unsetenv_error(command))
        return (1);
    for (int i = 1; command[i] != NULL; i++)
        remove_variable(command[i]);
    return (1);
}