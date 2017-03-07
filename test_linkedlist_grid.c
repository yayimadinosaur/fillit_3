#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct		s_list
{
	char			content;
	size_t			content_size;
	struct	s_list	*next;
}					t_list;

typedef struct		s_store
{
	int				shape;		//shape
	char			alpha;		//letter
	int				used;		//1 = used 0 = not used
	struct	s_list	*next;
}					t_store;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

t_list	**ft_makegrid(int n)
{
	t_list	**head;
	t_list	**buff;
	int		i;

	i = 0;
	printf("start [makegrid]\n-----\n");
	if (!(buff = (t_list**)malloc(sizeof(t_list*) * (n + 1))))
		return (0);
	head = buff;
	while (i < n)
	{
		printf("created row %i\n", i);
		if (!(buff[i] = (t_list*)malloc(sizeof(t_list) * (n + 1))))
			return (0);
	//	buff[i]->content = '.';
		i++;
	}
	buff[i] = 0;
	printf("finished [makegrid]\n-----\n");
	return (head);
}

t_list	**ft_fillblank(t_list **grid, int n)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 46;
	printf("start [fillblank]\n-----\n");
	while (i < n)
	{
		while (j < n)
		{
		//	printf("i is currently %i\n", j);
			(grid[i][j]).content = k;
			j++;
	//		k++;
		}
		if (j == 5)
			grid[i][j].content = 0;			//it was never set to null
		j = 0;
		i++;
	}
	printf("i is now %i\n", i);
//	printf("test\n");			code breaks here
//	grid[i]->content = '\0';				this breaks the code
	printf("end [fillblank]\n-----\n");
	return (grid);
}


/*
 * t_list		**ft_insertshape(t_list **grid, t_list **stored_shapes)
{

}
*/

void	ft_print_grid(t_list **grid)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("start [print_grid]\n-----\n");
	while (grid[i] != 0)
	{
	//	printf("{%i}", i);					//printfs x axis
		while (grid[i][j].content != 0)
		{
	//		printf("(%i)%c", j, grid[i][j].content);
	//		if (grid[i][j].content != '.')
	//			printf("[F]");
	//		else if (grid[i][j].content == '.')
	//			printf("[ok]");
	//		else
	//			printf("[random]");
	//		printf("[%i]%c", j, grid[i][j].content);		//prints y axis
			printf("[%c]", grid[i][j].content);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
/*	while (grid[i] != 0)
	{
		ft_putchar('[');
		ft_putchar(grid[i]->content);
		ft_putchar(']');
	//	ft_putstr((char*)&grid[i] + 48);		//print address of linkedlist (type to char)
	//	ft_putchar('\n');
	//	printf("[%c][%p]\n", grid[i]->content, &grid[i]);
		i++;
	}
	if (grid[i] == 0)			//this causes x to print first
//		printf("[x]\n");			//removing printf to test putchar
	{
		ft_putchar('[');
		ft_putchar('\\');
		ft_putchar('0');
		ft_putchar(']');
		ft_putchar('\n');
	//	printf("%p\n", &grid[i]);
	//	ft_putchar('\n');
	}
*/	printf("-----\nend [print_grid]\n-----\n");
	return ;
}

int		main(void)
{
	int		n;

	n = 2;

	while (n < 10)
	{
		ft_print_grid(ft_fillblank(ft_makegrid(n), n));
		n++;
	}
	return (0);
}

//make grid can grow depending on the passed in n variable
