#include "../fillit.h"

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
        else if(data[i] == TETRIMINO_CHARACTER)
            hash++;
        i++;
    }
    return (is_valid_tetrimino_count(dots,hash));
}


void print_list(l_tetriminos *list_tetriminos)
{

}


int verify_file(int fd)
{
    int aux;
    char data[BUFFER_FILE + 1];
    char character;
    l_tetriminos *list_tetriminos;
    
    character = 'A';
    while((aux = read(fd,data,BUFFER_FILE)) > 0)
    {
        data[aux] = '\0';
        if(verify_current_buffer(data))
        {
            
            create_tetrimino(&list_tetriminos, character,data);
            return (0);
           //printf("Character: %c \n", list_tetriminos->character);
        }
        else
        {
            printf("deu ruim. \n");
            return (0);
        }
        character += 1;
    }

    
   /// printf("COmecnado: \n");
    while(list_tetriminos)
    {
    //    printf("Character: %c \n", list_tetriminos->character);
        list_tetriminos = list_tetriminos->next;
    }
    
    return 1;
}


/* cria a lista e percorre. */