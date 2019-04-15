NAME = bg

SRC =  $(wildcard *.c) \
	   $(wildcard libft/*.c) \
	   $(wildcard tetrimino/*.c)

OBJ = $(SRC:.c=.o)

FLAG = gcc  

all:	$(OBJ) 
		$(FLAG) $(SRC)
 
