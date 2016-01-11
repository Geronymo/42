/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab1d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:33:19 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/12 18:38:13 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>

static void	ft_putline(void)
{
	unsigned int j;

	j = 0;
	while (j < 79)
	{
		if (j % 8 != 0 && j % 8 < 6)
			write(1, "-", 1);
		else if (j % 8 == 7)
			write(1, " ", 1);
		else
			write(1, "|", 1);
		j++;
	}
}

void		ft_puttab1d(unsigned char *tab, size_t size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		write(1, "| ", 2);
		if (*(tab + i) < 10)
			write(1, " ", 1);
		else if (*(tab + i) < 100)
			write(1, "0", 1);
		ft_putnbr(*(tab + i));
		if (*(tab + i) < 10)
			write(1, " ", 1);
		if ((i % 10) < 9)
			write(1, " |\t", 3);
		else
		{
			write(1, " |\n", 3);
			ft_putline();
			write(1, "\n", 1);
		}
		i++;
	}
	write(1, "\n", 1);
}
