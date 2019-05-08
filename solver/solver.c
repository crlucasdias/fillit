#include "../fillit.h"

int  is_square(char **map)
{
    return (1);
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

                //problema: ele pega o primeiro da outra posicao e faz a diminuicao.
                //5 - 2 = 3
                if(list_tetriminos->character == 'F')
                {
                    printf("Row: %d \n", row);
                    printf("Column %d \n", column);
                    printf("list_tetriminos->tetrimino[1][0] %d \n", list_tetriminos->tetrimino[1][0]);
                    printf("list_tetriminos->tetrimino[0][0] %d \n", list_tetriminos->tetrimino[0][0]);
                    printf("J antes1: %d \n", j);
                }
                j = j - (list_tetriminos->tetrimino[0][0] - list_tetriminos->tetrimino[1][0]);
                if(list_tetriminos->character == 'F')
                {
                    printf("J depois1: %d \n", j);
                }
            }
            else if(list_tetriminos->tetrimino[1][0] != list_tetriminos->tetrimino[0][0])
            {
                if(list_tetriminos->character == 'F')
                {
                    printf("J antes2: %d \n", j);
                }
                j = j - (list_tetriminos->tetrimino[1][0] - list_tetriminos->tetrimino[0][0]);
                if(list_tetriminos->character == 'F')
                {
                    printf("J depois2: %d \n", j);
                }
                //j = j - list_tetriminos->tetrimino[1][0] + '0';
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
        if(list_tetriminos->tetrimino[row + 1][column - 1] && (column - 1 > -1))
        {   
            j = j - (list_tetriminos->tetrimino[row][column] - list_tetriminos->tetrimino[row + 1][column - 1]);
        }
        else
        {
            /* When we have a new row, but with different sizes, without have a previous, that means we have something forward.
            Otherwise will return the same j. */
            if(list_tetriminos->tetrimino[row + 1][column] != list_tetriminos->tetrimino[row][column])
            {
                j = j + (list_tetriminos->tetrimino[row + 1][column]);
            }
        }  
    }
    return (j);
}

char  **try_fillit(char **map, l_tetriminos *list_tetriminos, int i, int j)
{
    char **new_map = create_map(EMPTY_CHARACTER, get_current_map_size(map));
    int row;
    int column;
    int aux;

    row = 0;
    column = 0; 
    new_map = cpy_map(new_map, map);
    j = get_column_value(list_tetriminos, -1, -1, j);  
    while(list_tetriminos->tetrimino[row])
    {
        while(list_tetriminos->tetrimino[row][column])
        {
            if(!new_map[i] || new_map[i][j] != EMPTY_CHARACTER)
            {
                //printf("Espaco ocupado OU Sem espaco suficiente. deal with\n"); //!new_map[i] == full
                return(0);
            }
            new_map[i][j] = list_tetriminos->character; //vai dar seg fault quando o map[j] == null
            print_map(new_map);
            printf("\n");
            j = get_column_value(list_tetriminos, row, column, j);
            column++;
        }
        i += 1;
        row++;
        column = 0;
    }
    return (new_map);
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

        Problema 1: 

        Backtracking -> Como funciona e como fazer.

        Problema 2:

        Como terminar o programa? Quando saber q todas as tentativas foram esgotadas?
    */
    char **new_map;
    int i; 
    int j;

    i = 0;
    j = 0;

    if(list_tetriminos->tetrimino && is_map_full(map, list_tetriminos->tetrimino))
        map = grow_map(map);
    while(map[i])
    {
        while(map[i][j])
        {
            if(is_empty_space(map[i][j]))
            {
                if((new_map = try_fillit(map,list_tetriminos, i, j)))
                {
                  //  print_map(new_map);
                  //  printf("\n");
                    if(list_tetriminos->next)
                    {   
                        solver(new_map, list_tetriminos->next);
                    }
                    return (0);
                }
                else
                {
                    //backtracking!! ;)
                    //else
                      //  inverte_posicoes_com_backtracking();
                }
                //return (0);
                //exit(0);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (map);
}