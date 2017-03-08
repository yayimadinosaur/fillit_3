/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:36:25 by wfung             #+#    #+#             */
/*   Updated: 2017/03/07 20:57:14 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place1(t_grid **grid, t_store **store, int k, int grid_range)	//k = array # of store
{
	int		i;		//counter for x
	int		j;		//counter for y
	int		z;
	int		x;
	int		stored_index;

	i = 0;
	j = 0;
	z = -1;
	x = 0;
	while (x < 4)
	{
		stored_index = store[k]->stored[x] + 1;
		printf("p1 start stored_index = [%i] k = [%i] x = [%i] stored_index = [%i]\n", stored_index, k, x, stored_index);
		while (stored_index > -1 && z++ && stored_index--)
		{
			printf("p1 loop store[x] = [%i] stored_index = [%i] z = [%i]\n", x, stored_index, z);
			if (z == grid_range)
			{
				i++;
				j = 0;
				z = -1;
			}
			if (i == grid_range)
				return ;
			j++;
//twice		z++;
		}
		printf("p2 values - stored_index = [%i] z = [%i]\n", stored_index, z);
		grid[i][j].content = k + grid[i][j].content + 19;
		printf("p3 grid[%i][%i].content = [%c]\n", i, j, grid[i][j].content);
		x++;
		i = 0;
		j = 0;
	}
		//added bottom portion to see print out
/*	i = 0;
	j = 0;
	while (i < grid_range)
	{
		while (j < grid_range)
		{
			printf("[%c]", grid[i][j].content);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
	printf("\n");
*/	return ;
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
	{
		printf("scan_grid1 grid[%i][%i] = [%c]\n", i, j, grid[i][j].content);
		return (1);
	}
	printf("scan_grid1 FAIL  grid[%i][%i] = [%c]\n", i, j, grid[i][j].content);
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
				printf("fit1 no place to put store[%i]", k);
				return (0);
			}
			printf("fit1 x = [%i]\n", x);
			x++;
		}
		ft_place1(grid, store, k, grid_range);
		k++;
		x = 0;
	}
	ft_print_grid(grid);
	return (1);
}
