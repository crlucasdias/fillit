#include "libft/get_next_line.h"
#include <stdio.h>

#define BUFFER_FILE 21
#define SIZE_PER_LINE 4
#define HASH_SIZE 4
#define TETRIMINO_CHARACTER '#'

typedef struct l_tetriminos
{
    char character;
    int tetrimino[4];
    struct l_tetriminos *next;
} l_tetriminos;


int verify_file(int fd);
void create_tetrimino(l_tetriminos **lst, char character, char *data);
l_tetriminos *list_add(l_tetriminos *lst, char character);