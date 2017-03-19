/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:50:10 by wfung             #+#    #+#             */
/*   Updated: 2017/03/18 20:45:10 by wfung            ###   ########.fr       */
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
	n = 6;
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
				while (n < 11)
				{
					printf("			main passing n = [%i]		\n", n);
					buff = ft_makegrid(n);
				//	ft_fillblank(buff, n);		redundent
					ft_print_grid(buff);
					printf("main finished print_grid\n");
					if (ft_grid_iter(buff, hey, n) == 1)	//ft_fit3
					{
						ft_print_grid(buff);
						free(buff);
						free(hey);
						printf("fit3 success! via [%i x %i] grid\n", n, n);
						return (0);
					}
					else
					{
						ft_print_grid(buff);
						free(buff);
						printf("grid too small, freed grid size of [%i]\n", n);
						n++;
					}
				}
			}
			else
			{
				printf("shape_chk fail\n");
				return (0);
			}
		}
		else
		{
			printf("fail chk_input\n");
			return (0);
		}
	}
	return (0);
}
