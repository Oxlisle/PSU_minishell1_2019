/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Displaying, one-by-one,
** the character of a string
*/

#include <unistd.h>

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
}
