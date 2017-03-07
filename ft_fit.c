/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 21:02:02 by wfung             #+#    #+#             */
/*   Updated: 2017/03/06 21:00:14 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_place(t_grid **grid, t_store **store, int grid_range, int k)
{
	int		i;		//x position of grid
	int		j;		//y position of grid
	int		x;		//counter for shape piece 1-4
	int		y;		//grid counter
	int		z;		//counter for distance of stored[k]->store[x]

	i = 0;
	j = 0;
	x = 0;
	y = grid_range;
	while (store[k]->stored[x] != 0)		//or while (x < 4) because store[x] is always 0
	{
		z = 0;
		while (z < store[k]->stored[k])
		{
			if (grid_range == 0)
			{
				i++;
				j = 0;
				grid_range = y;
			}
			grid_range--;
			z++;
		}
		grid[i][j].content = k + 65;
	}
	return ;
}

int		ft_chk_pts(t_grid **grid, t_store **store, int grid_range, int k)	//k == stored array index	
{
	int		i;		//x position of grid
	int		j;		//y position of grid
	int		x;		//counter for shape piece 1-4
	int		y;		//grid counter
	int		z;		//counter for distance of stored[k]->store[x]

	i = 0;
	j = 0;
	x = 0;
	y = grid_range;
	while (store[k]->stored[x] != 0)		//or while (x < 4) because store[x] is always 0
	{
		z = 0;
		while (z < store[k]->stored[k])
		{
			if (grid_range == 0)
			{
				i++;
				j = 0;
				grid_range = y;
			}
			z++;
			grid_range--;
		}
		if (grid[i][j].content == '.' && store[k]->marked != 'y')
		   	x++;
		else if (i == grid_range)
			return (0);
	}
	return (1);
}
void	ft_print_grid(t_grid **grid)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (grid[i] != 0)
	{
		while (grid[i][j].content != 0)
		{
			printf("[%c]", grid[i][j].content);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	return ;
}

int		ft_fit(t_grid **grid, t_store **store, int grid_range)
{
	int		i;
	int		j;
	int		k;		//counter for store array
	int		x;

	i = 0;
	j = 0;
	k = 0;
	x = 0;
	printf("start fit\n");
	while (i < grid_range)
	{
		while (j < grid_range)
		{
			if (k == grid_range)					//without this, k is segfaulting the entire main
			{
				ft_print_grid(grid);	
				printf("---------k == [%i]\n", k);
				return (1);
			}
			printf("start chk_pts k = [%i]\n", k);
			if (ft_chk_pts(grid, store, grid_range, k) == 1)
			{
				printf("chk_pts return == [1]\n");
				ft_place(grid, store, grid_range, k);
		//		x = 0;
			}
		//	x++;
			k++;
			j++;
		}
		i++;
		j = 0;
	}
	free(grid);		//not sure if this is correct spot to free
	printf("END FT_FIT // ft_fit FAILED\n");
	return (0);
}
