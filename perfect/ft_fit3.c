/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 20:44:27 by wfung             #+#    #+#             */
/*   Updated: 2017/03/16 21:42:56 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place3(t_grid **grid, int i, int j, t_store **store)
{
	int		a;		//store iter
	int		b;		//stored shape piece
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (store[a]->marked != 'Y')
		a++;
	while (k < 4)
	{
		grid[i + store[a]->stored[k].content][j + x->stored[a][k].c] == i + 65;
		k++;
	}
	return ;
}

int		ft_chk_pts3(t_grid **grid, int i, int j, t_store **store)
{
	int		a;		//store iter
	int		b;		//stored shape piece
	int		k;

	a = 0;
	b = 0;
	k = 0;
	while (store[a]->marked != 'Y')
		a++;
	while (k < 4)
	{
		if (grid[i + store[a]->stored[k].content][j + store[a]->stored[k].content] == '.')
			k++;
		else
			return (0);
	}
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
			if (grid[i][j].content == '.')
			{
				if (ft_chk_pts3(grid, i, j, store) == 1)
					ft_place3(grid, i, j, store);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
