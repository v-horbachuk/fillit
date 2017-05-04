/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:59:48 by vhorbach          #+#    #+#             */
/*   Updated: 2017/02/10 22:04:47 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 545
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_mino
{
	int			x[4];
	int			y[4];
	char		*str;
	char		letter[4];
}				t_mino;

typedef struct	s_grid
{
	int			size;
	char		**grid;
}				t_grid;

int				check_grid(t_grid *map, t_mino *tetri);
char			**fill_grid(t_grid *map, t_mino *tetri, int n_o_t);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
void			ft_struct(char *str, int n);
void			grid_alloc(int i, t_mino *tetri, int n_o_t);
int				grid_size(int n);
t_grid			*put_element(t_grid *map, t_mino *tetri);
void			put_grid(t_grid *map);
char			**remove_element(t_grid *map, t_mino *tetri);
t_mino			*rewrite_cords(t_mino *tetri, int x, int y, int size);
void			say_error(void);
void			search_cords_1(t_mino *tetri, int n);
t_mino			*search_cords_2(t_mino *tetri, int x, int y, int i);
char			**solve(t_grid *map, t_mino *tetri, int k, int n_o_t);
void			validate_1(char *str);
void			validate_2(char *str);
int				validate_2_1(char *str, int i);
void			validate_3(char *str);
int				validate_3_1(char tetreminka[21]);

#endif
