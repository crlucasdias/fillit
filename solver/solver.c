#include "../fillit.h"

int  is_square()
{
    return (0);
}

int  get_column_value(l_tetriminos *list_tetriminos, int row, int column, int j)
{
    /* First interaction */
    if (row == - 1 && column == -1)
    {
        if(list_tetriminos->tetrimino[1])
        {
            if(list_tetriminos->tetrimino[1][0] < list_tetriminos->tetrimino[0][0])
            {
                    j = (list_tetriminos->tetrimino[0][0] - list_tetriminos->tetrimino[1][0]) - j;
            }
        }
        /* else, return (j default); */
    }
    /* When we have more one on the same column */
    else if (list_tetriminos->tetrimino[row][column + 1])
    {
        j = j + (list_tetriminos->tetrimino[row][column + 1] - list_tetriminos->tetrimino[row][column]);
    }
    /* Deal when we check if need change row */
    else if(list_tetriminos->tetrimino[row + 1])
    { 
        /* have new row and a previous value on column, means we need to go back */
        if(list_tetriminos->tetrimino[row + 1][column - 1])
        {   
            j = j - (list_tetriminos->tetrimino[row][column] - list_tetriminos->tetrimino[row + 1][column - 1]);
        }
        else
        {
            /* When we have a new row, but with different sizes, without have a previous, that means we have something forward.
            Otherwise will return the same j. */
            if(list_tetriminos->tetrimino[row + 1][column] != list_tetriminos->tetrimino[row][column])
            {
                j = j + (list_tetriminos->tetrimino[row + 1][column] - j - '0');
            }
        }  
    }
    return (j);
}

int  try_fillit(char **map, l_tetriminos *list_tetriminos, int i, int j)
{
    int row;
    int column;
    int aux;

    row = 0;
    column = 0; 
    j = get_column_value(list_tetriminos, -1, -1, j);
    while(list_tetriminos->tetrimino[row])
    {
        while(list_tetriminos->tetrimino[row][column])
        {
            if(map[i][j] != EMPTY_CHARACTER)
            {
                printf("Espaco ocupado.");
                return(0);
            }
            map[i][j] = list_tetriminos->character; //vai dar seg fault quando o map[j] == null
            j = get_column_value(list_tetriminos, row, column, j);
            column++;
        }
        i += 1;
        row++;
        column = 0;
    }
    print_map(map);
    return (1);
}

int is_empty_space(char c)
{
    if(c == '.')
        return (1);
    return (0);
}

char **refresh_map(char **map, char character)
{   
    return map;
}

char **solver(char **map,l_tetriminos *list_tetriminos)
{
    //pode ajudar performance:
    //i and j as parameter, qd fizer o backtracking.

    /* 
        Problemas:
        Aqui, tenho que comecar o backtracking, chamar essa nova funcao com o mapa atualizado e o proximo valor da lista. 
    */

    int i; 
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        while(map[i][j])
        {
            if(is_empty_space(map[i][j]))
            {
                if(try_fillit(map,list_tetriminos, i, j))
                {
                    return (0);
                    exit(0);
                    //fit it
                    //return new map (solver again)
                    //
                }
                return (0);
                exit(0);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}