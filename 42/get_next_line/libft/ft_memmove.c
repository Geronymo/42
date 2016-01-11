/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:13:38 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/23 13:01:29 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	if (src > dst)
		return (ft_memcpy(dst, src, len));
	i = len - 1;
	while (i > 0 && len > 0)
	{
		*((unsigned char*)dst + i) = *((const unsigned char*)src + i);
		i--;
	}
	if (i == 0)
		*((unsigned char*)dst) = *((const unsigned char*)src);
	return (dst);
}
