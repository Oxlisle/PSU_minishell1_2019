##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compiling the project
##

SRC		=	sources/main.c\
			sources/lib_functions/my_putstr.c\
			sources/lib_functions/my_strlen.c\
			sources/lib_functions/my_str_to_word_array.c\
			sources/lib_functions/my_free_array.c\
			sources/lib_functions/my_putarray.c\
			sources/lib_functions/my_strcmp.c\
			sources/lib_functions/my_getnbr.c\
			sources/lib_functions/my_strcat.c\
			sources/lib_functions/my_strncmp.c\
			sources/shell_functions/initialize_shell.c\
			sources/shell_functions/builtins_functions/cd_command.c\
			sources/shell_functions/builtins_functions/env_command.c\
			sources/shell_functions/builtins_functions/setenv_command.c\
			sources/shell_functions/builtins_functions/unsetenv_command.c\
			sources/shell_functions/bin_functions/exec_command.c\

OBJ		=	$(SRC:.c=.o)

NAME	=	mysh

CC		=	gcc

CFLAGS	=	-Wall -Wshadow -Wextra -Iinclude/

all		:	$(NAME) clean

$(NAME)	:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re