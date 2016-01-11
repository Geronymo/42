/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:28:45 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/06 17:03:41 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			a;

	a = (char)c;
	i = 0;
	while (i < len)
	{
		*((char*)b + i) = a;
		i++;
	}
	return (b);
}
