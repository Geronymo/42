/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:48:02 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/08 16:02:02 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	j;
	unsigned char	k;

	i = 0;
	while (*(s1 + i) != '\0' || *(s2 + i) != '\0')
	{
		if (*(s1 + i) != *(s2 + i))
		{
			j = (unsigned char)*(s1 + i);
			k = (unsigned char)*(s2 + i);
			return ((int)(j - k));
		}
		i++;
	}
	if (*s1 == '\0' || *s2 == '\0')
		return ((int)(*((unsigned char*)s1) - *((unsigned char*)s2)));
	return (0);
}
