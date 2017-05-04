/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:59:25 by vhorbach          #+#    #+#             */
/*   Updated: 2017/02/11 12:57:09 by akudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		say_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

char		*ft_read(char *name)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		read_ret;
	char	*str;

	fd = open(name, O_RDONLY | S_IREAD);
	if (!fd)
		return (0);
	while ((read_ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_ret] = '\0';
		str = ft_strdup(buf);
	}
	close(fd);
	if (read_ret < 0)
		say_error();
	if (str == 0)
		say_error();
	return (str);
}

int			main(int ac, char **av)
{
	if (ac == 2)
	{
		validate_1(ft_read(av[1]));
	}
	return (0);
}
