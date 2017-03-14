/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:32:00 by wfung             #+#    #+#             */
/*   Updated: 2017/03/13 19:54:02 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_chk_block(char *str)
{
	int		i;		//counter for #
	int		j;		//counter for \n
	int		k;		//counter for each block (21)

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		if (i > 20 && i % 21 == 0)
		{
			if (j == 4 && k == 5)
			{
				j = 0;
				k = 0;
			}
			else
			{
				printf("i == [%i] j == [%i] k == [%i]\n", i, j, k);
				return (0);
			}
		}
		if (str[i] == '#')
			j++;
		else if (str[i] == '\n')
			k++;
		i++;
	}
	if ((i + 1) % 21 != 0)
	{
		printf("i = [%i] [%c]\n", i, str[i]);
		return (0);
	}
	return (1);
}

int		ft_chk_count(char *str, int i, int j, int k)	//i = # j = \n k = .
{
	int		x;

	x = ft_count_shapes(str);
	if (ft_strlen(str) < 20 || ft_strlen(str) > 545) //chk min + max char count
	{
		printf("strlen is off; total strlen = [%zu]\n", ft_strlen(str));
		return (0);
	}
	printf("strlen = %i shape count = %i\n", (int)ft_strlen(str), x);
	if (x != ft_strlen(str) / 21)
	{
		printf("shape count [%i] doesn't match strlen / 21 [%i]\n", x, (int)ft_strlen(str));
		return (0);
	}
	if (i != 4 * x && j != 5 * x && i + j + k != (int)ft_strlen(str))
	{
		printf("chk_count F # = [%i] \n = [%i] . = [%i] shapes = [%i]\n", i, j, k, ft_count_shapes(str));
		return (0);
	}
	printf("TEST %ii %i\n", x, (int)ft_strlen(str) / 21);
	printf("chk_count values shapes = [%i] # = [%i] \\n = [%i] . = [%i]\n", x, i, j, k);
	printf("chk_count passed\n");
	return (1);
}


int		ft_chk_char(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*head;

	i = 0;
	j = 0;
	k = 0;
	head = str;
	if (str == '\0')
		return (0);
	while (*str)
	{
		if (*str == '#')
			i++;
		if (*str == '\n')
			j++;
		if (*str == '.')
			k++;
		if (*str != '#' && *str != '\n' && *str != '.')
			return (0);
		str++;
	}
	printf("chk_char finished str\n");
	if (ft_chk_count(head, i, j, k) != 1)
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
	if (ft_chk_block(str) != 1)
	{
		printf("chk_block failed\n");
		return (0);
	}
	printf("-----\nend of chk_input\n----\n");
	return (1);
}
