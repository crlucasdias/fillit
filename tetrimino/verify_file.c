#include "../fillit.h"

int verify_count_buffer(int dots, int hash)
{
    int size_dots_we_want;

    size_dots_we_want = BUFFER_FILE - (BUFFER_FILE / SIZE_PER_LINE) - HASH_SIZE;
    if(hash != HASH_SIZE)
        return(0);
    if(dots != size_dots_we_want)
        return(0);
    return (1);
}

int verify_current_buffer(char *data)
{
    int i;
    int dots;
    int hash;

    i = 0;
    dots = 0;
    hash = 0;
    while(data[i])
    {
        if((i == BUFFER_FILE - 1) && (data[i] != '\n'))
            return (0);
        if(data[i] == '.')
            dots++;
        else if(data[i] == '#')
            hash++;
        i++;
    }
    return (verify_count_buffer(dots,hash));
}

int verify_file(int fd)
{
    int aux;
    char data[BUFFER_FILE + 1];

    while((aux = read(fd,data,BUFFER_FILE)) > 0)
    {
        data[aux] = '\0';
        if(verify_current_buffer(data))
        {
            printf("Linha ok. \n");
        }
        else
        {
            printf("deu ruim. \n");
            return (0);
        }
    }
    return 1;
}