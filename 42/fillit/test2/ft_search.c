/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:01:58 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/23 23:33:35 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <string.h>

void	ft_search_ten(char *str, char order_figure[27])
{
	int		pos;

	pos = order_figure[0] + 1;
	if (str[1] == '#' && str[5] == '#' && str[9] == '#')
		order_figure[pos] = 9;
	else if (str[4] == '#' && str[8] == '#' && str[9] == '#')
		order_figure[pos] = 18;
	else if (str[4] == '#' && str[5] == '#' && str[9] == '#')
		order_figure[pos] = 16;
	else
		ft_ragequit();
	(*order_figure)++;
}

void	ft_recognition(char *str, char order_figure[27])
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i == 4 || i == 8 || i == 13)
		ft_search_other(str, order_figure, i);
	else if (i == 5)
		ft_search_five(str, order_figure);
	else if (i == 6)
		ft_search_six(str, order_figure);
	else if (i == 7)
		ft_search_seven(str, order_figure);
	else if (i == 9)
		ft_search_nine(str, order_figure);
	else if (i == 10)
		ft_search_ten(str, order_figure);
	else
		ft_ragequit();
}

void	ft_cpt(int cpt[3], char i)
{
	if (i == 1)
	{
		cpt[0]++;
		cpt[1]++;
	}
	else if (i == 0)
	{
		cpt[1] = 0;
		cpt[2] = 0;
	}
	else
	{
		cpt[0] = 0;
		cpt[1] = 0;
	}
}

void	ft_str_cpt(char *str, int cpt[3])
{
	if (cpt[1] == 14)
		ft_ragequit();
	if (str[cpt[0]] == '\n')
		cpt[0]++;
	if (str[cpt[0]] == '#')
		cpt[2]++;
}

void	ft_search(char *str, char order_figure[27])
{
	int		cpt[3];
	char	str_pattern[15];

	ft_zero(cpt, 12);
	while (str[cpt[0]] != '\0')
	{
		ft_bzero(str_pattern, 15);
		while (str[cpt[0]] != '#')
			cpt[0]++;
		while (cpt[2] < 4)
		{
			ft_str_cpt(str, cpt);
			str_pattern[cpt[1]] = str[cpt[0]];
			ft_cpt(cpt, 1);
		}
		ft_recognition(str_pattern, order_figure);
		while (cpt[0] % 21 != 20)
			cpt[0]++;
		if (str[cpt[0]] != '\0')
			cpt[0]++;
		ft_cpt(cpt, 0);
	}
}
