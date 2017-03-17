/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:34:45 by wfung             #+#    #+#             */
/*   Updated: 2017/03/17 15:18:06 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>		//malloc free exit 
# include <fcntl.h>			//open
# include <unistd.h>		//close write
# include <sys/uio.h>		//read

# include <stdio.h>					//remove later, for printf

typedef struct			s_grid			//struct for grid
{
	char				content;
}						t_grid;

typedef struct			s_container
{
	int					x;
	int					y;
}						t_container;

typedef	struct			s_store			//struct for stored array for shape parsing
{
	int					shape;
	char				marked;
	t_container			**stored;
}						t_store;

/*		UNUSED OLD STRUCT
typedef	struct			s_save1
{
	int					placed;
	struct	s_container	**container;

}					t_save1;
*/

void		ft_putstr(char *str);	//for printing grid within norm
void		ft_putchar(char c);

int			ft_match1(char *str);	//??? what is this for

int			ft_shape1(char *start);
int			ft_shape2(char *start);
int			ft_shape_chk(char *start);

size_t		ft_strlen(const char *s);


int			ft_matchx(char *str);

int			ft_chk_input(char *str);
int			ft_chk_char(char *str);
int			ft_chk_count(char *str, int i, int j, int k);

//char		*ft_shape_letter(char *str, int n);

int			ft_count_shapes(char *str);

t_grid		**ft_makegrid(int n);
void		ft_fillblank(t_grid **grid, int n);		//notsure if needed in header (STATIC?)
void		ft_print_grid(t_grid **grid);

/*		NOT SURE IF NEEDED / USED?
int			ft_fit1(t_grid **grid, t_store **store, int grid_range);
int			ft_scan_grid1(t_grid **grid, int stored_index, int grid_range, int z);
void		ft_place1(t_grid **grid, t_store **store, int k, int grid_range);
*/
void		ft_print_save(t_grid ***array);
t_grid		***ft_save(char *str, int shape_count);
void		ft_addpieces(t_grid **array, char *str_start);

int		ft_chk_input1(char *str);
int		ft_chk_char1(char *str);
int		ft_chk_count1(char *str, int i, int j, int k);
int		ft_chk_block1(char *str);

void	ft_print_store(t_store **store, int count);
t_store	**ft_create_store(char *str, int shape_count);
t_container	**ft_store_parts(t_container **stored, char *str);

/* OLD PLACE?
void	ft_place1(t_grid **grid, t_store **store, int k, int grid_range);
int		ft_scan_grid1(t_grid **grid, int stored_index, int grid_range, int z);
int		ft_fit1(t_grid **grid, t_store **store, int grid_range);
*/

/*	NOT USING FOR NOW
int		ft_fit2(t_grid **grid, t_store **store);
int		ft_chk_pts2(t_grid **grid, int i, int j, t_store **store);
int		ft_chk_mark(t_store **store);
int		ft_chk_index(t_grid **grid, int j, t_store **store, t_store s_index);
int		ft_place2(t_store **store, );
int		ft_remove();
*/

int		ft_grid_iter(t_grid **grid, t_store **store);
int		ft_chk_pts3(t_grid **grid, int i, int j, t_store **store);
void	ft_place3(t_grid **grid, int i, int j, t_store **store);

#endif

//NOTE : CANNOT USE NULL
