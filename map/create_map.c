#include "../fillit.h"

//Ideia: O ultimo character eh \n dps nulo. Se tirar o \n do ultimo, posso economizar em tempo de execucao. testar depois.
char **create_map(char character, int size_per_line)
{
	char **map;
	int i;
	int j;

	map = malloc(sizeof(char*) * (size_per_line));
	if(!map)
		return (0);
	i = 0;
	j = 0;
	while(i < BUFFER_FILE / size_per_line)
	{
		map[i] = malloc(sizeof(char) * size_per_line + 1);
		while(j < size_per_line)
		{
			map[i][j] = (j == size_per_line - 1) ? '\n' : character;
			j++;
		}   
		map[i][j] = '\0';
		j = 0;
		i++;
	}
	map[i] = NULL;
	return (map);
}
