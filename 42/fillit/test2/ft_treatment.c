/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:29:03 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/24 00:11:01 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <string.h>
#include <unistd.h>

int		ft_deplace(char **map, char figure, char letter, int pos[3])
{
	if (!(ft_del(map, letter, pos[2])))
	{
		if (pos[1] < pos[2] - 1)
			pos[1] += 1;
		else if (pos[0] < pos[2] - 1)
		{
			pos[0]++;
			pos[1] = 0;
		}
		else
			return (0);
	}
	return (ft_place(map, figure, letter, pos));
}

int		ft_len_save(char s[16][16])
{
	int		j;

	j = 0;
	while (s[0][j] != '\n')
		j++;
	return (j);
}

int		ft_len(char **map)
{
	int j;

	j = 0;
	while (map[0][j] != '\0')
		j++;
	return (j);
}

char	ft_del(char **map, char letter, char taille)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < (unsigned int)taille)
	{
		while (j < (unsigned int)taille)
		{
			if (map[i][j] == letter)
				map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		ft_treatment(char **map, char save[16][16], char tab[27], int i)
{
	int		pos[3];
	int		end;

	end = 0;
	ft_cpt(pos, 2);
	pos[2] = ft_len(map);
	if (ft_place(map, tab[i], ((char)i + 64), pos))
	{
		if (i == tab[0])
			return (ft_save(map, save, pos[2], tab[0]));
		while (!end)
		{
			end = ft_treatment(map, save, tab, (i + 1));
			if (end == 0)
			{
				if (!ft_deplace(map, tab[i], (i + 64), pos))
					return (ft_del(map, (i + 64), pos[2]));
			}
			else
				return (end - 1);
		}
	}
	return (0);
}
