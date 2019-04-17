#include "fillit.h"
 #include <fcntl.h>

 
int main()
{
    int fd;

    fd = open("valid_file.txt",O_RDONLY);
    if(!fd)
        return (0);
    verify_file(fd);
    return (0);
}