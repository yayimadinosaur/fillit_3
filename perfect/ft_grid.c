/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:13:55 by wfung             #+#    #+#             */
/*   Updated: 2017/03/11 17:11:22 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillblank(t_grid **grid, int n)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 46;
//	printf("start [fillblank]\n-----\n");
	while (i < n)
	{
		while (j < n)
		{
			(grid[i][j]).content = k;
			j++;
		}
		if (j == 5)
			grid[i][j].content = 0;
		j = 0;
		i++;
	}
//	printf("i is now %i\n", i);
	printf("end [fillblank]\n-----\n");
//	return (grid);
	return ;
}

t_grid	**ft_makegrid(int n)
{
	t_grid	**head;
	t_grid	**buff;
	int		i;

	i = 0;
//	printf("start [makegrid]\n-----\n");
	if (!(buff = (t_grid**)malloc(sizeof(t_grid*) * (n + 1))))
		return (0);
	head = buff;
	while (i < n)
	{
//		printf("created row %i\n", i);
		if (!(buff[i] = (t_grid*)malloc(sizeof(t_grid) * (n + 1))))
			return (0);
		i++;
	}
	buff[i] = 0;
	printf("finished [makegrid] grid size = [%i]\n-----\n", n);
	ft_fillblank(head, n);
	return (head);
}
//left print here for testing purposes
void	ft_print_grid(t_grid **grid)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("start [print_grid]\n-----\n");
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
	printf("-----\nend [print_grid]\n-----\n");
	return ;
}

/*
 MAIN IS LEFT FOR TESTING PURPOSES

int		main(void)
{
	int		n;

	n = 2;

	while (n < 10)
	{
		ft_print_grid(ft_fillblank(ft_makegrid(n), n));
		n++;
	}
	return (0);
}
*/
