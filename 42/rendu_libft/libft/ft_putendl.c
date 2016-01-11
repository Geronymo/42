/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:25:11 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/06 17:04:25 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, (const void *)(s + i), 1);
		i++;
	}
	write(1, "\n", 1);
}
