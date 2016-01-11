/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:39:42 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/12 19:43:36 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	d;
	unsigned int	f;
	char			*str;
	char			a;

	d = 0;
	f = 0;
	if (*s == '\0')
		return ((char*)s);
	while (*(s + f) != '\0')
		f++;
	f--;
	while ((*(s + d) == ' ' || *(s + d) == '\n' || *(s + d) == '\t') && d < f)
		d++;
	while ((*(s + f) == ' ' || *(s + f) == '\n' || *(s + f) == '\t') && f > d)
		f--;
	if (*(s + d) != ' ' && *(s + d) != '\n' && *(s + d) != '\t')
		str = ft_strsub(s, d, f - d + 1);
	else
	{
		a = '\0';
		str = &a;
	}
	return (str);
}
