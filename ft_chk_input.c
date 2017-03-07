/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:32:00 by wfung             #+#    #+#             */
/*   Updated: 2017/02/26 18:59:36 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_chk_block(char *str)
{
	int		j;		//counter for #
	int		k;		//counter for \n
	int		m;		//counter for each block (21)

	j = 0;
	k = 0;
	m = 0;
	while (*str++)
	{
		if (*str == '#')
			j++;
		if (*str == '\n')
			k++;
		if (m == 21)
		{
			if (j == 4 && k == 5)
				m = 0;
			else
				return (0);
			j = 0;
			k = 0;
		}
		m++;
	}
	printf("chk_block passed!\n");
	return (1);
}

int		ft_chk_count(char *str, int i, int j, int k) // all, #, \n
{
	if (ft_strlen(str) < 20 || ft_strlen(str) > 545) //chk min + max char count
	{
		printf("i count = %i\n", i);
		return (0);
	}
	if (i == 20)
	{
		if (j / 4 != 1 || k / 4 != 1)
		{
			printf("missing stuff i = %i j = %i k = %i\n", i, j, k);
			return (0);
		}
	}
	if (i > 20)
	{
		printf("[i > 20] i = %i\n# of shapes = %i + 1\n", i, (i - 20) / 21);
		printf("j = %i k = %i\n", j, k);
		if ((j - 4) / 4 != (i - 20) / 21 && (j - 4) / 4 != (i - 20) % 21)
		{
			printf("j count off\n");
			return (0);
		}
		if ((k - 4) / 5 != (i - 20) / 21 && (k - 4) / 5 != (i - 20) % 21)
		{
			printf("k count off\n");
			return (0);
		}
		if ((i - 20) % 21 != 0)
		{
			printf("not enough input count\n");
			return (0);
		}
		if (ft_chk_block(str + 20) != 1)
		{
			printf("chk_block failed!\n");
			return (0);
		}
	}
	printf("chk_count passed\n");
	return (1);
}

int		ft_chk_char(char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '#' || str[i] == '\n' || str[i] == '.')
		{
			if (str[i] == '#')
				j++;
			else if (str[i] == '\n')
				k++;
			i++;
		}
		else if (str[i] != '#' && str[i] != '\n' && str[i] != '.')
			return (0);
	}
	if (ft_chk_count(str, i, j, k) != 1)
		return (0);
	return (1);
}

int		ft_chk_input(char *str)
{
	int		i;

	i = 0;
	if (ft_chk_char(str) != 1)
	{
		printf("-----\nchk_input chk_char failed\n----");
		return (0);
	}
	printf("-----\nchk_input chk_char passed\n");
	while (str[i] != '\0')
	{
		if (str[i] == '.' || str[i] == '#' || str[i] == '\n')
			i++;
		else
			return (0);
	}
	printf("-----\nend of chk_input\n----\n");
	return (1);
}
