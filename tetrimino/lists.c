#include "../fillit.h"

l_tetriminos *list_add(l_tetriminos *lst, char character)
{
    lst = malloc(sizeof(l_tetriminos));
    if(!lst)
        return (0);
    lst->character = character;
    lst->next = NULL;
    return (lst);
}

int get_list_size(l_tetriminos *lst)
{
    int i;

    i = 0;
    while(lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

int get_count_lines_tetrimino(char *data)
{
    int count_lines;
    int found_tetrimino_character;
    int i = 0;

    count_lines = 0;
    found_tetrimino_character = 0;
    i = 0;
    while(data[i])
    {
        if(data[i] == TETRIMINO_CHARACTER)
            found_tetrimino_character = 1;
        if(data[i] == '\n' && found_tetrimino_character == 1)
        {
            count_lines++;
            found_tetrimino_character = 0;
        }
        i++;
    }
    return count_lines;
}