/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:46:40 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/21 19:28:59 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ERREURS
// error = 0 <=> pas d'erreur
// error = 1 <=> une ou plusieurs erreurs (afficher "error") <=> ft_ragequit();

#include "fillit.h"

void	test_number(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i > 546)
		ft_ragequit();
}

void	test_char(char *str)
{
	unsigned int 	i;
	unsigned int 	memory;
	unsigned char	cpt_hash;

	i = 0;
	memory = 0;
	cpt_hash = 0;
	while (str[i] != '\0' && cpt_hash < 5)
	{
		while ((i - memory) < 21 && str[i] != '\0' && cpt_hash < 5)
		{
			if (str[i] == '#')
				cpt_hash++;
			i++;
		}
		if (cpt_hash < 5)
		{
			memory = i;
			cpt_hash = 0;
		}
	}
	if (cpt_hash > 4)
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
			else if ((i - memory) == 20 && str[i] != '\n')
				ft_ragequit();
			i++;
		}
		memory = i;
	}
	return;
}

void	ft_erreur(char *str)
{
	test_return(str);
	test_number(str);
	test_char(str);
}
