/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shape_chk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:36:17 by wfung             #+#    #+#             */
/*   Updated: 2017/02/27 20:23:59 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_shape1(char *x)
{
	char	y;
	int		i;

	y = '#';
	i = 0;
	if (x[i] == y && x[i + 1] == y && x[i + 2] == y && x[i + 3] == y)
	{
		printf("yay1\n####\n....\n....\n....\n");	//####\n				
		return (1);
	}
	else if (x[i] == y && x[i + 5] == y && x[i + 10] == y && x[i + 15] == y)
	{												//#...\n
		printf("yay2\n#...\n#...\n#...\n#...\n");	//#...\n
		return (2);									//#...\n
	}												//#...\n
	else if (x[i] == y && x[i + 1] == y && x[i + 5] == y&& x[i + 6] == y)
	{
		printf("yay3\n##..\n##..\n....\n....\n");	//##..\n
		return (3);									//##
	}
	else if (x[i] == y && x[i + 1] == y && x[i + 2] == y&& x[i + 6] == y)
	{
		printf("yay4\n###.\n.#..\n....\n....\n");	//###.\n
		return (4);									//.#
	}
	else if (x[i] == y && x[i + 5] == y && x[i + 6] == y&& x[i + 10] == y)
	{
		printf("yay5\n#...\n##..\n#...\n....\n");	//#...\n
		return (5);									//##..\n
	}												//#
	else if (x[i] == y && x[i + 4] == y && x[i + 5] == y&& x[i + 10] == y)
	{
		printf("yay6\n.#..\n##..\n.#..\n....\n");	//.#..\n
		return (6);									//##..\n
	}												//.#
	else if (x[i] == y && x[i + 4] == y && x[i + 5] == y&& x[i + 6] == y)
	{
		printf("yay7\n.#..\n###.\n....\n....\n");	//.#..\n
		return (7);									//###
	}
	else if (x[i] == y && x[i + 1] == y && x[i + 6] == y&& x[i + 7] == y)
	{
		printf("yay8\n##..\n.##.\n....\n....\n");	//##..\n
		return (8);									//.##
	}
	else if (x[i] == y && x[i + 4] == y && x[i + 5] == y&& x[i + 9] == y)
	{

		printf("yay9\n.#..\n##..\n#...\n....\n");	//.#..\n
		return (9);									//##..\n
	}												//#
	else if (x[i] == y && x[i + 1] == y && x[i + 4] == y&& x[i + 5] == y)
	{
		printf("yay10\n..##\n.##.\n....\n....\n");	//.##.\n
		return (10);								//##
	}
	else if (x[i] == y && x[i + 5] == y && x[i + 6] == y&& x[i + 11] == y)
	{
		printf("yay11\n#...\n##..\n.#..\n....\n");	//#...\n
		return (11);								//##..\n
	}												//.#
	else
	{
		printf("shape1 fail\n");
		return (0);
	}
}

int		ft_shape2(char *x)
{
	char	y;
	int		i;

	y = '#';
	i = 0;
	if (x[i] == y && x[i + 5] == y && x[i + 10] == y&& x[i + 11] == y)
	{
		printf("yay12\n#...\n#...\n##..\n....\n");	//#...\n
		return (12);								//#...\n
	}												//##
	else if (x[i] == y && x[i + 3] == y && x[i + 4] == y&& x[i + 5] == y)
	{
		printf("yay13\n..#.\n###.\n....\n....\n");	//..#.\n
		return (13);								//###
	}
	else if (x[i] == y && x[i + 1] == y && x[i + 6] == y&& x[i + 11] == y)
	{
		printf("yay14\n##..\n.#..\n.#..\n....\n");	//##..\n
		return (14);								//.#..\n
	}												//.#
	else if (x[i] == y && x[i + 1] == y && x[i + 2] == y&& x[i + 5] == y)
	{
		printf("yay15\n###.\n#...\n....\n....\n");	//###.\n
		return (15);								//#
	}
	else if (x[i] == y && x[i + 5] == y && x[i + 9] == y&& x[i + 10] == y)
	{
		printf("yay16\n.#..\n.#..\n##..\n....\n");	//.#..\n
		return (16);								//.#..\n
	}												//##
	else if (x[i] == y && x[i + 5] == y && x[i + 6] == y&& x[i + 7] == y)
	{
		printf("yay17\n#...\n###.\n....\n....\n");	//#...\n
		return (17);								//###
	}
	else if (x[i] == y && x[i + 1] == y && x[i + 5] == y&& x[i + 10] == y)
	{
		printf("yay18\n##..\n#...\n#...\n....\n");	//##..\n
		return (18);								//#...\n
	}												//#
	else if (x[i] == y && x[i + 1] == y && x[i + 2] == y&& x[i + 7] == y)
	{
		printf("yay19\n###.\n..#.\n....\n....\n");	//###.\n
		return (19);								//..#
	}
	else
	{
		printf("shape2 fail\n");
		return (0);
	}
}

int		ft_shape_chk(char *x)
{
	if (ft_shape1(x) == 0 && ft_shape2(x) == 0)
	{
		printf("ft_shape_chk failed!! =(\n");
		return(0);
	}
	else
	{
		printf("ft_shape_chk passed! =D\n");
		return (1);
	}
}
