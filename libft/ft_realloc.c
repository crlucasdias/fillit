#include "libft.h"

char    *ft_realloc(char *str, size_t size)
{
    char *new_str;
    int i = 0;
    
    new_str = malloc(size);
    if(!new_str)
        return (0);
    ft_strncpy(new_str, str, size);
    free(str);
    return new_str;
}
