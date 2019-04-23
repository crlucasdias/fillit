#include "fillit.h"
 #include <fcntl.h>

 
int main()
{
    int fd;
    char **map;

    fd = open("valid_file.txt",O_RDONLY);
    if(!fd)
        return (0);
    //map = create_map('.',DOTS_PER_LINE + 1);
    //print_map(map);
    verify_file(fd);
    return (0);

    //
}

