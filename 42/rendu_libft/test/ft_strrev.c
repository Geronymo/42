/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 23:59:54 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/14 11:18:59 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			a;

	i = 0;
	j = 0;
	while (*(str + i) != '\0')
		i++;
	i--;
	while ((i - j) > j)
	{
		a = *(str + i - j);
		*(str + i - j) = *(str + j);
		*(str + j) = a;
		j++;
	}
	*(str + i + 1) = '\0';
	return (str);
}
