#include "../fillit.h"

void    print_map(char **map)
{
	int i = 0;
	int j = 0;
	while(map[i])
	{
		while(map[i][j])
		{
			printf("%c",map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_array(char **tmp_arr)
{
	int i = 0;
    int j = 0;
   //printf("Tmp[1][0] %c",tmp_arr[1][0]);
        while(tmp_arr[i])
        {
            while(tmp_arr[i][j])
            {
                printf("I: %d  J: %d, tmp[%d][%d]: Valor: %c \n", i,j,i,j, tmp_arr[i][j]);
                j++;
            }
            i++;
            j = 0;
        }
}