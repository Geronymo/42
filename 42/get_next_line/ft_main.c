/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 17:50:25 by pibenoit          #+#    #+#             */
/*   Updated: 2016/01/11 14:21:53 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putendl_gnl(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	char	end;

	end = 1;
	fd = 0;
	if (ac == 1 || ac == 2)
	{
		if (ac == 2)
			fd = open(av[1], O_RDONLY);
		while (end == 1)
//		while (get_next_line(fd, &line) == 1)	
		{
			end = get_next_line(fd, &line);
//			if (line[0] != '\0')
//			{
				ft_putendl_gnl(line);
				if (ft_strcmp(line, "mnopqrstuvwxyzab") == 0)
					write(1, "ok\n", 3);
				if (ft_strcmp(line, "efghijkl") == 0)
					write(1, "ok\n", 3);
//			}
			if (line != NULL)
				free(line);
		}
		if (ac == 2)
			close(fd);
	}
	else
		ft_putendl_gnl("Error");
	return (0);
}
