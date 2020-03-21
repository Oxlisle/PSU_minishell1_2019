/*
** EPITECH PROJECT, 2020
** initialize_shell.c
** File description:
** Creating; getting and executing commands
*/

#include "function.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int display_error(int error_type, char *command)
{
    if (error_type == 9) {
        my_putstr(command);
        my_putstr(": Command not found.\n");
    } if (error_type == 139) {
        my_putstr("Segmentation fault (core dumped)\n");
    } return (1);
}

int check_command(char **command)
{
    int get_return;

    if (!my_strcmp(command[0], "exit"))
        return (0);
    if (!my_strcmp(command[0], "cd"))
        return (cd_command(command));
    if (!my_strcmp(command[0], "env"))
        return (env_command(command));
    if (!my_strcmp(command[0], "setenv"))
        return (setenv_command(command));
    if (!my_strcmp(command[0], "unsetenv"))
        return (unsetenv_command(command));
    if ((get_return = is_exec(command)) > 0)
        return (display_error(get_return, command[0]));
    return (1);
}

char *get_command(void)
{
    char *buffer = NULL;
    size_t size = 0;

    my_putstr("$> ");
    if (getline(&buffer, &size, stdin) == -1) {
        my_putstr("exit\n");
        free(buffer);
        return (NULL);
    } for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            buffer[i] = '\0';
    return (buffer);
}

int init_shell(void)
{
    char *command;
    char **cuted_command;

    while (1) {
        command = get_command();
        if (command == NULL)
            return (0);
        cuted_command = my_str_to_word_array(command, " \t");
        if (!check_command(cuted_command)) {
            my_free_array(cuted_command);
            free(command);
            return (0);
        } my_free_array(cuted_command);
        free(command);
    } return (0);
}