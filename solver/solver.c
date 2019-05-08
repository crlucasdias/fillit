#include "../fillit.h"

int  is_square()
{
    return (1);
}

int  get_column_value(l_tetriminos *list_tetriminos, int row, int column, int j)
{
    /* When we have more one on the same column */
    if (list_tetriminos->tetrimino[row][column + 1])
    {
        //printf("IF STATEMENT 1 ### \n \n");
        j = j + (list_tetriminos->tetrimino[row][column + 1] - list_tetriminos->tetrimino[row][column]);
    }
    /* Deal when we check if need change row */
    else if(list_tetriminos->tetrimino[row + 1])
    {
        if(list_tetriminos->tetrimino[row + 1][0] > list_tetriminos->tetrimino[row][column])
        {
          //  printf("IF STATEMENT 2 ### \n \n");
            j = j + (list_tetriminos->tetrimino[row + 1][0] - list_tetriminos->tetrimino[row][column]);
        }
        else if(list_tetriminos->tetrimino[row + 1][0] < list_tetriminos->tetrimino[row][column])
        {
            //printf("IF STATEMENT 3 ### \n \n");
            j = j - (list_tetriminos->tetrimino[row][column] - list_tetriminos->tetrimino[row + 1][0]);
        }
    }
    return (j);
}

char  **try_fillit(char **map, l_tetriminos *list_tetriminos, int i, int j)
{
    char **new_map = create_map(EMPTY_CHARACTER, get_current_map_size(map));
    int row;
    int column;

    row = 0;
    column = 0; 
    new_map = cpy_map(new_map, map);
    if(list_tetriminos->character == 'I')
    {
        //print_array(list_tetriminos->tetrimino);
    }

    while(list_tetriminos->tetrimino[row])
    {
        while(list_tetriminos->tetrimino[row][column])
        {
            if(!new_map[i] || new_map[i][j] != EMPTY_CHARACTER)
            {
                if(list_tetriminos->character == 'C')
                {
                    //printf("MAP [%d] [%d] \n", i, j);
                    //print_map(new_map);
                    //printf("\n");
                }
                //printf("Espaco ocupado OU Sem espaco suficiente. deal with\n"); //!new_map[i] == full
                return(0);
            }
            new_map[i][j] = list_tetriminos->character; //vai dar seg fault quando o map[j] == null
            //print_map(new_map);
            //printf("\n");
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

char **solver(char **map,l_tetriminos *list_tetriminos)
{
    //pode ajudar performance:
    //i and j as parameter, qd fizer o backtracking.

    /* 
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

    //printf("### Proximo character %c ### \n \n \n", list_tetriminos->character);
    
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
                    //print_map(new_map);
                    //printf("\n");
                    if(list_tetriminos->next)
                    {   
                        return(solver(new_map, list_tetriminos->next));
                    }
                    else
                    {
                        return(new_map);
                    }
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



/*

int  get_column_value(l_tetriminos *list_tetriminos, int row, int column, int j)
{
 First interaction 
    if (row == - 1 && column == -1)
    {
        return(j);
        if(list_tetriminos->tetrimino[1])
        {
            if(list_tetriminos->tetrimino[1][0] < list_tetriminos->tetrimino[0][0])
            {

                //problema: ele pega o primeiro da outra posicao e faz a diminuicao.
                //5 - 2 = 3
                if(list_tetriminos->character == 'B')
                {
                    printf("IF STATEMENT 1 ### \n \n");
                    printf("J antes1: %d \n", j);
                }
                j = j - (list_tetriminos->tetrimino[0][0] - list_tetriminos->tetrimino[1][0]);
                if(list_tetriminos->character == 'B')
                {
                    j = 2;
                    printf("J depois1: %d \n", j);
                }
            }
            else if(list_tetriminos->tetrimino[1][0] != list_tetriminos->tetrimino[0][0])
            {
                
                if(list_tetriminos->character == 'C')
                {
                    printf("IF STATEMENT 2 ### \n \n");
                    printf("J antes2: %d \n", j);
                }
                j = j - (list_tetriminos->tetrimino[1][0] - list_tetriminos->tetrimino[0][0]);
                if(list_tetriminos->character == 'B')
                {
                    printf("J depois2: %d \n", j);
                }
                //j = j - list_tetriminos->tetrimino[1][0] + '0';
            }
        }
    else, return (j default); 
    }
    When we have more one on the same column 

    else if (list_tetriminos->tetrimino[row][column + 1])
    {
        printf("IF STATEMENT 3 ### \n \n");
        j = j + (list_tetriminos->tetrimino[row][column + 1] - list_tetriminos->tetrimino[row][column]);
    }
 Deal when we check if need change row
    else if(list_tetriminos->tetrimino[row + 1])
    { 
    have new row and a previous value on column, means we need to go back
    if(list_tetriminos->tetrimino[row + 1][column - 1] && (column - 1 > -1))
        {   
            printf("IF STATEMENT 4 ### \n \n");
            j = j - (list_tetriminos->tetrimino[row][column] - list_tetriminos->tetrimino[row + 1][column - 1]);
        }           
          When we have a new row, but with different sizes, without have a previous, that means we have something forward.
            Otherwise will return the same j
     else if(list_tetriminos->tetrimino[row + 1][column] > list_tetriminos->tetrimino[row][column])
        {
                printf("IF STATEMENT 5 ### \n \n");
                printf("Column : %d \n",column);
                printf("J antes: %d \n",j);
                j = j - (list_tetriminos->tetrimino[row + 1][column] - list_tetriminos->tetrimino[row][column]);
                printf("J depois: %d \n",j);
        }
        else if(list_tetriminos->tetrimino[row + 1][column] < list_tetriminos->tetrimino[row][column])
        {
                printf("IF STATEMENT 5.2 ### \n \n");
                printf("Column : %d \n",column);
                printf("J antes: %d \n",j);
                j = j - (list_tetriminos->tetrimino[row][column] - list_tetriminos->tetrimino[row + 1][column]);
                printf("J depois: %d \n",j);
        }
    }
    return (j);
}

*/