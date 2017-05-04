/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:29:58 by vhorbach          #+#    #+#             */
/*   Updated: 2017/02/10 14:32:25 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validate_3_1(char *tetriminka)
{
	int i;
	int valid;

	valid = 0;
	i = 0;
	while (tetriminka[i])
	{
		if (tetriminka[i] == '#')
		{
			if ((i + 1) < 20 && tetriminka[i + 1] == '#')
				valid++;
			if ((i - 1) >= 0 && tetriminka[i - 1] == '#')
				valid++;
			if ((i + 5) < 20 && tetriminka[i + 5] == '#')
				valid++;
			if ((i - 5) >= 0 && tetriminka[i - 5] == '#')
				valid++;
		}
		i++;
	}
	if (valid == 8 || valid == 6)
		return (1);
	return (0);
}

void	validate_3(char *str)
{
	int		i;
	int		n;
	int		j;
	char	*tetreminka;

	n = 0;
	j = 0;
	while (str[j])
	{
		i = 0;
		tetreminka = (char *)malloc(sizeof(*str) * 21);
		while (str[j] && i <= 20)
		{
			tetreminka[i] = str[j];
			i++;
			j++;
		}
		if (!validate_3_1(tetreminka))
			say_error();
		else
			n++;
		free(tetreminka);
	}
	ft_struct(str, n);
}

int		validate_2_1(char *str, int i)
{
	int	new_line;
	int	hash;
	int	dot;
	int k;

	new_line = 0;
	hash = 0;
	dot = 0;
	k = 0;
	while (k <= 19)
	{
		if (str[i] == '#')
			hash++;
		else if (str[i] == '.')
			dot++;
		else if (str[i] == '\n')
			new_line++;
		i++;
		k++;
	}
	if (hash == 4 && dot == 12 && new_line == 4)
		return (1);
	else
		say_error();
	return (0);
}

void	validate_2(char *str)
{
	int i;
	int all_bytes;

	i = 0;
	all_bytes = ft_strlen(str);
	while (i <= all_bytes)
	{
		if (validate_2_1(str, i))
			i = i + 21;
		else
			say_error();
	}
	if (str[i] == '\n' && (str[i + 1] != '\n' || str[i + 1] != '\0'))
		say_error();
	validate_3(str);
}

void	validate_1(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		say_error();
	while (str[i])
	{
		if (ft_strlen(str) > 545)
			say_error();
		if (str[i] == '.' || str[i] == '#' || str[i] == '\n')
		{
			i++;
		}
		else
			say_error();
	}
	validate_2(str);
}
