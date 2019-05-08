#include "fillit.h"

char *verify_file(int fd)
{
    int aux;
    char data[BUFFER_FILE + 1];
    char *txt_str;

    txt_str = ft_strnew(1);
    while((aux = read(fd,data,BUFFER_FILE)) > 0)
    {
        data[aux] = '\0';
        if(verify_current_buffer(data))
            txt_str = ft_strjoin(txt_str,data);
        else
            return(0);
    }
    return (txt_str);
}

int verify_current_buffer(char *data)
{
    int i;
    int dots;
    int hash;

    i = 0;
    dots = 0;
    hash = 0;
    if(data[BUFFER_FILE - 1] != '\n' && data[BUFFER_FILE - 1] != '\0')
        return(0);
    while(data[i])
    {
        if((i == BUFFER_FILE - 1) && (data[i] != '\n'))
            return (0);
        if(data[i] == '.')
            dots++;
        else if(data[i] == TETRIMINO_CHARACTER)
            hash++;
        i++;
    }
    return (is_valid_tetrimino_count(dots,hash));
}

int is_valid_tetrimino_count(int dots, int hash)
{
    int total_dots;

    total_dots = BUFFER_FILE - (BUFFER_FILE / DOTS_PER_LINE) - HASH_SIZE;
    if(hash != HASH_SIZE)
        return(0);
    if(dots != total_dots)
        return(0);
    return (1);
}