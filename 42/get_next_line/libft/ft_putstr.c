/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:43:04 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/06 17:05:16 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr(char const *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(s + i) != '\0')
		i++;
	while (j < i)
	{
		write(1, (s + j), 1);
		j++;
	}
}
