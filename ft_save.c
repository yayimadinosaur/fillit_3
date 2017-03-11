/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:34:12 by wfung             #+#    #+#             */
/*   Updated: 2017/03/10 21:21:51 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * stores each shape in a 4 x 4 t_grid
 */

/*			FUNCTION PROBABLY NOT NEEDED
t_grid		**ft_add_each(t_grid **array, int pos)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array[i] != 0)
	{
		while (array[i][j].content != 0)
		{
			if (pos == 0)
			{
				array[i][j].content = '#';
			}
			pos--;
			j++;
		}
		j = 0;
		i++;
	}
	return (array);
}
*/
void	ft_addpieces(t_grid **array, char *str_start)
{
	int		i;		//# counter
	int		j;		//iterator counter
	int		k;
	int		x;

	i = 0;
	k = 0;
	j = 0;
	while (*str_start)
	{
		if (*str_start == '#')
		{
			//ft_add_each(&array[j], k);
			if (i == 4)
				return ;
			if (j > 4)
				k = j / 5;
			x = j % 5;
			array[k][x].content = '#';
			printf("[%i][%i]hey\n", k, x);
			i++;
		}
		str_start++;
		j++;
	}
	return ;
}

t_grid		***ft_save(char *str, int shape_count)
{
	int		i;
	int		j;
	t_grid	***save;

	i = 0;
	j = 0;
	if (!(save = (t_grid***)malloc(sizeof(t_grid**) * (shape_count + 1))))
		return (0);
	save[shape_count + 1] = 0;
	while (i < shape_count)
	{
		save[i] = ft_makegrid(4);	//creates **ptr blank grid per shape
		ft_addpieces(save[i], str + (21 * i));	//copies shape over to **ptr
		i++;
	}
	save[i] = 0;
	return (save);
}

/*
 * function only for test
 */

void	ft_print_save(t_grid ***array)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	printf("printing save complete\n");
	while (array[i] != 0)
	{
		while (array[i][j] != 0)
		{
			while (array[i][j][k].content != 0)
			{
				printf("%c", array[i][j][k].content);
			//	printf("[%i][%i][%i] %c", i, j, k, array[i][j][k].content);
				k++;
			}
			printf("\n");
			k = 0;
			j++;
		}
		printf("^shape[%i]\n", i);
		k = 0;
		j = 0;
		i++;
	}
	return ;
}
