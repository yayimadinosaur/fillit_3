/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:15:52 by wfung             #+#    #+#             */
/*   Updated: 2017/03/15 17:41:14 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//uses t_save1 struct (testing out new struct values to avoid array within struct
//
void	ft_addpieces2(t_save1 **array, int shape_num, char *str_start)
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
			array[shape_num][i].x = k;
			array[shape_num][i].y = x;
			i++;
		}
		str_start++;
		j++;
	}
	return ;
}

t_save1		**ft_save2(char *str, int shape_count)
{
	int		i;
	int		k;
	t_save1	**save1;

	i = 0;
	k = 0;
	if (!(save1 = (t_save1**)malloc(sizeof(t_save1*) * (shape_count + 1))))
		return (0);
	save1[shape_count + 1] = 0;
	while (i < shape_count)
	{
		if (!(save1[i] = (t_save1*)malloc(sizeof(t_save1) * (5))))
			return (0);
		save1[i][4] = 0;
		ft_addpieces2(save1[i], i, str + (21 * i));
		i++;
	}
	return (save1);
}

/*
 * function only for test
 */


void	ft_print_save2(t_save1 **array)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (array[i] != 0)
	{
		printf("shape store= [%i]\n", i);
		while (array[i]->piece[j] != 0)
		{
			while (array[i]->piece[j][k] != 0)
			{
				printf("%i", array[i]->piece[j][k]);
				k++;
			}
			printf("array[%i]->piece[%i][%i]\n", i, j, k);
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}
