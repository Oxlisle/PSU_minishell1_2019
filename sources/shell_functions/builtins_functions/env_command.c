/*
** EPITECH PROJECT, 2020
** env_command.c
** File description:
** env_command
*/

#include "function.h"
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

int env_error(char **command)
{
    int fd;
    DIR *check_dir;

    if (command[1] == NULL)
        return (1);
    if ((check_dir = opendir(command[1])) != NULL) {
        my_putstr("env: '");
        my_putstr(command[1]);
        my_putstr("': Permission denied\n");
        closedir(check_dir);
        return (0);
    } if ((fd = open(command[1], O_RDONLY))) {
        my_putstr("env: '");
        my_putstr(command[1]);
        my_putstr("': No such file or directory\n");
        return (0);
    }
    closedir(check_dir);
    close(fd);
    return (1);
}

int env_command(char **command)
{
    if (!env_error(command))
        return (1);
    my_putarray(__environ);
    return (1);
}