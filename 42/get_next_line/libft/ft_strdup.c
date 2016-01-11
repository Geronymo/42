/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:42:16 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/06 17:07:22 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	s2 = (char*)malloc(sizeof(char) * i + 1);
	if (s2 != NULL)
		while (i >= 0)
		{
			*(s2 + i) = *(s1 + i);
			i--;
		}
	else
		return (NULL);
	return (s2);
}
