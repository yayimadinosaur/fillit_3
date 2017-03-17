/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 20:44:27 by wfung             #+#    #+#             */
/*   Updated: 2017/03/17 16:44:19 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_chk_range(t_grid **grid, t_store **store)
{
	int		a;		//store iter
	int		k;

	a = 0;
	k = 0;
	printf("start chk_range\n");
	while (store[a]->marked != 'N')
		a++;
	printf("chk_pts shape choice = [%i]\n", a);
	ft_chk_range(grid, store);
	while (store[a]->stored[k] != 0)
	{
		printf("chk_range CHECKING [%i]\n", k);
		if (grid[i + store[a]->stored[k]->x][j + store[a]->stored[k]->y].content == '.')
			k++;
		else
			return (0);
	}
	printf("chk_range finished shape\n");
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

void	ft_place3(t_grid **grid, int i, int j, t_store **store)
{
	int		a;		//store iter
	int		k;

	i = 0;
	a = 0;
	k = 0;
	printf("place3 start\n");
	while (store[a]->marked != 'N')
		a++;
	while (k < 4)
	{
		grid[i + store[a]->stored[k]->x][j + store[a]->stored[k]->y].content = a + 65;
		k++;
	}
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
	ft_chk_range(grid, store);
	while (store[a]->stored[k] != 0)
	{
		printf("chk_pts3 CHECKING [%i]\n", k);
		if (grid[i + store[a]->stored[k]->x][j + store[a]->stored[k]->y].content == '.')
			k++;
		else
			return (0);
	}
	printf("chk_pts3 finished shape\n");
	return (1);
}

int		ft_grid_iter(t_grid **grid, t_store **store)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (grid[i] != 0)
	{
		while (grid[i][j].content != 0)
		{
			printf("grid_iter [%i][%i][%c]\n", i, j, grid[i][j].content);
			if (grid[i][j].content == '.')
			{
				if (ft_chk_pts3(grid, i, j, store) == 1)
				{
					ft_place3(grid, i, j, store);
					if (ft_checkstore(store) == 1)
					{
						printf("all pieces placed - please check solution\n");
						return (1);
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
