NAME = bg

SRC =  $(wildcard *.c) \
	   $(wildcard libft/*.c) \
	   $(wildcard tetrimino/*.c) \
	   $(wildcard solver/*.c) \
	   $(wildcard map/*.c)
OBJ = $(SRC:.c=.o)

FLAG = gcc -Wall -Wextra -Werror -o fillit

all:	$(OBJ) 
		$(FLAG) $(SRC)
 
