/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 22:36:09 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/23 23:48:19 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_onedthreep_bonus(char **square, char forme, char letter, int tab[3])
{
	if (forme == 19 && (tab[0] + 3) < tab[2])
	{
		if (square[tab[0] + 3][tab[1]] == '.')
		{
			square[tab[0] + 3][tab[1]] = letter;
			square[tab[0]][tab[1]] = letter;
			square[tab[0] + 1][tab[1]] = letter;
			square[tab[0] + 2][tab[1]] = letter;
			return (1);
		}
	}
	return (0);
}

int		ft_twod_bonus(char **map, char fig, char letter, int t[3])
{
	if (fig == 7 && (t[0] + 2) < t[2])
	{
		if (map[t[0] + 2][t[1]] == '.')
		{
			map[t[0] + 2][t[1]] = letter;
			map[t[0]][t[1]] = letter;
			map[t[0]][t[1] + 1] = letter;
			map[t[0] + 1][t[1]] = letter;
			return (1);
		}
	}
	return (0);
}

int		ft_twod(char **map, char fig, char letter, int t[3])
{
	if (fig == 5 && (t[1] - 1) >= 0)
	{
		if (map[t[0] + 1][t[1] - 1] == '.')
		{
			map[t[0] + 1][t[1] - 1] = letter;
			map[t[0]][t[1]] = letter;
			map[t[0]][t[1] + 1] = letter;
			map[t[0] + 1][t[1]] = letter;
			return (1);
		}
	}
	else if (fig == 6)
	{
		if (map[t[0] + 1][t[1] + 1] == '.')
		{
			map[t[0] + 1][t[1] + 1] = letter;
			map[t[0]][t[1]] = letter;
			map[t[0]][t[1] + 1] = letter;
			map[t[0] + 1][t[1]] = letter;
			return (1);
		}
	}
	return (ft_twod_bonus(map, fig, letter, t));
}

int		ft_twodi(char **map, char fig, char letter, int t[3])
{
	if (fig == 8 && (t[1] + 2) < t[2])
	{
		if (map[t[0] + 1][t[1] + 2] == '.')
		{
			map[t[0] + 1][t[1] + 2] = letter;
			map[t[0]][t[1]] = letter;
			map[t[0]][t[1] + 1] = letter;
			map[t[0] + 1][t[1] + 1] = letter;
			return (1);
		}
	}
	else if (fig == 9 && (t[0] + 2) < t[2])
	{
		if (map[t[0] + 2][t[1] + 1] == '.')
		{
			map[t[0] + 2][t[1] + 1] = letter;
			map[t[0]][t[1]] = letter;
			map[t[0]][t[1] + 1] = letter;
			map[t[0] + 1][t[1] + 1] = letter;
			return (1);
		}
	}
	return (0);
}
