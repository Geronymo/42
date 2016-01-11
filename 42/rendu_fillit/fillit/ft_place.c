/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:51:31 by pbenoit           #+#    #+#             */
/*   Updated: 2015/12/24 00:11:52 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

int		ft_place1(char **map, char fig, char letter, int t[3])
{
	if (fig > 0 && fig < 5 && (t[1] + 2) < t[2])
	{
		if (map[t[0]][t[1] + 1] == '.' && map[t[0]][t[1] + 2] == '.')
			return (ft_threed(map, fig, letter, t));
	}
	else if (fig > 4 && fig < 8 && (t[0] + 1) < t[2] && (t[1] + 1) < t[2])
	{
		if (map[t[0]][t[1] + 1] == '.' && map[t[0] + 1][t[1]] == '.')
			return (ft_twod(map, fig, letter, t));
	}
	else if (fig > 7 && fig < 10 && (t[0] + 1) < t[2] && (t[1] + 1) < t[2])
	{
		if (map[t[0]][t[1] + 1] == '.' && map[t[0] + 1][t[1] + 1] == '.')
			return (ft_twodi(map, fig, letter, t));
	}
	return (0);
}

int		ft_place2(char **map, char fig, char letter, int t[3])
{
	if (fig > 9 && fig < 14 && (t[0] + 1) < t[2] && (t[1] - 1) >= 0)
	{
		if (map[t[0] + 1][t[1]] == '.' && map[t[0] + 1][t[1] - 1] == '.')
			return (ft_onedtwop(map, fig, letter, t));
	}
	else if (fig > 13 && fig < 17 && (t[0] + 1) < t[2] && (t[0] + 1) < t[2])
	{
		if (map[t[0] + 1][t[1]] == '.' && map[t[0] + 1][t[1] + 1] == '.')
			return (ft_onedthreeptwod(map, fig, letter, t));
	}
	else if (fig > 16 && fig < 20 && (t[0] + 2) < t[2] && t[1] < t[2])
	{
		if (map[t[0] + 1][t[1]] == '.' && map[t[0] + 2][t[1]] == '.')
			return (ft_onedthreep(map, fig, letter, t));
	}
	return (0);
}

int		ft_place(char **map, char fig, char letter, int t[3])
{
	while (t[0] < t[2])
	{
		while (t[1] < t[2])
		{
			if (map[t[0]][t[1]] == '.')
			{
				if (fig > 0 && fig < 10 && ft_place1(map, fig, letter, t))
					return (1);
				else if (fig > 9 && fig < 20 && ft_place2(map, fig, letter, t))
					return (1);
			}
			t[1]++;
		}
		if (t[1] == t[2])
		{
			t[1] = 0;
			t[0]++;
		}
	}
	return (0);
}

int		ft_threed_bonus(char **map, char fig, char letter, int t[3])
{
	if (fig == 3 && (t[0] + 1) < t[2])
	{
		if (map[t[0] + 1][t[1] + 1] == '.')
		{
			map[t[0] + 1][t[1] + 1] = letter;
			map[t[0]][t[1]] = letter;
			map[t[0]][t[1] + 1] = letter;
			map[t[0]][t[1] + 2] = letter;
			return (1);
		}
	}
	else if (fig == 4 && (t[0] + 1) < t[2])
	{
		if (map[t[0] + 1][t[1] + 2] == '.')
		{
			map[t[0] + 1][t[1] + 2] = letter;
			map[t[0]][t[1]] = letter;
			map[t[0]][t[1] + 1] = letter;
			map[t[0]][t[1] + 2] = letter;
			return (1);
		}
	}
	return (0);
}

int		ft_threed(char **map, char fig, char letter, int t[3])
{
	if (fig == 1 && (t[1] + 3) < t[2])
	{
		if (map[t[0]][t[1] + 3] == '.')
		{
			map[t[0]][t[1] + 3] = letter;
			map[t[0]][t[1]] = letter;
			map[t[0]][t[1] + 1] = letter;
			map[t[0]][t[1] + 2] = letter;
			return (1);
		}
	}
	else if (fig == 2 && (t[0] + 1) < t[2])
	{
		if (map[t[0] + 1][t[1]] == '.')
		{
			map[t[0] + 1][t[1]] = letter;
			map[t[0]][t[1]] = letter;
			map[t[0]][t[1] + 1] = letter;
			map[t[0]][t[1] + 2] = letter;
			return (1);
		}
	}
	return (ft_threed_bonus(map, fig, letter, t));
}
