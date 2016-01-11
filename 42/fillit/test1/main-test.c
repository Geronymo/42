/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:10:07 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/21 21:35:25 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char BUF[547];
	char **map;
	char save[16][16];
	char tab[27];
	char end;
	int	 taille;
	int cpt;

	
	if (argc != 2)
		ft_ragequit();
	ft_bzero(tab, 27);
	ft_file(argv[1], BUF);
	ft_erreur(BUF);
	ft_search(BUF, tab);
	taille = ft_sqrt(8 * tab[0]);
	map = ft_init(taille);
	ft_clean(save, 15);
	cpt = 1;
	end = 0;
	while (end == 0 && taille >= ft_sqrt(4 * tab[0]))
	{
		end = ft_treatment(map, save, tab, cpt);
		if (taille > ft_sqrt(4 * tab[0]))
		{
			taille--;
			map = ft_init(taille);
			cpt = ft_try_copy(map, save, taille);
		}
	}
	ft_exit(save, ft_len_save(save));
	return (0);
}
