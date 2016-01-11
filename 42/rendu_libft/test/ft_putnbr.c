/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:25:50 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/06 17:04:47 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	int i;

	i = 48;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 0 && (n - 1) < n)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n >= 0 && n < 10)
	{
		i = i + n;
		write(1, &i, 1);
	}
	else
		write(1, "-2147483648", 11);
}
