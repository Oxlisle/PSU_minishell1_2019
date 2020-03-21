/*
** EPITECH PROJECT, 2020
** function.h
** File description:
** All the functions protoype of the project
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_

char **my_str_to_word_array(char *str, char *separator);
int my_strncmp(char *s1, char *s2, int n);
char *my_strcat(char *dest, char *src);
int unsetenv_command(char **command);
int setenv_command(char **command);
int my_strcmp(char *s1, char *s2);
void my_free_array(char **array);
int env_command(char **command);
int cd_command(char **command);
void my_putarray(char **str);
int is_exec(char **command);
void my_putstr(char *str);
int my_getnbr(char *str);
int my_strlen(char *str);

#endif /* !FUNCTION_H_ */