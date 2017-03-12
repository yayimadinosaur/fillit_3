/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:32:00 by wfung             #+#    #+#             */
/*   Updated: 2017/03/11 17:59:56 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_chk_block(char *str)
{
	int		j;		//counter for #
	int		k;		//counter for \n
	int		m;		//counter for each block (21)
	int		test;
	j = 0;
	k = 0;
	m = 0;
	test = 0;
	while (*str)
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
			{
				printf("something wrong in block char#[%i] #[%i] \\n[%i]\n", test, j, k);
				return (0);
			}
			j = 0;
			k = 0;
		}
		m++;
		str++;
		test++;
	}
	return (1);
}

int		ft_chk_count(char *str)
{
	if (ft_strlen(str) < 20 || ft_strlen(str) > 545) //chk min + max char count
	{
		printf("strlen is off\n");
		return (0);
	}
	if (ft_chk_block(str) != 1)
	{
		printf("chk_block failed\n");
		return (0);
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
			i++;
		else if (str[i] != '#' && str[i] != '\n' && str[i] != '.')
		{
			printf("chk_char wrong char passed\n");
			return (0);
		}
	}
	if (ft_chk_count(str) != 1)
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
