/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:00:49 by wfung             #+#    #+#             */
/*   Updated: 2017/03/10 16:37:21 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_store		**ft_store_auto2(t_store **store, char *str)
{
	int		i;
	int		j;
	int		k;
	int		x;

	i = 0;
	j = 0;
	k = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			store[x]->stored[j] = i - k;
			j++;
		}
		if (j == 4)
		{
			j = 0;
			x++;
		}
		if (j == 0)
			k = i + 1;
		i++;
	}
	return (store);
}

t_store		**ft_create_store2(char *str, int shape_count)
{
	int		i;
	t_store	**store;
	t_store	**head;

	i = 0;
	if (shape_count == 0)
		return (0);
	else
		if (!(store = (t_store**)malloc(sizeof(t_store*) * (shape_count + 1))))
			return (0);	
	store[shape_count] = 0;
	head = store;
	while (i < shape_count)
	{
		if (!(store[i] = (t_store*)malloc(sizeof(t_store) * (1))))
			return (0);
		if (!(store[i]->stored = (int*)malloc(sizeof(int) * (5))))
			return (0);
		store[i]->stored[4] = 0;
		store[i]->marked == 'N';
		i++;
	}
	ft_store_auto(head, str);
	return (head);	
}

t_grid	**ft_convert(t_store **store)		//original idea was to convert t_store to t_grid
{												//result = extra work
	int i;	//grid counter	i
	int j;	//grid counter	j
	int k;	//store counter
	t_grid	**buff;

	i = 0;
	j = 0;
	k = 0;
	while (store[k] != 0)
		k++;
	if (!(buff = (t_grid**)malloc(sizeof(t_grid*) * (k + 1))))
		return (0);
	buff[k + 1] = 0;
	k = 0;
	while (store[k] != 0)
	{
		if (!(store[k][j] = (t_grid*)malloc(sizeof(t_grid) * 21)))
			return (0);
	//DID NOT FINISH
	}
}

/*		
 *		leave print_store + MAIN  function here for testing
*/

void		ft_print_store2(t_store **store, int count)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("start print\n");
	while (i < count)
	{
		while (j < 5)
		{
	//		printf("shape [%i], hash# [%i], value [%i]\n", i, j, store[i]->stored[j]);
			j++;
		}
		i++;
		j = 0;
	}
	printf("store[shape] = %i\n", i);
	if (store[i] == 0)
		printf("shape [%i] [\\0]\n", i);
	return ;
}

/*
int		main(void)
{
	int		x;
	char	*str =
					"####\n"
					"....\n"
					"....\n"
					"....\n"
					"\n"
					"#...\n"
					"###.\n"
					"....\n"
					"....\n"
					"\n"
					"##..\n"
					".#..\n"
					".#..\n"
					"\n";
	x = ft_count_shapes(str);
	ft_print_store(ft_create_store(str, x), x);
	return (0);
}
*/
