/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:01:58 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/21 21:18:58 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// recherche de pattern et reconnaissance pour marquage
// refonte du code ci-dessus


#include "fillit.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_search_other(char *str, char	order_figure[27], unsigned int i)
{
	int	pos;

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
	int	pos;

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
	int    pos;

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
	int    pos;

	pos = order_figure[0] + 1;
	if (str[1] == '#' && str[2] == '#' && str[6] == '#')
		order_figure[pos] = 4;
	else if (str[4] == '#' && str[5] == '#' && str[6] == '#')
		order_figure[pos] = 14;
	else if (str[1] == '#' && str[5] == '#' && str[6] == '#')
		order_figure[pos] = 7;
	else
		ft_ragequit();
	(*order_figure)++;
}

void	ft_search_nine(char *str, char order_figure[27])
{
	int    pos;

	pos = order_figure[0] + 1;
	if (str[4] == '#' && str[7] == '#' && str[8] == '#')
		order_figure[pos] = 17;
	else if (str[1] == '#' && str[4] == '#' && str[8] == '#')
		order_figure[pos] = 8;
	else if (str[4] == '#' && str[5] == '#' && str[8] == '#')
		order_figure[pos] = 15;
	else if (str[3] == '#' && str[4] == '#' && str[8] == '#')
		order_figure[pos] = 13;
	else
		ft_ragequit();
	(*order_figure)++;
}

void	ft_search_ten(char *str, char order_figure[27])
{
	int    pos;

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

//cpt[0] = i (naviguer dans la chaine)
//cpt[1] = j (naviguer dans la nouvelle chaine)
//cpt[2] = compteur de #
//strtrim? strsplit?

void	ft_search(char *str, char order_figure[27])
{
	unsigned int	cpt[3];
	char			str_pattern[15];

	ft_zero(cpt, 12);
	while (str[cpt[0]] != '\0')
	{
		ft_bzero(str_pattern, 15);
		while (str[cpt[0]] != '#')
			cpt[0]++;
		while (cpt[2] < 4)
		{
			if (str[cpt[0]] == '\n')
				cpt[0]++;
			str_pattern[cpt[1]] = str[cpt[0]];
			if (str[cpt[0]] == '#')
				cpt[2]++;
			cpt[0]++;
			cpt[1]++;
		}
		str_pattern[cpt[1]] = '\0';
		ft_recognition(str_pattern, order_figure);
		while (cpt[0] % 21 != 20)
			cpt[0]++;
		if (str[cpt[0]] != '\0')
			cpt[0]++;
		cpt[2] = 0;
		cpt[1] = 0;
	}
}

// entre les '_', il y a un bout de code concernant la lecture d'erreurs et de tetriminos qui sera a completer
// il faudra faire les patterns des figures pour les comparer, finir de lire le fichier, etc...
