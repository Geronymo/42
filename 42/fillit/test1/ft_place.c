/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:51:31 by pbenoit           #+#    #+#             */
/*   Updated: 2015/12/21 21:36:06 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

int		ft_place(char **map, char fig, char letter, int t[3])
{
	while (t[0] < t[2])
	{
		while(t[1] < t[2])
		{
			if (map[t[0]][t[1]] == '.')
			{
				if (fig > 0 && fig < 5 && map[t[0]][t[1] + 1] == '.' && map[t[0]][t[1] + 2] == '.' && (t[1] + 2) < t[2])
				{
					if (ft_threed(map, fig, letter, t))
						return (1);
				}
				else if (fig > 4 && fig < 8 && map[t[0]][t[1] + 1] == '.' && map[t[0] + 1][t[1]] == '.' && (t[0] + 1) < t[2] && (t[1] + 1) < t[2])
				{
					if (ft_twod(map, fig, letter, t))
						return (1);
				}
				else if (fig > 7 && fig < 10 && map[t[0]][t[1] + 1] == '.' && map[t[0] + 1][t[1] + 1] == '.' && (t[0] + 1) < t[2] && (t[1] + 1) < t[2])
				{
					if (ft_twodi(map, fig, letter, t))
						return (1);
				}
				else if (fig > 9 && fig < 14 && map[t[0] + 1][t[1]] == '.' && map[t[0] + 1][t[1] - 1] == '.' && (t[0] + 1) < t[2] && (t[1] - 1) >= 0)
				{
					if (ft_onedtwop(map, fig, letter, t))
						return (1);
				}
				else if (fig > 13 && fig < 17 && map[t[0] + 1][t[1]] == '.' && map[t[0] + 1][t[1] + 1] == '.' && (t[0] + 1) < t[2] && (t[0] + 1) < t[2])
				{
					if (ft_onedthreeptwod(map, fig, letter, t))
						return (1);
				}
				else if (fig > 16 && fig < 20 && map[t[0] + 1][t[1]] == '.' && map[t[0] + 2][t[1]] == '.' && (t[0] + 2) < t[2])
				{
					if (ft_onedthreep(map, fig, letter, t))
						return (1);
				}
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

int    ft_threed(char **map, char fig, char letter,int t[3])
{
	if (fig == 1 && map[t[0]][t[1] + 3] == '.' && (t[1] + 3) < t[2])
		map[t[0]][t[1] + 3] = letter;
	else if (fig == 2 && map[t[0] + 1][t[1]] == '.' && (t[0] + 1) < t[2])
		map[t[0] + 1][t[1]] = letter;
	else if (fig == 3 && map[t[0] + 1][t[1] + 1] == '.' && (t[0] + 2) < t[2])
		map[t[0] + 1][t[1] + 1] = letter;
	else if (fig == 4 && map[t[0] + 1][t[1] + 2] == '.' && (t[0] + 1) < t[2])
		map[t[0] + 1][t[1] + 2] = letter;
	else
		return (0);
	map[t[0]][t[1]] = letter;
	map[t[0]][t[1] + 1] = letter;
	map[t[0]][t[1] + 2] = letter;
	return (1);
}

int    ft_twod(char **map, char fig, char letter, int t[3])
{
	if (fig == 5 && map[t[0] + 1][t[1] - 1] == '.' && (t[1] - 1) >= 0)
		map[t[0] + 1][t[1] - 1] = letter;
	else if (fig == 6 && map[t[0] + 1][t[1] + 1] == '.')
		map[t[0] + 1][t[1] + 1] = letter;
	else if (fig == 7 && map[t[0] + 2][t[1]] == '.' && (t[0] + 2) < t[2])
		map[t[0] + 2][t[1]] = letter;
	else
		return (0);
	map[t[0]][t[1]] = letter;
	map[t[0]][t[1] + 1] = letter;
	map[t[0] + 1][t[1]] = letter;
	return (1);
}

int    ft_twodi(char **map, char fig,char letter, int t[3])
{
	if (fig == 8 && map[t[0] + 1][t[1] + 2] == '.' && (t[1] + 2) < t[2])
		map[t[0] + 1][t[1] + 2] = letter;
	else if (fig == 9 && map[t[0] + 2][t[1] + 1] == '.' && (t[0] + 2) < t[2])
		map[t[0] + 2][t[1] + 1] = letter;
	else
		return (0);
	map[t[0]][t[1]] = letter;
	map[t[0]][t[1] + 1] = letter;
	map[t[0] + 1][t[1] + 1] = letter;
	return (1);
}
