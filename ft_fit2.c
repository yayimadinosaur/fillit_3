/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:49:47 by wfung             #+#    #+#             */
/*   Updated: 2017/03/08 19:30:08 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_chk_store(t_store **store)		//checks which index section of store is marked
{
	int		k;

	k = 0;
	while (store[k] != 0)
	{
		if (store[k].marked == 'N')
			return (k);		//return piece not placed (marked N)
		k++;
	}
	return (26);		//all pieces of store are placed (marked Y)
}

int		ft_place2(t_store **store, )			//checks which one isnt placed
{

}

int		ft_chk_index(t_grid **grid, int i, int j, t_store **store)	//checks the entire shape
{
	int		k;
	int		x;
	int		y;		//decrement counter for each index

	k = 0;
	x = 0;
	y = store[k]->store[x] + 1;			//adding 1 extra because of norm space (y-- inside of 3rd while)
	while (x < 4)
	{
		y = store[k]->store[x];
		while (grid[i] != 0)
		{
			while (grid[i][j].content != 0 && y--)
			{
				if (y == 0)
				{
					if (grid[i][j].content != '.')
						return (0);					//grid position is not empty
				}	
				j++;
			}
			i++;
			j = 0;
		}
	}
	return (y - 1);		//all 4 parts of index can be placed
}

int		ft_chk_pts2(t_grid **grid, int i, int j, t_store **store)
{
	int		k;
	int		x;

	x = 0;
	k = ft_chk_store(store);		//check which part of stored index isnt placed (marked 'N')
	while (x < 4)
	{
		while (grid[i] != 0)
		{
			while (grid[i][j].content != 0)
			{
				j++;
			}
			j = 0;
			i++;
		}
		x++;
	}
	return (1);				//checked shape

int		ft_fit2(t_grid **grid, t_store **store)
{
	int		i;
	int		j;
	int		z;		//z = chk_store return value (0-25 for store index; 27 for all done)

	i = 0;
	j = 0;
	while (grid[i]!= 0)
	{
		while (grid[i][j].content != 0)
		{
			if (grid[i][j].content == '.')			//if location is empty, then check
			{
				if (ft_chk_pts2(grid, i, j, store) != 0)
					ft_place2(grid, i, j, store);	//place piece (NEED TO KNOW WHICH)
				else
					return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (ft_store_chk(store) == 1)		//checks store if all are placed (marked Y)
	{
		printf("fit2 all pieces placed; please chk solution\n");
		return (1);
	}
	printf("fit2 map could not fit all shapes\n");
	return (0);
}
