/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:52:08 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/21 19:25:08 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "fillit.h"

//_________________________________________________________________
//lecture de fichiers (ouverture/lecture/fermeture)

void	ft_file(const char *str_in, char BUF[547])
{
	int		BUF_SIZE;
	int		fd;
	int		cpt;

	ft_bzero(BUF, 547);
	BUF_SIZE = 547;
	fd = open(str_in, O_RDONLY);
	cpt = read(fd, BUF, BUF_SIZE);
	if (cpt == -1)
		ft_ragequit();
	BUF[cpt + 1] = '\0';
	close(fd);
}
//exit(0);
//______________________________________________________________

void	ft_ragequit(void)
{
	write(1, "erreur\n", 7);
	exit(0);
}
/*
//________________________________________________________________
int	main(int argc, char **argv)
{
	char	BUF[547];
	char	order_figure[27];
	char	error;
//	char	**ptr_map;
//	char	**ptr_map_saved;

	error = 0;
	if (argc != 2)
		ft_ragequit();
	ft_bzero(order_figure, 27);
	ft_file(argv[1], BUF);
	ft_erreur(BUF);
	error = ft_search(BUF, order_figure);
	if (error)
		ft_ragequit();
//	ptr_map = ft_init(ft_sqrt((unsigned char)(8 * order_figure[0])));
//	ptr_map_saved = ft_init(ft_sqrt((unsigned char)(8 * order_figure[0])));
//	write(1, "aucune erreur\n", 14);
//	while (error >= 0)
//		error =	ft_treatment(ptr_map, ptr_map_saved, order_figure, 1);
//	ft_exit(ptr_map_saved, ft_len(ptr_map));
	return (0);
}*/
