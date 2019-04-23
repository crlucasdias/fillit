#include "../fillit.h"


//gcc fillit.c tetrimino/*.c libft/*.c 

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

void    cria_array_por_linha(char **tmp_arr, char *data, char keep_track)
{
    int current_count_line;
    int characters;
    int i;

    i = 0;
    current_count_line = 0;
    characters = 0;
    while(data[i])
    {
        if(data[i] == TETRIMINO_CHARACTER)   
        {
            tmp_arr[current_count_line] = ft_realloc(tmp_arr[current_count_line], characters + 2);
            if(!tmp_arr[current_count_line])
                exit(0);
            tmp_arr[current_count_line][characters++] = keep_track;
        }
        if(data[i] == '\n' && tmp_arr[current_count_line])
        {
            current_count_line += 1;
            characters = 0;
        }
        keep_track = (data[i] == '\n') ? keep_track = '0' : ++keep_track;
        i++;
    }
}

char     **get_tetrimino(char **tmp_arr, char *data)
{
    int count_lines;
    int i;

    count_lines = get_count_lines_tetrimino(data) + 1;
    i = 0;
    tmp_arr = (char **)malloc(count_lines * sizeof(char*));
    if(!tmp_arr)
        return (0);
    while(i < count_lines)
    {
        tmp_arr[i] = malloc(sizeof(char));
        tmp_arr[i] = 0;
        i++;
    }
    cria_array_por_linha(tmp_arr, data, '0'); //colocar exit se error.
    return (tmp_arr);
}

void create_tetrimino(l_tetriminos **lst, char character, char *data)
{
    l_tetriminos *tmp;
    char **tetrim;

    if(!*lst)   
    {   
        *lst = list_add(*lst, character);
        (*lst)->tetrimino = get_tetrimino(tetrim,data);
        return;
    }
    tmp = *lst;
    while(tmp)
    {
        if(tmp->next)
            tmp = tmp->next;
        else
        {
            tmp->next = list_add(tmp->next,character);
            tmp = tmp->next;
            tmp->tetrimino = get_tetrimino(tetrim,data);
            break;
        }
    }
}