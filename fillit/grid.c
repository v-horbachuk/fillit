/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:25:58 by vhorbach          #+#    #+#             */
/*   Updated: 2017/02/10 16:31:00 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			grid_size(int n)
{
	int		i;
	int		k;

	i = 2;
	k = n * 4;
	while (i * i < k)
		i++;
	return (i);
}

char		**fill_grid(t_grid *map, t_mino *tetri, int n_o_t)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < map->size)
	{
		map->grid[i] = (char *)malloc(sizeof(char) * map->size + 1);
		j = 0;
		while (j < map->size)
		{
			map->grid[i][j] = '.';
			j++;
		}
		map->grid[i][j] = '\0';
		i++;
	}
	map->grid[i] = 0;
	if (!(map->grid = solve(map, tetri, k, n_o_t)))
		return (0);
	return (map->grid);
}

void		put_grid(t_grid *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			write(1, &map->grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void		grid_alloc(int size, t_mino *tetri, int n_o_t)
{
	t_grid	*map;

	map = malloc(sizeof(t_grid));
	map->size = size;
	map->grid = (char **)malloc(sizeof(char *) * map->size + 1);
	if (!map->grid)
		say_error();
	while (!(map->grid = fill_grid(map, tetri, n_o_t)))
	{
		free(map->grid);
		map->size++;
		map->grid = (char **)malloc(sizeof(char *) * map->size + 1);
	}
	put_grid(map);
}
