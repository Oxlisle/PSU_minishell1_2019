/*
** EPITECH PROJECT, 2020
** cd_command.c
** File description:
** cd_command
*/

#include "function.h"
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int get_lenght(char **command)
{
    int j = 0;

    for (; command[j + 1] != NULL; j++);
    return (j);
}

void put_error(int type, char *str, char **command)
{
    if (type)
        my_putstr(command[0]);
    my_putstr(str);
}

char *get_home(void)
{
    char *buffer = NULL;
    char *final;
    int i = 0;
    int k = 0;
    size_t size = 0;

    final = getcwd(buffer, size);
    while (k != 3 && final[i] != '\0') {
        if (final[i] == '/')
            k++;
        i++;
    }
    final[i] = '\0';
    return (final);
}

int cd_command(char **command)
{
    int j = get_lenght(command);
    DIR *check;
    char *home;

    if (command[1] == NULL || command[1][0] == '\0') {
        home = get_home();
        chdir(home);
        free(home);
        return (1);
    } if ((check = opendir(command[1])) == NULL) {
        put_error(1, ": Not a directory.\n", command);
        closedir(check);
        return (1);
    } closedir(check);
    if (chdir(command[1]) == -1) {
        put_error(1, ": No such file or directory.\n", command);
        return (1);
    } if (j > 8 || (j == 2)) {
        my_putstr("cd: Too many arguments.\n");
        return (1);
    } return (1);
}