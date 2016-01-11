/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:20:44 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/10 17:40:09 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char			*tab;
	unsigned int	i;

	i = 0;
	tab = malloc(sizeof(char) * size);
	if (tab != NULL)
		while (i < size)
		{
			tab[i] = '\0';
			i++;
		}
	else
		return (NULL);
	return ((void*)tab);
}
