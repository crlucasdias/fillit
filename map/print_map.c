#include "../fillit.h"

void    print_map(char **map)
{
	int i = 0;
	int j = 0;
	int count = 0;
	printf("Printando... \n");
	while(map[i])
	{
		while(map[i][j])
		{
			printf("%c",map[i][j]);
			j++;
			count++;
		}
		j = 0;
		i++;
	}
	//printf("\n Count: %d \n", count);
}