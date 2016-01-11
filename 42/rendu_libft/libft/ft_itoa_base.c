/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:32:15 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/14 11:16:13 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int	length(int n, char base)
{
	unsigned int	i;

	i = 2;
	while (n > (base - 1))
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(int n, char base)
{
	int				len;
	char			*str;

	str = NULL;
	if (base == 10)
		str = ft_itoa(n);
	else if (n > 0 && base < 17)
	{
		len = length(n, base);
		str = (char*)malloc(sizeof(char) * len);
		if (str == NULL)
			return (NULL);
		str[len - 1] = '\0';
		len -= 2;
		while (len >= 0)
		{
			if (n % base <= 9)
				str[len] = (n % base) + 48;
			else
				str[len] = (n % base) + 65;
			n = n / base;
			len--;
		}
	}
	return (str);
}
