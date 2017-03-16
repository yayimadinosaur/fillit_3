/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:00:49 by wfung             #+#    #+#             */
/*   Updated: 2017/03/15 21:05:46 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
int		ft_shape_chk(char *x);
int		ft_count_shapes(char *str);
int		ft_shape1(char *x);
int		ft_shape2(char *x);

typedef struct		s_store
{
	int				shape;
	char			alpha;
	int				*stored;
}					t_store;
*/

//COMMENTED OUT PRINTF IN STORE FOR CLEARER RESULTS

/*commented out USING STORE_AUTO1 now
 * old store_auto works
t_store		**ft_store_auto(t_store **store, char *str)
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
	//		printf("[j] = %i [k] = %i [i] = %i result = [%i]\n", j, k, i, i - k);
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
*/

t_container		*ft_store_parts(t_container *stored, char *str)
{
	int		i;	//counter for piece (4)
	int		j;	//counter

	i = 0;
	j = 0;
	while (*str && i < 4)
	{
		if (*str == '#')
		{
			printf("storing piece %i\n", i);
			printf("check i [%i] j [%i] *str [%c]\n", i, j, *str);
			stored[i].x = j % 5;
			printf("piece [%i] x [%i]\n", i, stored[i].x);		//issue
			stored[i].y = j / 5;
			printf("piece [%i] y [%i]\n", i, stored[i].y);		//issue
			i++;
			printf("finished piece %i\n", i);
		}
		j++;
		str++;
	}
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
	store[shape_count] = 0;
	head = store;
//	printf("head store\n");
	while (i < shape_count)
	{
		printf("starting x\n");
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

	i = 0;
	j = 0;
	printf("start print\n");
	while (i < count)
	{
		while (j < 5)
		{
			printf("shape [%i], hash# [%i], value [%i]\n", i, j, store[i]->stored[j]->x);
			printf("shape [%i], hash# [%i], value [%i]\n", i, j, store[i]->stored[j]->y);
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

