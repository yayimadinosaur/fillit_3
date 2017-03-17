/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:34:45 by wfung             #+#    #+#             */
/*   Updated: 2017/03/16 17:58:39 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>		//malloc free exit 
# include <fcntl.h>			//open
# include <unistd.h>		//close write
# include <sys/uio.h>		//read

# include <stdio.h>					//remove later, for printf

typedef struct		s_grid			//struct for grid
{
	char			content;
//	struct s_list	*next;
}					t_grid;

typedef struct		s_container
{
	int				x;
	int				y;
}					t_container;

typedef	struct		s_store			//struct for stored array for shape parsing
{
	int				shape;
	char			marked;
	t_container		**stored;
/*	int				x0;				//use struct in case stored is **ptr;
	int				y0;
	int				x1;
	int				y1;
	int				x2;
	int				x2;
	int				x3;
	int				y3;*/
}					t_store;

typedef struct		s_save			//testing new struct with *ptr piece that saves x + y of coor
{
	int				placed;			//1 = yes 0 = no
	int				**piece;
}					t_save;

typedef	struct		s_save1
{
	int				placed;
	struct	s_container	**container;
///	int				x;
//	int				y;
}					t_save1;

/* moved struct above to test in ft_store.c
typedef struct		s_container
{
	int				x;
	int				y;
}					t_container;
*/

void		ft_putstr(char *str);	//for printing grid within norm
void		ft_putchar(char c);

int			ft_match1(char *str);

int			ft_shape1(char *start);
int			ft_shape2(char *start);
int			ft_shape_chk(char *start);

size_t		ft_strlen(const char *s);


int			ft_matchx(char *str);

int			ft_chk_input(char *str);
int			ft_chk_char(char *str);
int			ft_chk_count(char *str, int i, int j, int k);

char		*ft_shape_letter(char *str, int n);

int			ft_count_shapes(char *str);

t_grid		**ft_makegrid(int n);
void		ft_fillblank(t_grid **grid, int n);		//notsure if needed in header (STATIC?)
void		ft_print_grid(t_grid **grid);

int			ft_fit1(t_grid **grid, t_store **store, int grid_range);
int			ft_scan_grid1(t_grid **grid, int stored_index, int grid_range, int z);
void		ft_place1(t_grid **grid, t_store **store, int k, int grid_range);

void		ft_print_save(t_grid ***array);
t_grid		***ft_save(char *str, int shape_count);
void		ft_addpieces(t_grid **array, char *str_start);

void	ft_place1(t_grid **grid, t_store **store, int k, int grid_range);
int		ft_scan_grid1(t_grid **grid, int stored_index, int grid_range, int z);
int		ft_fit1(t_grid **grid, t_store **store, int grid_range);
//old	int			ft_fit(t_grid **grid, t_store **store, int grid_range);
//old	int			ft_chk_pts(t_grid **grid, t_store **store, int grid_range, int k);
//old	void		ft_place(t_grid **grid, t_store **store, int grid_range, int k);


int		ft_chk_input1(char *str);
int		ft_chk_char1(char *str);
int		ft_chk_count1(char *str, int i, int j, int k);
int		ft_chk_block1(char *str);

t_save	**ft_save1(char *str, int shape_count);
void	ft_addpieces1(t_save *array, char *str_start);
void	ft_print_save1(t_save **array);

t_save1	**ft_save2(char *str, int shape_count);
void	ft_addpieces2(t_container **array, char *str_start);
void	ft_print_save2(t_save1 **array);
#endif

//CANNOT USE NULL
