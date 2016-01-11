/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:46:29 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/21 14:45:56 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

void	ft_exit(char map[16][16], int taille)
{
	int		i;
	int		j;
	char	letter;

	letter = 0;
	i = 0;
	j = 0;
	while (i < taille)
	{
		while (j < taille)
		{
			letter = map[i][j];
			write(1, &letter, 1);
			j++;
		}
		i++;
		j = 0;
		write(1, "\n", 1);
	}
}
