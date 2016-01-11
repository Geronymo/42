/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:39:02 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/20 15:51:53 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int len, char a)
{
	if ((len == 0 && a == 0) || (len == 2 && a == 1))
		return (1);
	else if ((len == 1 && a == 0) || (len == 3 && a == 1))
		return (16);
	else
		return (ft_pow(len - 1, a) * 16);
}

static int	ft_addnumber(const char *s, int *i, int len, char a)
{
	int		lenmax;

	lenmax = len;
	while ((len > 1 && a == 1) || (len >= 0 && a == 0))
	{
		if (*(s + len) > 47 && *(s + len) < 58)
			*i = *i + ((*(s + len) - 48) * ft_pow(lenmax - len, a));
		else if (*(s + len) > 64 && *(s + len) < 71)
			*i = *i + ((*(s + len) - 55) * ft_pow(lenmax - len, a));
		else if (*(s + len) > 96 && *(s + len) < 103)
			*i = *i + ((*(s + len) - 87) * ft_pow(lenmax - len, a));
		else
			a = 2;
		len--;
	}
	if (a < 2)
		return (0);
	else
		return (1);
}

int			ft_atoi_hexa(const char *s)
{
	int		i;
	int		len;
	char	a;

	i = 0;
	len = 0;
	a = 0;
	if (*s == '0' && *(s + 1) == 'x')
		a = 1;
	while (*(s + len) != '\0')
		len++;
	if (!(ft_addnumber(s, &i, len, a)))
		return (i);
	else
		return (0);
}
