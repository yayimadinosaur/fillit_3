/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:50:10 by wfung             #+#    #+#             */
/*   Updated: 2017/03/07 20:57:10 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_store(t_store **store, int count);
t_store	**ft_create_store(char *str, int shape_count);

int		main(void)
{		
	char 	*str;		//passed in str to test
	int		n;

	n = 2;
	str = 
			"####\n"	//5
			"....\n"	//5
			"....\n"	//5
			"....\n";	//5
/*			"\n"		//1			1
			"#...\n"	//5
			"#...\n"	//5
			"#...\n"	//5
			"#...\n"
			"\n"
			"...#\n"
			".###\n"
			"....\n"
			"....\n";	//5

			"\n"		//1			2
			"##..\n"	//5
			"##..\n"	//5
			"....\n"	//5
			"....\n"	//5
			"\n"		//1			3
			"###.\n"	//5
			".#..\n"	//5
			"....\n"	//5
			"....\n"	//5
			"\n"		//			4
			"#...\n"	//5
			"##..\n"	//5
			"#...\n"	//5
			"....\n"	//5
			"\n"		//1			5
			".#..\n"	//5
			"##..\n"	//5
			".#..\n"	//5
			"....\n"	//5
			"\n"		//1			6
			".#..\n"	//5
			"###.\n"	//5
			"....\n"	//5
			"....\n"	//5
			"\n"		//1			7
			"##..\n"	//5
			".##.\n"	//5
			"....\n"	//5
			"....\n"	//5
			"\n"		//1			8
			".#..\n"	//5
			"##..\n"	//5
			"#...\n"	//5
			"....\n"	//5
			"\n"		//1			9
			".##.\n"	//5
			"##..\n"	//5
			"....\n"	//5
			"....\n"	//5
			"\n"		//1			10
			"#...\n"	//5
			"##..\n"	//5
			".#..\n"	//5
			"....\n"	//5
			"\n"		//1			11
			"#...\n"	//5
			"#...\n"	//5
			"##..\n"	//5
			"....\n"	//5
			"\n"		//1			12
			"..#.\n"	//5
			"###.\n"	//5
			"....\n"	//5
			"....\n"	//5
			"\n"		//1			13
			"##..\n"	//5
			".#..\n"	//5
			".#..\n"	//5
			"....\n"	//5
			"\n"		//1			14
			"###.\n"	//5
			"#...\n"	//5
			"....\n"	//5
			"....\n"	//5
			"\n"		//1			15
			".#..\n"	//5
			".#..\n"	//5
			"##..\n"	//5
			"....\n"	//5
			"\n"		//1			16
			"#...\n"	//5
			"###.\n"	//5
			"....\n"	//5
			"....\n"	//5
			"\n"		//1			17
			"##..\n"	//5
			"#...\n"	//5
			"#...\n"	//5
			"....\n"	//5
			"\n"		//1			18
			"###.\n"	//5
			"..#.\n"	//5
			"....\n"	//5
			"....\n"	//5		
						//1			19
			"\n"		//1					20 - 26 are extra for testing
			"###.\n"	//5
			"#...\n"	//5
			"....\n"	//5
			"....\n"	//5
			"\n"		//1			20
			".#..\n"	//5
			".#..\n"	//5
			"##..\n"	//5
			"....\n"	//5
			"\n"		//1			21
			"#...\n"	//5
			"###.\n"	//5
			"....\n"	//5
			"....\n"	//5
			"\n"		//1			22
			"##..\n"	//5
			"#...\n"	//5
			"#...\n"	//5
			"....\n"	//5
			"\n"		//1			23
			"#...\n"	//5
			"###.\n"	//5
			"....\n"	//5
			"....\n"	//5		
			"\n"		//5			24
			"###.\n"	//5
			"..#.\n"	//5
			"....\n"	//5
			"....\n"	//5		
			"\n"		//5			25

			"....\n"
			"....\n"
			"....\n"
			"....\n"
			"";		//1			27
*/
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

/* sample.fillit from fillit pdf

...#$	5
...#$	5
...#$	5
...#$	5
$		1
....$	5
....$	5
....$	5
####$	5
$		1
.###$	5
...#$	5
....$	5
....$	5
$		1
....$	5
..##$	5
.##.$	5
....$	5
$>		1
*/
