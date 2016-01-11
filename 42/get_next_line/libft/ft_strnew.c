/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:32:15 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/10 17:42:12 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str != NULL)
		while (i <= size)
		{
			str[i] = '\0';
			i++;
		}
	else
		return (NULL);
	return (str);
}
