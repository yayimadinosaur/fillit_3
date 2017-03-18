/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 20:44:27 by wfung             #+#    #+#             */
/*   Updated: 2017/03/17 21:16:23 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//function for removing pieces
//void	ft_remove();

int		ft_chk_range(int i, int j, t_store **store, int range)
{
	int		a;		//store iter
	int		k;		//per piece

	a = 0;
	k = 0;
	printf("start chk_range\n");
	while (store[a]->marked != 'N')
		a++;
	while (store[a]->stored[k] != 0)
	{
		if (i + store[a]->stored[k]->x > range)
			return (0);
		if (j + store[a]->stored[k]->y > range)
			return (0);
		k++;
	}
	printf("chk_range all fit within current grid\n");
	return (1);
}

int		ft_checkstore(t_store **store)
{
	int		i;

	i = 0;
	while (store[i] != 0)
	{
		if (store[i]->marked == 'Y')
			i++;
		else
			return (0);
	}
	return (1);
}

//REMEMBER HOW YOU BUILT THE FUCKEN GRID - Y POINTER THEN X INDEX
void	ft_place3(t_grid **grid, int i, int j, t_store **store)
{
	int		a;		//store iter
	int		k;		//per piece

	i = 0;
	a = 0;
	k = 0;
	printf("place3 start\n");
	while (store[a]->marked != 'N')
		a++;
	while (k < 4)
	{
		printf("shape = [%i] piece = [%i]\n", a, k);
		printf("i [%i] j [%i] x [%i] y [%i]\n", i, j, store[a]->stored[k]->x,
				store[a]->stored[k]->y);
		printf("result = i + x [%i] j + x [%i]\n", i + store[a]->stored[k]->x, j + store[a]->stored[k]->y);
		grid[i + store[a]->stored[k]->y][j + store[a]->stored[k]->x].content = a + 65;
		k++;
	}
	printf("place3 TESTING RESULT OF GRID!!!!!!\n");
	ft_print_grid(grid);
	store[a]->marked = 'Y';
	printf("store[%i]->marked = 'Y'\n", a);
	return ;
}

int		ft_chk_pts3(t_grid **grid, int i, int j, t_store **store)
{
	int		a;		//store iter
	int		k;

	a = 0;
	k = 0;
	printf("start chk_pts3\n");
	while (store[a]->marked != 'N')
		a++;
	printf("chk_pts shape choice = [%i]\n", a);
	while (store[a]->stored[k] != 0)
	{
		printf("chk_pts3 CHECKING shape [%i] piece [%i][%i][%i] grid x[%i]y[%i]\n", a, k, store[a]->stored[k]->x, store[a]->stored[k]->y, i, j);
		if (grid[i + store[a]->stored[k]->x][j + store[a]->stored[k]->y].content == '.')
			k++;
		else
			return (0);
	}
	printf("chk_pts3 finished shape\n");
	return (1);
}

int		ft_grid_iter(t_grid **grid, t_store **store, int range)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (grid[i] != 0)
	{
		while (grid[i][j].content != 0)
		{
			if (ft_checkstore(store) == 1)
			{
				printf("all pieces placed - please check solution\n");
				return (1);
			}
			printf("grid_iter [%i][%i][%c]\n", i, j, grid[i][j].content);
			if (grid[i][j].content == '.')
			{	
				if (ft_chk_range(i, j, store, range) == 1)
				{
					if (ft_chk_pts3(grid, i, j, store) == 1)
					{
						ft_place3(grid, i, j, store);
						printf("			grid_iter PLACED!		\n");
						ft_print_grid(grid);
					}
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	printf("			end of grid_iter			\n");
	return (0);
}
