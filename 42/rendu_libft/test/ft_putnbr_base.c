/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:16:10 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/12 19:29:30 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_putlittlenbr(char nbr)
{
	if (nbr < 10)
	{
		nbr += 48;
		write(1, &nbr, 1);
	}
	else
	{
		nbr += 55;
		write(1, &nbr, 1);
	}
}

void		ft_putnbr_base(int n, char base)
{
	int i;

	i = 0;
	if (n >= base)
	{
		ft_putnbr_base(n / base, base);
		ft_putnbr_base(n % base, base);
	}
	else if (n < 0 && base == 10 && (n - 1) < n)
	{
		write(1, "-", 1);
		ft_putnbr_base(-n, base);
	}
	else if (n >= 0 && n < base)
		ft_putlittlenbr(n);
	else
		write(1, "-2147483648", 11);
}
