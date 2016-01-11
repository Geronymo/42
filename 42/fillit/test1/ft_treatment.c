/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:29:03 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/21 21:36:03 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>


int		ft_deplace(char **map, char figure, char letter, int tab[3])
{
	ft_del(map, letter, tab[2]);
	if (tab[1] < tab[2] - 1)
		tab[1] += 1;
	else if (tab[0] < tab[2] - 1)
	{
		tab[0]++;
		tab[1] = 0;
	}
	else
		return (0);
	return (ft_place(map, figure, letter, tab));
}

void	ft_copy(char **map, char save[16][16], char taille)
{
	int	i;
	int	j;

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

int		ft_try_copy(char **map, char save[16][16], int taille)
{
	int				letter;
	int				i;

	i = 0;
	letter = 91;
	while (i < taille)
	{
		if (save[i][taille - 1] < letter && save[i][taille - 1] != 46)
			letter = save[i][taille - 1];
		if (save[taille - 1][i] < letter && save[taille - 1][i] != 46)
			letter = save[taille - 1][i];
		i++;
	}
	ft_select_copy(map, save, taille, letter);
	i = letter;
	return (i - 64);
}

void	ft_select_copy(char **m, char s[16][16], int t, int l)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < (unsigned int)t - 1)
	{
		while (j < (unsigned int)t - 1)
		{
			if (s[i][j] < l)
				m[i][j] = s[i][j];
			else if (s[i][j] >= l)
				m[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_clean(char s[16][16], int taille)
{
	int	i;
	int	j;

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

int		ft_save(char **ptr_map, char ptr_map_saved[16][16], char taille, char nb_figure)
{
	unsigned int	i;
	unsigned int	j;
	int				cpt;

	i = 0;
	j = 0;
	cpt = 0;
	ft_clean(ptr_map_saved, (int)taille);
	ft_copy(ptr_map, ptr_map_saved, taille);
	ft_free(ptr_map);
	if (taille > ft_sqrt(nb_figure * 4))
		return (nb_figure);
	return (-1);
}
int		ft_len_save(char s[16][16])
{
	int	j;

	j = 0;
	while (s[0][j] != '\n')
		j++;
	return (j);
}

int		ft_len(char **ptr_map)
{
	int j;

	j = 0;
	while (ptr_map[0][j] != '\0')
		j++;
	return (j);
}

void	ft_del(char **ptr_map, char letter, char taille)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	cpt_letter;

	cpt_letter = 0;
	i = 0;
	j = 0;
	while (i < (unsigned int)taille && cpt_letter < 3)
	{
		while (j < (unsigned int)taille && cpt_letter < 3)
		{
			if (ptr_map[i][j] == letter)
			{
				ptr_map[i][j] = '.';
				cpt_letter++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int		ft_treatment(char **ptr_map, char ptr_map_saved[16][16], char order_figure[27], int i)
{
	int		pos[3];
	int		end;

	end = 0;
	pos[0] = 0;
	pos[1] = 0;
	pos[2] = ft_len(ptr_map);
	if (ft_place(ptr_map, order_figure[i], ((char)i + 64), pos))
	{
		if (i == order_figure[0])
		{
			end = ft_save(ptr_map, ptr_map_saved, pos[2], order_figure[0]);
		}
		else
		{
			while (!end)
			{
					end = ft_treatment(ptr_map, ptr_map_saved, order_figure, (i + 1));
					if (end < 26 && end >= 0)
					{
						if (!ft_deplace(ptr_map, order_figure[i], (i + 64), pos))
						{
							ft_del(ptr_map, (i + 64), pos[2]);
							end = 1;
						}
					}
			}
		}
	}
	else
		return (0);
	return (end - 1);
}
