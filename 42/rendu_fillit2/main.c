/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:10:07 by pibenoit          #+#    #+#             */
/*   Updated: 2016/01/04 13:29:21 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	ft_taille_min(char tab[27])
{
	int		taille;
	int		i;

	taille = ft_sqrt(4 * tab[0]);
	i = 1;
	while (tab[i] != 0)
	{
		if ((tab[i] == 1 || tab[i] == 19) && taille < 4)
			taille = 4;
		else if (tab[0] == 1 && tab[i] == 6)
			return (2);
		i++;
	}
	if (taille > 3)
		return (taille);
	return (3);
}

void	ft_file(const char *str_in, char buffer[547], char tab[27])
{
	int		fd;
	int		cpt;

	ft_bzero(buffer, 547);
	ft_bzero(tab, 27);
	fd = open(str_in, O_RDONLY);
	if (fd == -1)
		ft_ragequit();
	cpt = read(fd, buffer, 547);
	if (cpt == -1 || cpt >= 546)
		ft_ragequit();
	buffer[cpt + 1] = '\0';
	close(fd);
	ft_erreur(buffer);
	ft_search(buffer, tab);
}

char	**ft_debut(int cpt[4], char save[16][16], char tab[27])
{
	cpt[0] = 1;
	cpt[1] = ft_sqrt(8 * tab[0]);
	cpt[2] = ft_taille_min(tab);
	if (cpt[1] < cpt[2])
		cpt[1]++;
	ft_clean(save, 15);
	return (ft_init(cpt[1]));
}

void	ft_ragequit(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int		main(int argc, char **argv)
{
	char	buffer[547];
	char	**map;
	char	save[16][16];
	char	tab[27];
	int		cpt[4];

	if (argc != 2)
		ft_ragequit();
	ft_file(argv[1], buffer, tab);
	map = ft_debut(cpt, save, tab);
	while (cpt[0] == 1 && cpt[1] >= cpt[2])
	{
		cpt[0] = ft_treatment(map, save, tab, 1);
		cpt[3] = 0;
		while (cpt[1] > cpt[2] && !cpt[3] && cpt[0] == 2)
		{
			cpt[1]--;
			map = ft_init(cpt[1]);
			cpt[3] = ft_test_point(map);
			cpt[0] = 1;
		}
	}
	ft_exit(save, ft_len_save(save));
	return (0);
}
