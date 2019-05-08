#include "fillit.h"
#include <fcntl.h>

#include <time.h>

int main(int argc, char **argv)
{
    int fd;
    char *fd_file_txt;
    char **map;
    char **solution;
    l_tetriminos *list_tetriminos;

    if(argc != 2)
    {
        printf("usage: ./fillit ~file_name.txt");
        exit(0);
    }
    fd = open(argv[1],O_RDONLY);
    if(!fd)
        return (0);
    fd_file_txt = verify_file(fd);
    if(fd_file_txt)
    {
        list_tetriminos = create_list_tetriminos(fd_file_txt);
        map = create_map('.',DOTS_PER_LINE + 1);
        //return(0);
        //clock_t t; 
        //t = clock();  

      /*  while(list_tetriminos)
        {
            printf("character %c \n", list_tetriminos->character);
           list_tetriminos = list_tetriminos->next;
        }
    
        exit(0);
    */
        if(!map || !list_tetriminos)
        {   
            printf("error");
            exit(0);
        }
        solution = solver(map, list_tetriminos);
        print_map(solution);
        //t = clock() - t; 
        //double time_taken = ((double)t)/CLOCKS_PER_SEC;
        //printf("Tempo sem aumentar se nao conseguir try_fillit: %f\n", time_taken); 
       //print_map(solution);
    }
    else
        printf("error");
    return (0);
}

//alterei o verify file. checar
/*
    creatE_tetrimino qd n terminar com /n
*/

/* Notas:

a[0][0]
a[1][0]
a[2][0]
a[3][0]

a[0][1]
a[1][1]
a[2][1]
a[3][1]

a[0][2]
a[1][2]
a[2][2]
a[3][2]

a[0][3]
a[1][3]
a[2][3]
a[3][3]

while(a[aux])
{
    while(a[i][j])
    {
        i++;
        counter++;
    }
    if(counter >= height_size)
        return (0);
    j = 0;
    counter = 0;
    aux++;
    i = aux;
}

return (1);

1 -> Pegar tamanho do height do mapa. Problema: seg fault ao tentar acessar [i][j].
2 -> Quando eh a primeira interacao e existe anterior. ta indo pra 5 - 2
3 -> Is square
4 -> Backtracking

*/
/*
BUG IFLHO DUMA PUTA QUE NAO TENHO IDEIA DO QUE QUE Q EH..

TALVEZ DEBUGAR OCM A MERDA DO LLDB AJUDE A DESCOBRIR ESSA MERDA SEM SENTIDO

FLW

bug fudido:

qd tem ####, o seguinte quebra a merda toda

qd tem ##
        ##
        o ultimo fica bugado com so 2 characters
*/

























/* auxs:

//print_map(map);

printa_lista

while(list_tetriminos)
{
    print_array(list_tetriminos->tetrimino);
    printf("Character: %c \n", list_tetriminos->character);
    list_tetriminos = list_tetriminos->next;
    printf("Next.. \n");
}
*/