/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:43:11 by wfung             #+#    #+#             */
/*   Updated: 2017/03/16 16:50:57 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//uses t_save1 struct (testing out new struct values to avoid array within struct
//
void	ft_addpieces2(t_container **array, char *str_start)
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
			array[i]->x = k;
			array[i]->y = x;
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
	if (!(save1 = (t_save1**)malloc(sizeof(t_save1*) * (shape_count + 1))))
		return (0);
	save1[shape_count + 1] = 0;
	printf("save_2 finished malloc t_save1* * shape_count + 1\n");
	while (i < shape_count)
	{
		printf("save_2 start [%i] malloc * 5\n", i);
		k = -1;
		if (!(save1[i]->container = (t_container**)malloc(sizeof(t_container*) * (5))))
			return (0);
		printf("save_2 fin shape [%i] 5 ptr malloc\n", i);
		while (k < 4 && k++)
		{
			printf("save_2 start [%i]\n", k);
			if (!(save1[i]->container[k] = (t_container*)malloc(sizeof(t_container) * (1))))
				return (0);
		}
		save1[i]->container[4] = 0;
		printf("save_2 start add piece [%i] k [%i]\n", i, k);
		ft_addpieces2(save1[i]->container, str + (21 * i));
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
		while (array[i]->container[j] != 0)
		{
			printf("%i", array[i]->container[j]->x);
			printf("%i", array[i]->container[j]->y);
			j++;
		}
		printf("shape [%i] fin\n", i);
		j = 0;
		k++;
	}
	return ;
}
