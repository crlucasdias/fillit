#include "../fillit.h"

l_tetriminos *create_list_tetriminos(char *data)
{
    l_tetriminos *list_tetriminos;
    char character;
    char *tmp;
    int i;
    int aux;

    list_tetriminos = NULL;
    character = 'A';
    i = 0;
    aux = 0;

    while(data[i])
    {
        if(data[i] == '\n' && (data[i + 1] == '\n' ||  data[i + 1] == '\0'))
        {
            tmp = ft_strsub(data, aux, i - aux);
            if(!tmp)
                break;
            tetrimino_to_list(&list_tetriminos, character, tmp);
            aux = i + 2;
            character += 1;
        }
        i++;
    }
    return (list_tetriminos);
}

void    tetrimino_to_list(l_tetriminos **lst, char character, char *data)
{
    l_tetriminos *tmp;
    char **tetrim;

    tetrim = 0;
    if(!*lst)   
    {   
        *lst = list_add(*lst, character);
        (*lst)->tetrimino = create_tetrimino(tetrim,data);
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
            tmp->tetrimino = create_tetrimino(tetrim,data);
            break;
        }
    }
}

char     **create_tetrimino(char **tmp_arr, char *data)
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
    tmp_arr[i] = 0;
    build_tetrimino_array(tmp_arr, data, '0');
    return (tmp_arr);
}

void    build_tetrimino_array(char **tmp_arr, char *data, char keep_track)
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




/*


    while(list_tetriminos)
                    {
                        if(list_tetriminos->character == 'D')
                        {
                            if(list_tetriminos->tetrimino[0][0] == '\0')
                            {
                                printf("nulo");
                            }
                            printf("List_tetrimin[0][0] %c \n", list_tetriminos->tetrimino[0][0]);
                            printf("List_tetrimin[0][1] %c \n", list_tetriminos->tetrimino[0][1]);
                            print_array(list_tetriminos->tetrimino);
                            printf("Character: %c \n", list_tetriminos->character);
                        }
                        list_tetriminos = list_tetriminos->next;
                        printf("Next.. \n");
                    }
*/