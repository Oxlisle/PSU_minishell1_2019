/*
** EPITECH PROJECT, 2020
** exec_command.c
** File description:
** exec_command
*/

#include "function.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int compare_string(char *s1, char *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
        i = i + 1;
    if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
        return (0);
    else
        return (1);
}

char **cut_pathes(char *command, int path)
{
    char **cuted = malloc(sizeof(char *) * my_strlen(__environ[path]));
    char *tmp = __environ[path];

    for (int i = 5, k = 0, j = 0; tmp[i] != '\0'; i++, j = 0) {
        cuted[k] = malloc(sizeof(char) * my_strlen(tmp));
        for (; tmp[i] != ':' && tmp[i] != '\0'; j++) {
            cuted[k][j] = tmp[i];
            i++;
        }
        cuted[k] = my_strcat(cuted[k], "/");
        cuted[k] = my_strcat(cuted[k], command);
        k++;
    } return (cuted);
}

char **get_pathes(char *command)
{
    int path = 0;

    while (__environ[path] != NULL) {
        if (!compare_string(__environ[path], "PATH=", 5))
            break;
        path++;
    }
    if (__environ[path] == NULL) {
        return (NULL);
    } else
        return (cut_pathes(command, path));
}

int is_exec(char **command)
{
    char **paths = get_pathes(command[0]);
    pid_t pid = fork();
    int status = 0;
    int i = 0;
    if (pid == 0) {
        pid = getpid();
        while (paths[i] != NULL) {
            execve(paths[i], command, __environ);
            i++;
        } execve(command[0], command, __environ);
    }
    waitpid(0, &status, 0);
    kill(pid, SIGKILL);
    return (status);
}