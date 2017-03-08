/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:36:25 by wfung             #+#    #+#             */
/*   Updated: 2017/03/07 18:14:56 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_place1()
{

}

int		ft_scan_grid1(t_grid **grid, int stored_index, int grid_range, int z)	//z = decrement counter
{
	int		i;		//counter for x
	int		j;		//counter for y

	i = 0;
	j = 0;
	while (stored_index > 0)
	{
		if (z == grid_range)
		{
			i++;
			j = 0;
			z = 0;
		}
		if (i == grid_range)
			return (0);
		j++;
		z++;
		stored_index--;
	}
	if (grid[i][j].content == '.')
		return (1);
	return (0);
}

int		ft_fit1(t_grid **grid, t_store **store, int grid_range)
{
	int		k;		//counter for store array
	int		x;		//counter for each piece of shape (1 - 4)
	int		z;		//decrement counter for out of bounds check

	k = 0;
	x = 0;
	z = 0;
	while (store[k] != 0)
	{
		while (x < 4)
		{
			if (ft_scan_grid1(grid, store[k]->stored[x], grid_range, z) != 1)
			{
				printf("fit1 no place to put store[%i]");
				return (0);
			}
			x++;
		}
		ft_place1();
		x = 0;
		k++;
	}
	return (1);
}
