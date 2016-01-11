/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 20:22:12 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/24 00:05:36 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_test_point(char **map)
{
	int i;
	int len;

	i = 0;
	len = ft_len(map) - 1;
	while (i <= len)
	{
		if (map[len][i] != '.' || map[i][len] != '.')
			return (1);
		i++;
	}
	return (0);
}

void	ft_copy(char **map, char save[16][16], char taille)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= (int)taille)
	{
		while (j <= (int)taille)
		{
			if (i == (int)taille || j == (int)taille)
				save[i][j] = '\n';
			else
				save[i][j] = map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_clean(char s[16][16], int taille)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= taille)
	{
		while (j <= taille)
		{
			if (i == taille || j == taille)
				s[i][j] = '\n';
			else
				s[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
}

int		ft_save(char **map, char save[16][16], char taille, char nb_figure)
{
	ft_clean(save, (int)taille);
	ft_copy(map, save, taille);
	ft_free(map);
	if (taille > ft_sqrt(nb_figure * 4))
		return (nb_figure + 1);
	return (-1);
}
