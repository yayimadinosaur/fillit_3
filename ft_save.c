/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:34:12 by wfung             #+#    #+#             */
/*   Updated: 2017/03/10 17:23:32 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * stores each shape in a 4 x 4 t_grid
 */
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
				array[i][j].content == '#';
			}
			pos--;
			j++;
		}
		j = 0;
		i++;
	}
	return (array);
}

t_grid		**ft_addpieces(t_grid ***array, char *str, int shape_count)
{
	int		i;		//# counter
	int		j;		//**ptr counter
	int		k;		//position of #

	i = 0;
	j = 0;
	k = 0;
	while (*str)
	{
		if (*str == #)
		{
			if (i == 4)
			{
				ft_add_each(array[j], k);
				i = 0;
				k = 0;
				j++;
			}
			i++;
		}
		str++;
	}
	return (array);
}

t_grid		***ft_save(char *str, int shape_count)
{
	int		i;
	int		j;
	t_grid	***save;

	i = 0;
	j = 0;
	while (i < shape_count)
	{
		save[i] = ft_makegrid(17);	//creates **ptr blank grid per shape
		i++;
	}
	save[i] = 0;
	return (save);
}

/*
 * function only for test
 */

void	**ft_print_save(t_grid ***array)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (array[i] != 0)
	{
		while (array[i][j] != 0)
		{
			while (array[i][j][k].content != 0)
			{
				printf("%c", array[i][j][k].content);
				k++;
			}
			k = 0;
			j++;
		}
		k = 0;
		j = 0;
		i++;
	}
	return ;
}
