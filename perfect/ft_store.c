/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:00:49 by wfung             #+#    #+#             */
/*   Updated: 2017/03/16 20:01:36 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_container		**ft_store_parts(t_container **stored, char *str)
{
	int		i;	//counter for piece (4)
	int		j;	//counter
	int		k;

	i = 0;
	j = 0;
	while (*str && i < 4)
	{
		if (*str == '#')
		{
			if (i == 0)
				k = j;
			if (!(stored[i] = (t_container*)malloc(sizeof(t_container) * (1))))
				return (0);
			stored[i]->x = (j % 5) - (k % 5);
			stored[i]->y = (j / 5) + (k / 5);
			i++;
		}
		j++;
		str++;
	}
	printf("finish store_parts\n");
	return (stored);
}

t_store		**ft_create_store(char *str, int shape_count)
{
	int		i;
	t_store	**store;
	t_store	**head;

	i = 0;
//	printf("create_store start\nshape_count = [%i]\n", shape_count);
	if (shape_count == 0)
		return (0);
	else
		if (!(store = (t_store**)malloc(sizeof(t_store*) * (shape_count + 1))))
			return (0);	
	store[shape_count + 1] = 0;
	head = store;
//	printf("head store\n");
	while (i < shape_count)
	{
		printf("starting [%i]\n", i);
//		printf("store[i] going i = %i\n", i);
		if (!(store[i] = (t_store*)malloc(sizeof(t_store) * (1))))
			return (0);
		if (!(store[i]->stored = (t_container**)malloc(sizeof(t_container*) * (5))))
			return (0);
		printf("before store_parts shape [%i]\n", i);
		ft_store_parts(store[i]->stored, str + (i * 21));
		printf("started xx\n");
		store[i]->stored[4] = 0;
		store[i]->marked = 'N';		//created shape marked N for not placed by default
		i++;
	}
//	printf("start store_auto\n");
//	ft_store_auto(head, str);
	printf("end storeauto\n");
	return (head);	
}

//		leave print_store + MAIN  function here for testing

void		ft_print_store(t_store **store, int count)
{
	int		i;
	int		j;
	int		count_str; //str

	i = 0;
	j = 0;
	count_str = 0;
	printf("start print\n");
	while (i < count)
	{
		printf("store[shape] = %i\n", i);
		while (j < 4)
		{
			printf("shape [%i], hash# [%i], value [%i]\n", i, j, store[i]->stored[j]->x);
			printf("shape [%i], hash# [%i], value [%i]\n", i, j, store[i]->stored[j]->y);
			j++;
	//		printf("[%i]\n", count_str);
			count_str++;
		}
		printf("shape [%i] marked [%c]\n", i, store[i]->marked);
		j = 0;
		printf("\n");
		i++;
	}
	if (store[i] == 0)
		printf("shape [%i] [\\0]\n", i);
	return ;
}
