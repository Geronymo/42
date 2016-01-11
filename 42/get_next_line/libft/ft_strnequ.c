/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:31:57 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/06 17:09:43 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int i;
	unsigned int k;

	i = 0;
	k = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n && k == 0)
	{
		if (s1[i] == s2[i])
			i++;
		else
			k++;
	}
	if (i == n || s1[i] == '\0')
		return (1);
	else
		return (0);
}
