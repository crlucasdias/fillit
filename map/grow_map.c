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

int	 get_height_size(char **tetrimino)
{
	int x;
	
	x = 0;
	while(tetrimino[x])
		x++;
	return (x);
}
int  get_width_size(char **tetrimino)
{
	int i;
	int j;
	int width;
	int tmp;

	tmp = 0;
	i = 0;
	j = 0;
	width = 0;
	while(tetrimino[i])
	{
		while(tetrimino[i][j])
		{
			tmp++;
			j++;
		}
		if(width < tmp)
			width = tmp;
		tmp = 0;
		j = 0;
		i++;
	}
	return (width);
}

int     is_height_full(char **map, int height_size)
{
    int i;
    int j;
    int counter;

    counter = 0;
    i = 0;
    j = 0;
    while(map[i][j] != '\n')
    {    
        if((map[i][j] != EMPTY_CHARACTER) && (!(counter >= height_size)))
		    counter = 0;
        else
            counter += 1;
        i++;
		//if(counter > height_size) eventualmente, eh contado um height e width iguais, pq sao msm posicoes. tenho q garantir que isso nao eh um problema
        if(counter >= height_size)
            return(0);
        else if(!map[i])
        {
            i = 0;
			counter = 0;
            j++;
        }
    }
    return (1);
}

int  is_width_full(char **map, int width)
{
	int i;
	int j;
	int tmp;
	
	i = 0;
	j = 0;
	tmp = 0;
	while(map[i])
	{
		while(map[i][j] != '\n')
		{
			if(map[i][j] != EMPTY_CHARACTER)
				tmp = 0;
			else
				tmp += 1;
			if(tmp >= width)
				return(0);
			j++;
		}
		tmp = 0;
		j = 0;
		i++;
	}
	return (1);
}


int	 is_map_full(char **map, char **tetrimino)
{
	int width_size;
	int height_size;

	width_size = get_width_size(tetrimino);
	height_size = get_height_size(tetrimino);	
	
	if(width_size + height_size <= HASH_SIZE)
		return(1);
	if(is_width_full(map, width_size) == 0 && is_height_full(map,height_size) == 0)
		return (0);
	return (1);
}


/*

	map[0][1]
	map[0][0]
	... total

*/
/*
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
	if(empty_count <= HASH_SIZE)
		return(1);
	else
		return(0);
}
*/

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


/*

while(map[i][j] != '\n')
	{
		if(map[i][j] == EMPTY_CHARACTER)
		{
			counter++;
			if(counter >= height_size)
			{
				printf("Counter: %d \n", counter);
				printf("J: %d \n", j);
				printf("I: %d \n", i);
				return (0);
			}
		}
		i++;
		if(!map[i])
		{
			i = 0;
			counter = 0;
			j++;
		}
	}

	*/