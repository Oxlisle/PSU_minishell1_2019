/*
** EPITECH PROJECT, 2020
** setenv_command.c
** File description:
** setenv_command
*/

#include "function.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int is_exist(char *variable)
{
    for (int i = 0; __environ[i] != NULL; i++) {
        if (!my_strncmp(variable, __environ[i], my_strlen(variable)))
            return (i);
    } return (-1);
}

void add_env(char *str, char *value)
{
    int lenght = 0;
    int check = is_exist(str);
    char *variable = str;

    for (int i = 0; __environ[i] != NULL; i++)
        lenght++;
    variable = my_strcat(variable, "=");
    variable = my_strcat(variable, value);
    if (check >= 0 && __environ[check][0] == str[0])
        __environ[check] = variable;
    else {
        __environ[lenght] = variable;
        __environ[lenght + 1] = NULL;
    }
}

int my_isalphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] >= '0' && str[i] <= '9') || \
        (str[i] >= 'a' && str[i] <= 'z') || \
        (str[i] >= 'A' && str[i] <= 'Z') || \
        str[i] == '_' || str[i] == '.') {
        } else {
            return (0);
        }
    return (1);
}

int check_error(char **command)
{
    if (command[1] == NULL) {
        env_command(command);
        return (0);
    } if (my_getnbr(&command[1][0])) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return (0);
    } if (!my_isalphanum(command[1])) {
        my_putstr("setenv: Variable name must contain ");
        my_putstr("alphanumeric characters.\n");
        return (0);
    } if (command[2] == NULL)
        return (1);
    if (command[3] == NULL)
        return (1);
    else {
        my_putstr("setenv: Too many arguments.\n");
        return (0);
    }
    return (1);
}

int setenv_command(char **command)
{
    if (!check_error(command))
        return (1);
    if (command[2] != NULL)
        add_env(command[1], command[2]);
    else
        add_env(command[1], "");
    return (1);
}