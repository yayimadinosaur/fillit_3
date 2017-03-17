/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:49:47 by wfung             #+#    #+#             */
/*   Updated: 2017/03/16 21:31:16 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* LEAVING OUT, NEED TO WRITE IF USING (CURRENTLY NOT)
int		ft_remove();

int		ft_place2(t_store **store, );				//places piece

*/

//PROBLEM PROBLEM PROBLEM PROBLEM
int		ft_chk_index(t_grid **grid, int j, t_store **store, t_store s_index)	//checks the entire shape
{
	int		x;		//store[s_index]->stored[x]
	int		y;		//decrement counter for each index

	k = j;
	x = 0;
	while (x < 4)
	{
		y = store[s_index]->store[x] + 1;		//adding 1 extra because of norm space (y-- inside of 3rd while)
		while (grid[i] != 0)
		{
			while (grid[i][j].content != 0 && y--)
			{
				if (y == 0 && grid[i][j].content != '.')
						return (0);					//grid position is not empty
				}
				j++;
			}
			i++;
			j = 0;
		}
		x++;
	}
	return (1);		//all 4 parts of index can be placed; RETURN INDEX VALUE? (choosing 1 for now)
}

int		ft_chk_mark(t_store **store)		//checks which index section of store is marked
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

int		ft_chk_pts2(t_grid **grid, int i, int j, t_store **store)	//checks if shape placed
{
	int		k;
	int		x;
	int		y;			//saving i for reset
	int		z;			//saving j for reset

	x = 0;
	while (grid[y] != 0)
	{
		y = i;
		z = j;
		k = ft_chk_mark(store);		//check which part of stored index isnt placed (marked 'N')
		if (k == 26)
			return (1);					//store is all placed
		while (grid[y][z].content != 0)
		{
			if (ft_chk_index(grid, y, store, k) != 1)	//CAN WE PASS IN THIS?
				return (0);			//FAIL CONDITION??? /////////
			y++;
		}
		z = 0;
		y++;
	}
	return (1);				//checked shape
}

int		ft_fit2(t_grid **grid, t_store **store)		//searches for next .
{
	int		i;
	int		j;
	int		z;		//z = chk_store return value (0-25 for store index; 26 for all done)

	i = 0;
	j = 0;
	while (grid[i]!= 0)
	{
		while (grid[i][j].content != 0)
		{
			if (grid[i][j].content == '.')			//if location is empty, then check
			{
				if (ft_chk_pts2(grid, i, j, store) != 0)			//STARTING LOCATION OF CHECK
					ft_place2(grid, i, j, store);	//place piece (NEED TO KNOW WHICH)
			}
			j++;
		}
		j = 0;
		i++;
	}
	printf("fit2 map could not fit all shapes\n");
	return (0);
}
