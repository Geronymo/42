/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:13:06 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/21 17:20:36 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "fillit.h"

void	print_test(char **map)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int taille = ft_len(map);

	while (i < taille)
	{
		while (j < taille)
		{
			write(1, map[i] + j, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}
