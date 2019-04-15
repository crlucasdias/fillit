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

int *get_tetrimino(l_tetriminos *lst, char *data)
{
    static int tst[2];
    tst[0] = 1;
    tst[1] = 2;
    return (tst);
    int i;
    int base;

    base = 0;
    i = 0;

    while(data[i])
    {
      /*  if(data[i] == TETRIMINO_CHARACTER)
        {
            lst->tetrimino[base] = 1;
            printf( "%d\n", lst->tetrimino[base]);
            base++;
        }*/
        i++;
    }
    printf("Fim.");

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

void create_tetrimino(l_tetriminos **lst, char character, char *data)
{
    l_tetriminos *tmp;

    if(!*lst)   
     {   
         *lst = list_add(*lst, character);
         return;
     }
     
    tmp = *lst;
    while(tmp)
    {
        if(tmp->next)
            tmp = tmp->next;
        else
            break;
    }
    tmp->next = list_add(tmp->next,character);
    //get_tetrimino(tmp,data);
}

/*
void create_tetrimino(l_tetriminos **lst, char character, char *data)
{
    l_tetriminos *tmp;

    if(!*lst)   
     {   
         *lst = list_add(*lst, character);
         return;
     }
     
    tmp = *lst;
    while(tmp)
    {
        if(tmp->next)
            tmp = tmp->next;
        else
            break;
    }
    tmp->next = list_add(tmp->next,character);
    //get_tetrimino(tmp,data);
}*/
