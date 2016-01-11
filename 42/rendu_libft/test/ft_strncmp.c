/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:51:43 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/08 16:03:21 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				a;

	i = 0;
	a = 0;
	if (*s1 == '\0' || *s2 == '\0')
		return ((unsigned char)*(s1) - (unsigned char)*(s2));
	while ((*(s1 + i) != '\0' || *(s2 + i) != '\0') && i < n)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			a = (unsigned char)*(s1 + i) - (unsigned char)*(s2 + i);
			return (a);
		}
		i++;
	}
	return (0);
}
