/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:31:34 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/10 17:41:05 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			a;
	unsigned int	i;
	char			*s2;

	s2 = (char*)s;
	a = (char)c;
	i = 0;
	while (i < n)
	{
		if (*(s2 + i) == a)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
