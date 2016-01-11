/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oned.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:54:33 by pbenoit           #+#    #+#             */
/*   Updated: 2015/12/23 23:50:04 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

int		ft_onedtwop_bonus(char **square, char forme, char letter, int tab[3])
{
	if (forme == 12 && (tab[0] + 2) < tab[2])
	{
		if (square[tab[0] + 2][tab[1] - 1] == '.')
		{
			square[tab[0] + 2][tab[1] - 1] = letter;
			square[tab[0]][tab[1]] = letter;
			square[tab[0] + 1][tab[1]] = letter;
			square[tab[0] + 1][tab[1] - 1] = letter;
			return (1);
		}
	}
	else if (forme == 13 && (tab[0] + 2) < tab[2])
	{
		if (square[tab[0] + 2][tab[1]] == '.')
		{
			square[tab[0] + 2][tab[1]] = letter;
			square[tab[0]][tab[1]] = letter;
			square[tab[0] + 1][tab[1]] = letter;
			square[tab[0] + 1][tab[1] - 1] = letter;
			return (1);
		}
	}
	return (0);
}

int		ft_onedtwop(char **square, char forme, char letter, int tab[3])
{
	if (forme == 10 && (tab[1] - 2) >= 0)
	{
		if (square[tab[0] + 1][tab[1] - 2] == '.')
		{
			square[tab[0] + 1][tab[1] - 2] = letter;
			square[tab[0]][tab[1]] = letter;
			square[tab[0] + 1][tab[1]] = letter;
			square[tab[0] + 1][tab[1] - 1] = letter;
			return (1);
		}
	}
	else if (forme == 11 && (tab[1] + 1) < tab[2])
	{
		if (square[tab[0] + 1][tab[1] + 1] == '.')
		{
			square[tab[0] + 1][tab[1] + 1] = letter;
			square[tab[0]][tab[1]] = letter;
			square[tab[0] + 1][tab[1]] = letter;
			square[tab[0] + 1][tab[1] - 1] = letter;
			return (1);
		}
	}
	return (ft_onedtwop_bonus(square, forme, letter, tab));
}

int		ft_one_bonus(char **square, char forme, char letter, int tab[3])
{
	if (forme == 16 && (tab[0] + 2) < tab[2])
	{
		if (square[tab[0] + 2][tab[1] + 1] == '.')
		{
			square[tab[0] + 2][tab[1] + 1] = letter;
			square[tab[0]][tab[1]] = letter;
			square[tab[0] + 1][tab[1]] = letter;
			square[tab[0] + 1][tab[1] + 1] = letter;
			return (1);
		}
	}
	return (0);
}

int		ft_onedthreeptwod(char **square, char forme, char letter, int tab[3])
{
	if (forme == 15 && (tab[0] + 2) < tab[2])
	{
		if (square[tab[0] + 2][tab[1]] == '.')
		{
			square[tab[0] + 2][tab[1]] = letter;
			square[tab[0]][tab[1]] = letter;
			square[tab[0] + 1][tab[1]] = letter;
			square[tab[0] + 1][tab[1] + 1] = letter;
			return (1);
		}
	}
	else if (forme == 14 && (tab[1] + 2) < tab[2])
	{
		if (square[tab[0] + 1][tab[1] + 2] == '.')
		{
			square[tab[0] + 1][tab[1] + 2] = letter;
			square[tab[0]][tab[1]] = letter;
			square[tab[0] + 1][tab[1]] = letter;
			square[tab[0] + 1][tab[1] + 1] = letter;
			return (1);
		}
	}
	return (ft_one_bonus(square, forme, letter, tab));
}

int		ft_onedthreep(char **square, char forme, char letter, int tab[3])
{
	if (forme == 17 && (tab[1] - 1) >= 0)
	{
		if (square[tab[0] + 2][tab[1] - 1] == '.')
		{
			square[tab[0] + 2][tab[1] - 1] = letter;
			square[tab[0]][tab[1]] = letter;
			square[tab[0] + 1][tab[1]] = letter;
			square[tab[0] + 2][tab[1]] = letter;
			return (1);
		}
	}
	else if (forme == 18 && (tab[1] + 1) < tab[2])
	{
		if (square[tab[0] + 2][tab[1] + 1] == '.')
		{
			square[tab[0] + 2][tab[1] + 1] = letter;
			square[tab[0]][tab[1]] = letter;
			square[tab[0] + 1][tab[1]] = letter;
			square[tab[0] + 2][tab[1]] = letter;
			return (1);
		}
	}
	return (ft_onedthreep_bonus(square, forme, letter, tab));
}
