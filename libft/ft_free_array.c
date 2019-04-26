/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeserra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:32:01 by lbeserra          #+#    #+#             */
/*   Updated: 2019/02/27 17:34:07 by lbeserra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_multidimensional_array(char **arr)
{
	size_t i;
	
	i = 0;
	while(arr[i])
	{
		arr[i] = NULL;
		free(arr[i]);
		i++;
    }
    free(arr);
}
