/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 21:02:02 by wfung             #+#    #+#             */
/*   Updated: 2017/03/07 20:30:43 by wfung            ###   ########.fr       */
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
	printf("-----start place-----\n");
//	while (x < 5)
	while (store[k]->stored[x] != 0)		//or while (x < 4) because store[x] is always 0
	{
	//	printf("placing k = [%i] x = [%i]\n", k, x);
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
		x++;
	//	printf("placed k = |%i| (%i)(%i)[%c]\n", k, i, j, grid[i][j].content);
	//	printf("[%c]", grid[i][j].content);
	}
//	printf("\n");
	printf("-----end place-----\n");
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
		if (grid[i][j].content == '.')
	//	if (grid[i][j].content == '.' && store[k]->marked == 'N')
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
	int		x;		//counter for each piece of shape (1 - 4)

	i = 0;
	j = 0;
	k = 0;
	x = 0;
	printf("start fit\n");
	while (grid[i] != 0)
	{
		while (grid[i][j].content != 0)
		{
			if (store[k] == 0)					//without this, k is segfaulting the entire main
			{
				printf("fit finished all of store[k] is placed\n");
				return (1);
			}
			printf("start chk_pts k = [%i]\n", k);
			if (ft_chk_pts(grid, store, grid_range, k) == 1)
			{
				printf("chk_pts store[%i] placed!\n", k + 1);
				ft_place(grid, store, grid_range, k);
				ft_print_grid(grid);
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
	printf("END fit GRID DONE! BADDDD NEWS NEED TO GROW GRID\n");
	return (0);
}
