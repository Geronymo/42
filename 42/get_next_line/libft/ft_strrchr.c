/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:07:23 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/06 17:11:08 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;

	a = (char)c;
	i = 0;
	while (*(s + i) != '\0')
		i++;
	while (*(s + i) != a && i >= 0)
		i--;
	if (*(s + i) == a)
		return ((char*)(s + i));
	else
		return (NULL);
}
