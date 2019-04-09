#include "libft/get_next_line.h"
#include <stdio.h>

#define BUFFER_FILE 21
#define SIZE_PER_LINE 4
#define HASH_SIZE 4


struct tetrimino
{
    char character;
    char tetrimino[4];
};

int verify_file(int fd);