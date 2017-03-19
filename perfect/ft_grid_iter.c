/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:18:33 by wfung             #+#    #+#             */
/*   Updated: 2017/03/18 20:45:08 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//function for removing pieces
//void	ft_remove();

int		ft_chk_range(int i, int j, t_store **store, int range)
{
	int		a;		//store iter
	int		k;		//per piece
	int		buff_x;
	int		buff_y;

	a = 0;
	k = 0;
	printf("start chk_range RANGE = [%i] i[%i] j[%i]\n", range, i, j);
	while (store[a]->marked != 'N')
		a++;
	while (store[a]->stored[k] != 0)
	{
		printf("chk_range k = [%i]\n", k);
		buff_x = i + store[a]->stored[k]->y;		//switched x with y, dunno why it works
		buff_y = j + store[a]->stored[k]->x;
		if (buff_x > range)
		{
			printf("out of range big buff_x[%i] grid x[%i] y[%i] store x[%i] y[%i]\n", buff_x, i, j, store[a]->stored[k]->x, store[a]->stored[k]->y);
			return (0);
		}
		if (buff_x < -1)
		{
			printf("out of range buff_x[%i] x neg grid x[%i] y[%i] store x[%i] y[%i]\n", buff_x, i, j, store[a]->stored[k]->x, store[a]->stored[k]->y);
			return (0);
		}
		if (buff_y > range)
		{
			printf("out of range buff_y[%i] y big grid x[%i] y[%i] store x[%i] y[%i]\n", buff_y, i, j, store[a]->stored[k]->x, store[a]->stored[k]->y);
			return (0);
		}
		if (buff_y < -1)
		{
			printf("out of range buff_y[%i] y neg grid x[%i] y[%i] store x[%i] y[%i]\n", buff_y,i, j, store[a]->stored[k]->x, store[a]->stored[k]->y);
			return (0);
		}
		k++;
	}
	printf("chk_range all fit within current grid range\n");
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

	a = 0;
	k = 0;
	printf("place3 start\n");
	while (store[a]->marked != 'N')
		a++;
	while (k < 4)
	{
		printf("shape = [%i] piece = [%i] i [%i] j [%i] x [%i] y [%i]\n", a, k, i, j, store[a]->stored[k]->x,
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
		printf("chk_pts3 CHECKING shape [%i] piece [%i][%i][%i] grid x[%i]y[%i] result x[%i]y[%i]\n", a, k, store[a]->stored[k]->x, store[a]->stored[k]->y, i, j, i + store[a]->stored[k]->x , j + store[a]->stored[k]->y);
		if (grid[i + store[a]->stored[k]->y][j + store[a]->stored[k]->x].content == '.')
			k++;
		else
		{
			printf("chk_pts3 shape [%i] piece [%i] will not fit\n", a, k);
			return (0);
		}
	}
	printf("chk_pts3 passed!\n");
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
						i = 0;			//trying to see if reset grid coor works
						j = -1;
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
