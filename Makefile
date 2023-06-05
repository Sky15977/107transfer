##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compiles mylib
##

CC 	=	gcc

SRC	=	src/error.c \
		src/main.c \
		src/process.c \
		src/getnbr_n.c \
		src/str_dup.c

LIB 	=	lib/my/free.c \
	        lib/my/list_add.c \
        	lib/my/list_get.c \
		lib/my/my_getnbr.c \
		lib/my/my_isneg.c \
		lib/my/my_put.c	\
		lib/my/my_revstr.c \
		lib/my/my_str.c \
		lib/my/my_strcat.c \
		lib/my/my_strcmp.c \
		lib/my/my_strcpy.c \
		lib/my/my_strdup.c \
		lib/my/my_str_is.c \
		lib/my/my_strncmp.c \
		lib/my/my_str_to_word_array.c \
		lib/my/my_strupcase.c \
		lib/my/my_swap.c

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

NAME	=	libmy.a

NAME_BIN	= 	107transfer

LIBA	=	-L. -lmy

INCLUDES        =       -I includes/

CFLAGS	=	$(INCLUDES) -Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@$(CC) -o $(NAME_BIN) $(LIBA)
		@echo -e "\033[1;32mCompilation done\033[0m"

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@find . \( -name "*~" -o -name "#*" -o -name "*#" \) -delete
	@echo -e "\033[1;31mClean done\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_BIN)
	@rm -f coding-style-reports.log
	@rm -f vgcore*
	@echo -e "\033[1;31mFclean done\033[0m"

re:	fclean all

.PHONY: 	all re clean fclean
