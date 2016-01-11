/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:46:40 by pibenoit          #+#    #+#             */
/*   Updated: 2016/01/04 11:38:27 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	test_tronc_return(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i - 1] == '#' && str[i + 1] == '#')
			ft_ragequit();
		i++;
	}
}

void	test_number(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i > 546)
		ft_ragequit();
	else if (i == 0)
		ft_ragequit();
	else if (i > 0)
	{
		if (str[i - 1] == '\n' && str[i - 2] == '\n')
			ft_ragequit();
	}
}

void	test_char(char *str)
{
	unsigned int	i;
	unsigned int	memory;
	unsigned char	cpt_hash;

	i = 0;
	memory = 0;
	cpt_hash = 0;
	while (str[i] != '\0' && cpt_hash == 0)
	{
		while ((i - memory) < 21 && str[i] != '\0')
		{
			if (str[i] == '#')
				cpt_hash++;
			i++;
		}
		if (cpt_hash == 4)
		{
			memory = i;
			cpt_hash = 0;
		}
		else
			cpt_hash = 5;
	}
	if (cpt_hash == 5 || (i % 21 != 20))
		ft_ragequit();
}

void	test_return(char *str)
{
	unsigned int	i;
	unsigned int	memory;

	memory = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while ((i - memory) < 21 && str[i] != '\0')
		{
			if ((i - memory) % 5 == 4 && str[i] != '\n' && (i - memory) < 20)
				ft_ragequit();
			else if ((i - memory) % 5 != 4 && (str[i] != '#' && str[i] != '.'))
				ft_ragequit();
			else if ((i - memory) == 20 && str[i] != '\n')
				ft_ragequit();
			i++;
		}
		memory = i;
	}
	return ;
}

void	ft_erreur(char *str)
{
	test_return(str);
	test_number(str);
	test_char(str);
	test_tronc_return(str);
}
