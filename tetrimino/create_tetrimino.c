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
    int aux = 0;
    while(data[i])
    {
        if(data[i] == TETRIMINO_CHARACTER)   
        {
            tmp_arr[current_count_line] = ft_realloc(tmp_arr[current_count_line], characters + 2);
            //if deu merda, free tudo. --doit
            tmp_arr[current_count_line][characters] = keep_track;
            characters++;
            aux = 1;
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
    //tmp_arr[current_count_line - 1] = NULL;
   
    /* verificando se ta tudo certo*/


int     get_tetrimino(l_tetriminos *lst, char *data)
{
    char **tmp_arr;
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
    cria_array_por_linha(tmp_arr, data, '0');
    print_array(tmp_arr);
    return (1);
}

//chama funcao pra criar
//se nao existir tetrimino[count_line][0] = malloc
//else realloc

//Passo a passo:
/*
    1 - Quantidade de linhas para fazer o malloc no array multidimensional.
    2 - Pegar character e keep tracking
*/
//  tmp_arr[0] = malloc(sizeof(char) * 2);
  //  tmp_arr[0][0] = 'a';
  //  printf("Valor: %c", tmp_arr[0][0]);
    //tmp_arr[count_lines][0] = 'a';
   // lst->tetrimino[characters] = malloc(sizeof(int));
   // lst->tetrimino[count_lines][characters] = 1;

/*

-1 esquerda.
+1 direita.


*/
    /* 
    
    Como vou resolver?

    Melhor solucao: Keep tracking.
    como isso funciona?

    1 -> Pra direita
    0 -> Mesma posicao
    -1 -> Pra esquerda

    ...#
    ...#
    ...#
    ...#

    linha[0][0] = 1
    linha[1][0] = 1
    linha[2][0] = 1
    linha[3][0] = 1

    ....
    ....
    ....
    ####

    linha[0][0] = 1
    linha[0][1] = 1
    linha[0][2] = 1
    linha[0][3] = 1

    .###
    ...#
    ....
    ....

    linha[0][0] = 1
    linha[0][1] = 1
    linha[0][2] = 1
    linha[1][0] = 0

    ....
    ..##
    .##.
    ....

    linha[0][0] = 1
    linha[0][1] = 1
    linha[1][0] = -2
    linha[1][1] = 1

    ##
    #
    #

    
    
        formas de resolver. 
        Opcao 1:
        Keep track da ultima posicao com numero.
        linha[x][3]
        linha[x][4]

        linha[0][0] = 2
        linha[0][1] = 3
        linha[1][0] = 4
        linha[2][0] = 4


        xx##
        xxx#
        xxx#

        Nao adianta. Por uma razao simples, ele nao necessariamente vai ficar
        nessas posicoes

        Opcao 2:
        Faz a copia inteira com os .
        no final tenta encaixar so aonde tem posicao
        ...x
        ...x
        ...x
        ..x.

    */


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

void create_tetrimino(l_tetriminos **lst, char character, char *data)
{
    l_tetriminos *tmp;

    if(!*lst)   
     {   
         *lst = list_add(*lst, character);
         get_tetrimino(*lst,data);
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
            break;
        }
    }
    get_tetrimino(tmp,data);
    //printf("###### PROXIMO ####### \n\n\n");
}




/*
typedef struct l_tetriminos 
{
    char character;
    int tetrimino[4];
    struct l_tetriminos *next;
} l_tetriminos;


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

l_tetriminos *list_add(l_tetriminos *lst, char character)
{
    lst = malloc(sizeof(l_tetriminos));
    if(!lst)
        return (0);
    lst->character = character;
    lst->next = '\0';
    return (lst);
}


void create_tetrimino(l_tetriminos **lst, char character)
{
    l_tetriminos *tmp;

    tmp = *lst;
    while(tmp)
    {
      tmp = tmp->next;
    }
    tmp = list_add(tmp,character);
}


int main() {

  l_tetriminos *lista;
  char character = 'a';
  lista = list_add(lista, character);
  character++;
  while(character < 'e')
  {
      create_tetrimino(&lista,character);
      character++;
  }
  return 0;
}

int get_tetrimino(l_tetriminos *lst, char *data)
{
    int lineSize;
    int i;
    int base;

    lineSize = 0;
    base = 0;
    i = 0;

    printf("Data: %s \n",data);
    while(data[i])
    {
        if(data[i] == TETRIMINO_CHARACTER)
        {
            lst->tetrimino[base] = base;
            //printf( "%d\n", lst->tetrimino[base]);
            base++;
        }
        i++;
    }
    return (1);

*/