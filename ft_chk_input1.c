/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_input1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:21:52 by wfung             #+#    #+#             */
/*   Updated: 2017/03/13 19:38:14 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_chk_block1(char *str)
{
	int		i;		//#
	int		j;		//\n
	int		k;		//counter
	int		test;

	i = 0;
	j = 0;
	k = 0;
	test = 0;
	while (*str)
	{
		if (*str == '#')
			i++;
		if (*str == '\n')
			j++;
		if (k == 20)
		{
			printf("k == %i i = [%i] j = [%i]\n", k, i, j);
			if (i != 4 && j != 5)
			{
				printf("FAILLLLL i = %i j = %i\n", i, j);
				return (0);
			}
			i = 0;
			j = 0;
			k = -1;
			printf("reset i + j + k\n");
		}
		k++;
		str++;
		test++;
	}
	printf("test = %i\n", test);
	printf("chk_block1 end i = %i j = %i k = %i\n", i, j, k);
	return (1);
}


int		ft_chk_count1(char *str, int i, int j, int k)
{
	int		x;

	x = ft_count_shapes(str);
	if (ft_strlen(str) < 20 || ft_strlen(str) > 545)
		return (0);
	if (x != (ft_strlen(str) + 1) / 21)
		return (0);
	if (i / 4 != (i + j + k + 1) / 21)
		return (0);
	if ((j / 5) + 1 != (i + j + k + 1) / 21)
		return (0);
	if (k / 12 != (i + j + k + 1) / 21)
		return (0);
	return (1);
}

int		ft_chk_char1(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*head;

	i = 0;
	j = 0;
	k = 0;
	head = str;
	while (*str)
	{
		if (*str == '#')
			i++;
		if (*str == '\n')
			j++;
		if (*str == '.')
			k++;
		else if (*str != '#' && *str != '\n' && *str != '.')
			return (0);
		str++;
	}
	if (ft_chk_count1(head, i, j, k) != 1)
	{
		printf("chk_count somethingoff\n");
		return (0);
	}
	return (1);
}

int		ft_chk_input1(char *str)
{
	if (ft_chk_char1(str) != 1)
	{
		printf("chk_char1 fail\n");
		return (0);
	}
	if (ft_chk_block1(str) != 1)
	{
		printf("chk_block1 fail\n");
		return (0);
	}
	return (1);
}
