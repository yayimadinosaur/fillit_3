/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:34:45 by wfung             #+#    #+#             */
/*   Updated: 2017/03/06 20:55:19 by wfung            ###   ########.fr       */
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

typedef	struct		s_store			//struct for stored array for shape parsing
{
	int				shape;
	char			marked;
	int				*stored;
}					t_store;

void		ft_putstr(char *str);	//for printing grid within norm
void		ft_putchar(char c);

int			ft_match1(char *str);

int			ft_shape1(char *start);
int			ft_shape2(char *start);
int			ft_shape_chk(char *start);

size_t		ft_strlen(const char *s);

//int			ft_strncmp(const char *s1, const char *s2, size_t n);		//not used, remove

int			ft_matchx(char *str);

int			ft_chk_input(char *str);
int			ft_chk_char(char *str);
int			ft_chk_count(char *str, int i, int j, int k);

char		*ft_shape_letter(char *str, int n);

int			ft_count_shapes(char *str);

t_grid		**ft_makegrid(int n);
t_grid		**ft_fillblank(t_grid **grid, int n);		//notsure if needed in header (STATIC?)
void		ft_print_grid(t_grid **grid);

int			ft_fit(t_grid **grid, t_store **store, int grid_range);
int			ft_chk_pts(t_grid **grid, t_store **store, int grid_range, int k);
void		ft_place(t_grid **grid, t_store **store, int grid_range, int k);
//void	ft_lstadd(t_list **alst, t_list *new);							//not used
//t_list	*ft_lstnew(void const *content, size_t content_size);			//not used
//void	*ft_memmove(void *dst, const void *src, size_t len);			//not used
//void	ft_memdel(void **ap);											//not used
//void	*ft_memalloc(size_t size);										//not used

#endif

//CANNOT USE NULL
