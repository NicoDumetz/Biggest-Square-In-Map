##
## EPITECH PROJECT, 2023
## piz'' pgpj
## File description:
## l ihzoiz jio
##

SRC	=	my_getnbr.c \
		my_intlen.c \
		my_strlen.c \
		setting_up.c \
		get_size.c

OBJ_TEST=	$(SRC_TEST:.c=.o)

OBJ	=	$(SRC:.c=.o)

NAME	=	setting_up

CFLAGS += -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all
