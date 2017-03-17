/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:50:10 by wfung             #+#    #+#             */
/*   Updated: 2017/03/16 20:17:26 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{	
	int		fd;
	char	*str;
	int		n;
	t_grid	**buff;
	t_store	**hey;
	int		x;

	if (ac != 2)
	{
		printf("arg count = [%i] (if != [2]; fail)\n", ac);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (500));
	n = 2;
	fd = open(av[1], O_RDONLY);
	while (read(fd, str, 500))
	{
		printf("main str =\n%s\n", str);
		if (ft_chk_input1(str) == 1)
		{
			printf("chk_input COMPLETE!\n");
			if (ft_matchx(str) == 1)
			{
				x = ft_count_shapes(str);
				printf("matchx passed\n");
				hey = ft_create_store(str, x);
				ft_print_store(hey, x);
				while (n < 5)
				{
					buff = ft_makegrid(n);
					ft_fillblank(buff, n);
					ft_print_grid(buff);
					if (ft_fit2(buff, hey) == 0)
					{
						printf("fit2 failed on [%i x %i] grid\n", n, n);
						n++;
					}
					else
					{
						printf("fit2 all shapes fit!\n");
						ft_print_grid(buff);
					}
				}
			}
			else
				printf("shape_chk fail\n");
		}
		else
			printf("fail chk_input\n");
	}
	return (0);
}
