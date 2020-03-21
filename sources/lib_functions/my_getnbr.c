/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** Transform an string to an int
*/

int my_getnbr(char const *str)
{
    int	nb = 0;
    int	n = 1;
    int	i = 0;

    while ((str[i] == '+') || (str[i] == '-')) {
        if (str[i] == '-')
            n = n * -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
        }
        else
            return (nb * n);
        i++;
    }
    return (nb * n);
}