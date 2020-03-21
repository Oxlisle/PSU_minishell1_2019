/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** Return the length of a string
*/

int my_strlen(char *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++)
        result = i;
    return (result);
}