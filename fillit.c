#include "fillit.h"
#include <fcntl.h>


int main()
{
    int fd;
    char *fd_file_txt;
    char **map;
    char **solution;
    l_tetriminos *list_tetriminos;

    fd = open("valid_file.txt",O_RDONLY);
    if(!fd)
        return (0);
    fd_file_txt = verify_file(fd);
    if(fd_file_txt)
    {
        list_tetriminos = create_list_tetriminos(fd_file_txt);
        map = create_map('.',DOTS_PER_LINE + 1);
        if(!map || !list_tetriminos)
        {   
            printf("error");
            exit(0);
        }
        solution = solver(map, list_tetriminos);
    }
    else
        printf("error");
    return (0);
}

























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