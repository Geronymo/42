/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:59:23 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/06 17:06:10 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = (char)c;
	while (*(s + i) != a && *(s + i) != '\0')
		i++;
	if (*(s + i) == a)
		return ((char*)s + i);
	else
		return (NULL);
}
