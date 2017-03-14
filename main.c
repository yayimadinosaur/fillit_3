/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:50:10 by wfung             #+#    #+#             */
/*   Updated: 2017/03/13 18:35:03 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{	
	int		fd;
	char	*str;
	int		n;
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
		}
		else
			printf("fail chk_input\n");
	}
	return (0);
}





/*
	if (ft_chk_input(str) == 1)
	{
		printf("main: chk_input finished\n-----\n");
		if (ft_matchx(str) == 1)
		{
//			printf("-----\nmatchx passed\n");
			if (ft_count_shapes(str) > 0)
			{
//				printf("-----\ncount_shapes passed\n-----\n# of shapes = %i\n", ft_count_shapes(str));
				ft_print_store(ft_create_store(str, ft_count_shapes(str)), ft_count_shapes(str));
//				printf("\n$$$$$$$$$$$$$$$$$$$i$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		//extra		ft_print_grid(ft_makegrid(n));
//				printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
			//	while (ft_fit(ft_fillblank(ft_makegrid(n), n), ft_create_store(str, ft_count_shapes(str)), ft_count_shapes(str)) != 1)
				while (n < 5)
				{
					ft_print_grid(ft_makegrid(n));
	//old fit		if (ft_fit((ft_makegrid(n)), ft_create_store(str, ft_count_shapes(str)), ft_count_shapes(str)) != 1)
					//if (n == 5)
					//	break;
					if (ft_fit1(ft_makegrid(n), ft_create_store(str, ft_count_shapes(str)), n) != 1)
					printf("FIT TOO SMALL !!!! [%i]\n", n);
					n++;
				}
			//	if (ft_fit(ft_fillblank(ft_makegrid(n), n), ft_create_store(str, ft_count_shapes(str)), ft_count_shapes(str)) == 1)
			//		printf("done recursion? n = [%i]\n", n);
			//	else
			//		printf("fail recursion! n = [%i]\n", n);
			}
			else
			{
				printf("*****\ncount_shapes failed\n*****\n");
				return (0);
			}
		}
		else
			printf("*****\nfailed match =(\n*****\n");
	}
	else
	{
		printf("*****\nmain: fail chk_input\n*****\n");
	}
	printf("total strlen is %zu\n", ft_strlen(str));
	return (0);
}

*/




