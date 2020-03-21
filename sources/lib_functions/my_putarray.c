/*
** EPITECH PROJECT, 2020
** my_putarray.c
** File description:
** my_putarray
*/

#include <stddef.h>
void my_putstr(char *str);

void my_putarray(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
        my_putstr(str[i]);
        my_putstr("\n");
    }
}