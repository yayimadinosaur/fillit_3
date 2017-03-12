/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:15:52 by wfung             #+#    #+#             */
/*   Updated: 2017/03/11 16:32:09 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_addpieces1(t_save **array, char *str_start)
{
	int		i;		//# counter
	int		j;		//iterator counter
	int		k;
	int		x;

	i = 0;
	k = 0;
	j = 0;
	while (*str_start && i < 4)
	{
		if (*str_start == '#')
		{
			if (j > 4)
				k = j / 5;		//calculates x coor
			x = j % 5;			//calculates y coor
			array[i][0].piece = k;
			array[i][1].piece = x;
			i++;
		}
		str_start++;
		j++;
	}
	return ;
}

t_grid		**ft_save1(char *str, int shape_count)
{
	int		i;
	int		k;
	t_save	**save;

	i = -1;
	k = -1;
	if (!(save = (t_save**)malloc(sizeof(t_save*) * (shape_count + 1))))
		return (0);
	save[shape_count + 1] = 0;
	while (i < shape_count && i++)
	{
		if (!(save[i]->piece = (int***)malloc(sizeof(int**) * (5))))
			return (0);
		save[i].piece[5] = 0;
		while (k < 5 && k++)
		{
			if (!(save[i].piece[k] = (int**)malloc(sizeof(int*) * (3))))
				return (0);
			save[i].piece[k][3] = 0;
		}
		ft_addpieces1(save[i].piece, str + (21 * i));
		k = -1;
	}
	return (save);
}

/*
 * function only for test
 */

void	ft_print_save1(t_save **array)
{

}
