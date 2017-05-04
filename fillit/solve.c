/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:22:26 by vhorbach          #+#    #+#             */
/*   Updated: 2017/02/10 22:04:26 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_mino		*rewrite_cords(t_mino *tetri, int x, int y, int size)
{
	int		min_x;
	int		min_y;
	int		i;

	i = 0;
	min_x = size;
	min_y = size;
	while (i < 4)
	{
		if (tetri->x[i] < min_x)
			min_x = tetri->x[i];
		if (tetri->y[i] < min_y)
			min_y = tetri->y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tetri->x[i] = tetri->x[i] - min_x + x;
		tetri->y[i] = tetri->y[i] - min_y + y;
		i++;
	}
	return (tetri);
}

t_grid		*put_element(t_grid *map, t_mino *tetri)
{
	int		x;
	int		y;
	int		i;
	int		m;

	y = 0;
	i = 0;
	m = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (tetri->x[i] == x && tetri->y[i] == y)
			{
				map->grid[y][x] = tetri->letter[m];
				i++;
				m++;
			}
			x++;
		}
		y++;
	}
	return (map);
}

char		**remove_element(t_grid *map, t_mino *tetri)
{
	int		x;
	int		y;
	int		m;

	y = 0;
	m = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (map->grid[y][x] == tetri->letter[m])
				map->grid[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map->grid);
}

int			check_grid(t_grid *map, t_mino *tetri)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (tetri->x[i] == x && tetri->y[i] == y && map->grid[y][x] != '.')
				return (0);
			if (tetri->x[i] == x && tetri->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

char		**solve(t_grid *map, t_mino *tetri, int k, int n_o_t)
{
	int		x;
	int		y;

	y = -1;
	if (k >= n_o_t)
		return (map->grid);
	while (++y < map->size)
	{
		x = -1;
		while (++x < map->size)
		{
			tetri = rewrite_cords(tetri, x, y, map->size);
			if (check_grid(map, tetri))
			{
				map = put_element(map, tetri);
				if (solve(map, ++tetri, ++k, n_o_t))
					return (map->grid);
				else
					map->grid = remove_element(map, --tetri);
				k--;
			}
		}
	}
	return (0);
}
