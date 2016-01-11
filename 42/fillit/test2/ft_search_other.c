/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 21:02:47 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/23 21:09:26 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_search_other(char *str, char order_figure[27], unsigned int i)
{
	int		pos;

	pos = order_figure[0] + 1;
	if (i == 4)
	{
		if (str[1] == '#' && str[2] == '#' && str[3] == '#')
			order_figure[pos] = 1;
		else
			ft_ragequit();
	}
	else if (i == 8)
	{
		if (str[3] == '#' && str[4] == '#' && str[7] == '#')
			order_figure[pos] = 12;
		else
			ft_ragequit();
	}
	else if (i == 13)
	{
		if (str[4] == '#' && str[8] == '#' && str[12] == '#')
			order_figure[pos] = 19;
		else
			ft_ragequit();
	}
	order_figure[0]++;
}

void	ft_search_five(char *str, char order_figure[27])
{
	int		pos;

	pos = order_figure[0] + 1;
	if (str[2] == '#' && str[3] == '#' && str[4] == '#')
		order_figure[pos] = 10;
	else if (str[1] == '#' && str[2] == '#' && str[4] == '#')
		order_figure[pos] = 2;
	else if (str[1] == '#' && str[3] == '#' && str[4] == '#')
		order_figure[pos] = 5;
	else
		ft_ragequit();
	(*order_figure)++;
}

void	ft_search_six(char *str, char order_figure[27])
{
	int		pos;

	pos = order_figure[0] + 1;
	if (str[1] == '#' && str[4] == '#' && str[5] == '#')
		order_figure[pos] = 6;
	else if (str[1] == '#' && str[2] == '#' && str[5] == '#')
		order_figure[pos] = 3;
	else if (str[3] == '#' && str[4] == '#' && str[5] == '#')
		order_figure[pos] = 11;
	else
		ft_ragequit();
	(*order_figure)++;
}

void	ft_search_seven(char *str, char order_figure[27])
{
	int		pos;

	pos = order_figure[0] + 1;
	if (str[1] == '#' && str[2] == '#' && str[6] == '#')
		order_figure[pos] = 4;
	else if (str[4] == '#' && str[5] == '#' && str[6] == '#')
		order_figure[pos] = 14;
	else if (str[1] == '#' && str[5] == '#' && str[6] == '#')
		order_figure[pos] = 8;
	else
		ft_ragequit();
	(*order_figure)++;
}

void	ft_search_nine(char *str, char order_figure[27])
{
	int		pos;

	pos = order_figure[0] + 1;
	if (str[4] == '#' && str[7] == '#' && str[8] == '#')
		order_figure[pos] = 17;
	else if (str[1] == '#' && str[4] == '#' && str[8] == '#')
		order_figure[pos] = 7;
	else if (str[4] == '#' && str[5] == '#' && str[8] == '#')
		order_figure[pos] = 15;
	else if (str[3] == '#' && str[4] == '#' && str[8] == '#')
		order_figure[pos] = 13;
	else
		ft_ragequit();
	(*order_figure)++;
}
