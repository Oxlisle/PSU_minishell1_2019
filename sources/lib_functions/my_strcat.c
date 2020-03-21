/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** my_strcat
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char *str);

char *my_strcat(char *dest, char *src)
{
    char *str;
    int k = 0;

    if (dest == NULL || src == NULL)
        return (NULL);
    str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));
    for (int i = 0; dest[i] != '\0'; i++, k++)
        str[k] = dest[i];
    for (int i = 0; src[i] != '\0'; i++, k++)
        str[k] = src[i];
    str[k] = '\0';
    return (str);
}

/*
*/