#include "fillit.h"
 #include <fcntl.h>

 
int main()
{
    int fd;
    char *fd_file_txt;
    char **map;
    l_tetriminos *list_tetriminos;

    fd = open("valid_file.txt",O_RDONLY);
    if(!fd)
        return (0);
    fd_file_txt = verify_file(fd);
    if(fd_file_txt)
    {
        list_tetriminos = create_list_tetriminos(fd_file_txt, list_tetriminos);
        map = create_map('.',DOTS_PER_LINE + 1);
        //print_map(map);
        while(list_tetriminos)
        {
            print_array(list_tetriminos->tetrimino);
            //printf("Character: %c \n", list_tetriminos->character);
            list_tetriminos = list_tetriminos->next;
            printf("Next.. \n");
        }
    }
    else
        printf("deu ruim");
    return (0);

    //
}

