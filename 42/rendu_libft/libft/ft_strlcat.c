/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:49:02 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/10 17:54:16 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	cpt[2];
	unsigned int	len[2];

	len[0] = 0;
	len[1] = 0;
	cpt[0] = 0;
	while (*(src + len[0]) != '\0')
		len[0] = len[0] + 1;
	while (*(dst + len[1]) != '\0' && len[1] < (size - 1))
		len[1] = len[1] + 1;
	if (len[1] < (size - 1) && size != 0)
	{
		cpt[1] = len[1];
		while (cpt[1] < (size - 1) && *(src + cpt[0]) != '\0')
		{
			*(dst + cpt[1]) = *(src + cpt[0]);
			cpt[1] = cpt[1] + 1;
			cpt[0] = cpt[0] + 1;
		}
		*(dst + cpt[1]) = '\0';
	}
	if (size != 0 && (len[1] < (size - 1) || *(dst + len[1]) == '\0'))
		return (len[0] + len[1]);
	else
		return (len[0] + size);
}
