#include "libft/get_next_line.h"
#include <stdio.h>

#define BUFFER_FILE 21
#define DOTS_PER_LINE 4
#define HASH_SIZE 4
#define TETRIMINO_CHARACTER '#'
#define EMPTY_CHARACTER '.'

typedef struct l_tetriminos
{
    char character;
    char **tetrimino;
    struct l_tetriminos *next;
} l_tetriminos;

char            *verify_file(int fd);
int             is_valid_tetrimino_count(int dots, int hash);
int             verify_current_buffer(char *data);
l_tetriminos    *list_add(l_tetriminos *lst, char character);
int             get_list_size(l_tetriminos *lst);
int             get_count_lines_tetrimino(char *data);
l_tetriminos    *create_list_tetriminos(char *data);
void            tetrimino_to_list(l_tetriminos **lst, char character, char *data);
char            **create_tetrimino(char **tmp_arr, char *data);
void            build_tetrimino_array(char **tmp_arr, char *data, char keep_track);
char            **create_map(char character, int size_per_line);
char            **grow_map(char **map);
int	            get_current_map_size(char **map);
char            **cpy_map(char **new_map, char **previous_map);
void            print_map(char **map);
void	        print_array(char **tmp_arr);
char            **solver(char **map,l_tetriminos *list_tetriminos);