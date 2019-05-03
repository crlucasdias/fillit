#include "libft.h"

char    *ft_realloc(char *str, size_t size)
{
    char *new_str;
    int i = 0;
    
    new_str = malloc(size);
    ft_bzero(new_str,size);
    if(!new_str)
        return (0);
    if(str)
    {
        ft_strncpy(new_str, str, size);
        str = NULL;
        free(str);
    }
    return new_str;
}
