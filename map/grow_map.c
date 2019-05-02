#include "../fillit.h"

char **grow_map(char **map)
{
	int new_size;
	char **new_map;

	new_size = get_current_map_size(map);
	new_map = create_map(EMPTY_CHARACTER, new_size + 1);
	if (!new_map)
		return (0);
	new_map = cpy_map(new_map, map);
	ft_free_multidimensional_array(map);
	return (new_map);
}

int	 is_map_full(char **map)
{
	int i;
	int j;
	int empty_count;

	i = 0;
	j = 0;
	empty_count = 0;
	while(map[i])
	{
		while(map[i][j])
		{
			if(map[i][j] == EMPTY_CHARACTER)
				empty_count++;
			j++;
		}
		j = 0;
		i++;
	}
	if(empty_count < HASH_SIZE)
		return(1);
	else
		return(0);
}

int	 get_current_map_size(char **map)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = 0;
	while(map[i][j] != '\n')
	{
		size++;
		j++;
	}
	return (size + 1);
}

char **cpy_map(char **new_map, char **previous_map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(previous_map[i])
	{
		while(previous_map[i][j] != '\n')
		{
			if(previous_map[i][j] != EMPTY_CHARACTER)
				new_map[i][j] = previous_map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return new_map;
}
