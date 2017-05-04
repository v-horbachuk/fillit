/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:26:23 by vhorbach          #+#    #+#             */
/*   Updated: 2017/02/10 21:09:12 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_mino		*search_cords_2(t_mino *tetri, int x, int y, int i)
{
	int		z;
	int		a;

	z = 0;
	a = 0;
	while (z < 21)
	{
		if (tetri[i].str[z] == '#')
		{
			tetri[i].x[a] = x;
			tetri[i].y[a] = y;
			tetri[i].letter[a] = 65 + i;
			a++;
		}
		x++;
		if (tetri[i].str[z] == '\n')
		{
			x = 0;
			y++;
		}
		z++;
	}
	return (tetri);
}

void		search_cords_1(t_mino *tetri, int n)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < n)
	{
		y = 0;
		x = 0;
		tetri = search_cords_2(tetri, x, y, i);
		free(tetri[i].str);
		i++;
	}
	grid_alloc(grid_size(n), tetri, n);
}

void		ft_struct(char *string, int n)
{
	int		i;
	int		k;
	int		j;
	t_mino	tetri[n];

	k = 0;
	i = 0;
	while (i < n)
	{
		tetri[i].str = (char *)malloc(sizeof(char) * 21);
		j = 0;
		while (j < 20)
		{
			tetri[i].str[j] = string[k];
			j++;
			k++;
		}
		tetri[i].str[j] = '\0';
		k++;
		i++;
	}
	search_cords_1(tetri, n);
}
