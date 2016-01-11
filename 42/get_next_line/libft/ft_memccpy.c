/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:12:41 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/08 16:17:26 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	a;
	unsigned int	i;
	unsigned char	b;

	i = 0;
	a = (unsigned char)c;
	b = *((unsigned char*)src);
	while (b != a && i < n)
	{
		*((unsigned char*)dst + i) = *((unsigned char*)src + i);
		i++;
		b = *((unsigned char*)src + i);
	}
	if (*((unsigned char*)src + i) == a && i < n)
	{
		*((unsigned char*)dst + i) = *((unsigned char*)src + i);
		return ((unsigned char*)dst + i + 1);
	}
	else
		return (NULL);
}
