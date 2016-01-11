/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:48:11 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/24 00:09:29 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fillit.h"
#include <unistd.h>
#include <stdio.h>

int		ft_sqrt(unsigned char nb)
{
	char i;

	i = 2;
	if (nb == 0)
		return (0);
	if (nb == 1)
		return (1);
	while ((i * i) < nb)
		i++;
	return (i);
}

void	ft_free(char **ptr)
{
	int i;

	i = ft_len(ptr) - 1;
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	ptr = NULL;
}

void	ft_free_bis(char **ptr, int i)
{
	while (i >= 1)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

void	ft_point(char **map, char taille)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < (unsigned int)taille)
	{
		while (j < ((unsigned int)taille + 1))
		{
			if (j == (unsigned int)taille)
				map[i][j] = '\0';
			else
				map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

char	**ft_init(char taille)
{
	int		i;
	char	**ptr;

	i = 0;
	ptr = (char**)malloc(sizeof(char*) * taille);
	if (ptr == NULL)
		ft_ragequit();
	while (i < taille)
	{
		ptr[i] = (char*)malloc(sizeof(char) * (taille + 1));
		if (ptr[i] == NULL)
		{
			ft_free_bis(ptr, i);
			ft_ragequit();
		}
		i++;
	}
	ft_point(ptr, taille);
	return (ptr);
}
