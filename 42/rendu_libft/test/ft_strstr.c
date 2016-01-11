/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:30:04 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/06 17:11:38 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static void	ft_strmatch(char *s0, char *s1, unsigned int c[2], unsigned int m)
{
	while (s1[c[1]] == s0[c[0]] && s1[c[1]] != '\0')
	{
		c[1]++;
		c[0]++;
	}
	if (s1[c[1]] != '\0')
	{
		c[0] = m;
		c[1] = 0;
	}
}

char		*ft_strstr(char *s0, char *s1)
{
	unsigned int cpt[2];
	unsigned int mem;

	cpt[0] = 0;
	cpt[1] = 0;
	mem = 0;
	while (s1[cpt[1]] != '\0' && s0[cpt[0]] != '\0')
	{
		if (s1[cpt[1]] == s0[cpt[0]] && s1[cpt[1]] != '\0')
		{
			mem = cpt[0];
			ft_strmatch(s0, s1, cpt, mem);
		}
		cpt[0]++;
	}
	if (s1[cpt[1]] == '\0')
		s0 = s0 + mem;
	else
		s0 = NULL;
	return (s0);
}
