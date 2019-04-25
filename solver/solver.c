#include "../fillit.h"

int  is_square()
{
    return (0);
}


//Problema:

/*

Quando o valor comeca na esquerda, o programa quebra.

exemplo:

.#..
###.

coisa legal:

o mapeamento esta funcionando corretamente, ou seja, talvez consiga resolver.
*/
int  try_fillit(char **map, l_tetriminos *list_tetriminos, int i, int j)
{
    int row;
    int column;
    int aux;

    row = 0;
    column = 0; 

   // print_array(list_tetriminos->tetrimino);
   // return (0);
   /* printf("%d \n", list_tetriminos->tetrimino[row][0]);
    printf("%d \n", list_tetriminos->tetrimino[row][1]);
    printf("%d \n", list_tetriminos->tetrimino[row + 1][0]);
    printf("%d \n", list_tetriminos->tetrimino[row + 2][0]);
    printf("END \n \n \n");
    printf("J Inicial : %d \n \n", j + '0');
*/
    while(list_tetriminos->tetrimino[row])
    {
        while(list_tetriminos->tetrimino[row][column])
        {
            if(map[i][j] != EMPTY_CHARACTER)
                return(0);
            map[i][j] = list_tetriminos->character; //vai dar seg fault quando o map[j] == null
            if (list_tetriminos->tetrimino[row][column + 1])
            {
                // printf("J Dentro IF Antes:  %d \n", j + '0');
                j = j + (list_tetriminos->tetrimino[row][column + 1] - list_tetriminos->tetrimino[row][column]);
                printf("J Dentro IF Depois:  %d \n", j + '0');
            }
            else if(list_tetriminos->tetrimino[row + 1] && list_tetriminos->tetrimino[row + 1][column - 1])
            {
                //printf("J Else if Fora Antes: %d \n", j + '0');
               // printf("Row + 1 column %d \n", list_tetriminos->tetrimino[row][column]);
               // printf("Row + 1 column -1 column %d \n", list_tetriminos->tetrimino[row + 1][column - 1]);
                //printf("Valor conta: %d \n", list_tetriminos->tetrimino[row + 1][column] - list_tetriminos->tetrimino[row + 1][column - 1]);


                j = j - (list_tetriminos->tetrimino[row][column] - list_tetriminos->tetrimino[row + 1][column - 1]);

                //tem proxima posicao
                //-> row + 1 column - 1 (existe.)
                //-> row column atual
                printf("J Else if Fora Depois: %d \n", j + '0');
            }
            else
            {
                printf("J Fora: %d \n", j + '0');
            }
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


            /* else if (list_tetriminos->tetrimino[row + 1] && ((j + '0') < list_tetriminos->tetrimino[row + 1][0]))
            {
                  printf("entrou aqi");
                  j = j - 1;
            } */


// else if (list_tetriminos->tetrimino[row + 1] && ((j + '0') < list_tetriminos->tetrimino[row + 1][0]))
            //    j = j - 1;


//problemas:
/*
como tratar com a lista nesse caso?
quando eh o fim?
*/

/*
    Como resolver o problema? 

    Parte 1:

    1. Pego o head e o mapa vazio.
    2. Percorro o mapa, procurando a primeira posicao vazia.
    3. Se encontrar, comeco a insercao no mapa com a list_tetriminos->character.

    Parte 2:
    
      Recebo o mapa.

 printf("list_tetriminos->tetrimino[row][column] ANTES: %d \n", list_tetriminos->tetrimino[row][column]);
            printf("J antes: %d \n", j);
            if (list_tetriminos->tetrimino[row][column + 1])
            {
                printf("list_tetriminos->tetrimino[row][column] DEPOIS %d \n", list_tetriminos->tetrimino[row][column + 1]);
                j = j + (list_tetriminos->tetrimino[row][column + 1] - list_tetriminos->tetrimino[row][column]);
            }
            printf("J depois: %d \n", j);
            printf("Next \n \n");



int  try_fillit(char **map, l_tetriminos *list_tetriminos, int i, int j)
{
    int row;
    int column;
    int aux;

    row = 0;
    column = 0;

    printf("%d \n", list_tetriminos->tetrimino[row][0]);
    printf("%d \n", list_tetriminos->tetrimino[row][1]);
    printf("%d \n", list_tetriminos->tetrimino[row + 1][0]);
    printf("END \n \n \n");
    printf("J Inicial : %d \n \n", j + '0');

    //Divergencia dos J indiferente, pq um eh do map e o outro do fillit.

    while(list_tetriminos->tetrimino[row])
    {
        while(list_tetriminos->tetrimino[row][column])
        {
            if(map[i][j] != EMPTY_CHARACTER)
                return(0);
            map[i][j] = list_tetriminos->character; //vai dar seg fault quando o map[j] == null
            if (list_tetriminos->tetrimino[row][column + 1])
            {
                  printf("J Dentro IF:  %d \n", j + '0');
                  j = j + (list_tetriminos->tetrimino[row][column + 1] - list_tetriminos->tetrimino[row][column]);
            }
            else if(list_tetriminos->tetrimino[row + 1] && list_tetriminos->tetrimino[row + 1][column - 1])
            {
                printf("J Else if Fora: %d \n", j + '0');
                j = j - 1;
            }
            else
            {
                //printf("tmp[%d][%d]\n", i, j);
                printf("J Fora: %d \n", j + '0');
                //printf("Tetrimino: %d \n", list_tetriminos->tetrimino[row + 1][0]);
                //printf("\n\n");
            }
            column++;
        }
        i += 1;
        row++;
        column = 0;
    }
    print_map(map);
    return (1);
}

*/