/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int my_strlen(char *str);

int is_char_valid(char c, char *separator)
{
    for (int i = 0; separator[i] != '\0'; i++)
        if (separator[i] == c)
            return (0);
    return (1);
}

int	detect_words(char *str, char *separator)
{
    int	b = 1;

    for (int a = 0; str[a] != '\0'; a++)
        if (is_char_valid(str[a], separator) && \
            !is_char_valid(str[a + 1], separator))
            b++;
    return (b);
}

char **my_str_to_word_array(char *str, char *separator)
{
    int	words = detect_words(str, separator);
    char **result = malloc(sizeof(char *) * (words + 1));
    int	a = 0;
    int	c = 0;
    int b = 0;

    for (; b < words; a++, b++, c = 0) {
        result[b] = malloc(sizeof(char) * (my_strlen(str) + 2));
        while (!is_char_valid(str[a], separator))
            a++;
        while (str[a] != '\0' && is_char_valid(str[a], separator) != 0) {
            result[b][c] = str[a];
            c++;
            a++;
        }
        result[b][c] = '\0';
    } result[b] = NULL;
    return (result);
}