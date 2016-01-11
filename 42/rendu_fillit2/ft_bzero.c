/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:02:18 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/23 21:14:57 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((char*)s + i) = '\0';
		i++;
	}
}

void	ft_zero(void *s, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((char*)s + i) = 0;
		i++;
	}
}
