/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:37:29 by pibenoit          #+#    #+#             */
/*   Updated: 2016/01/11 13:36:41 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2, int *cpt)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		if (s2[j] == '\n')
			*cpt = (-2);
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_alloc_n_read(int const fd, char *str, int *end)
{
	char	*buf;
	int		cpt;

	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (buf == NULL || BUFF_SIZE < 1)
	{
		*end = -1;
		free(str);
		return (NULL);
	}
	buf[0] = '\0';
	cpt = BUFF_SIZE;
	while (cpt == BUFF_SIZE)
	{
		cpt = read(fd, buf, BUFF_SIZE);
		if (cpt == -1)
		{
			*end = -1;
			free(buf);
			free(str);
			return (NULL);
		}
		buf[cpt] = '\0';
		str = ft_strjoin_gnl(str, buf, &cpt);
		if (cpt != BUFF_SIZE && cpt != -2)
			*end = 0;
	}
	free (buf);
	return (str);
}

char    *ft_strsub_gnl(char *s, unsigned int start, size_t len)
{
	unsigned int    i;
	char            *str;

	i = -1;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		*(str + i) = *(s + start + i);
	*(str + i) = '\0';
	free(s);
	return (str);
}

char    **ft_copy(char **str, char **line, int *end, int cpt)
{
	char	*s2;
	int     i;

	if (*str != NULL)
		while ((*str)[cpt] != '\n' && (*str)[cpt] != '\0')
			cpt++;
	i = -1;
	if (!(*line = ft_strnew(cpt)))
		return (NULL);
	while (++i < cpt && str != NULL)
		(*line)[i] = (*str)[i];
	if ((*end == 1 /*|| *end == 0*/) && (*str)[cpt] == '\n')
	{
		s2 = ft_strsub_gnl((*str), cpt + 1, ft_strlen((*str) + cpt + 1));
		free(*str);
		*str = s2;
	}
	else if (*end == 0 && *str != NULL)
		free(*str);
	return (line);
}

int	get_next_line(int const fd, char **line)
{
	static char	*str;
	int			end;
	int			i;

	end = 1;
	i = 0;
	if (fd == 1 || fd < 0)
		return (-1);
	if (str == NULL)
	{
		str = (char*)malloc(sizeof(char) * 1);
		if (str == NULL)
			return (-1);
		*str = '\0';
	}
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		str = ft_alloc_n_read(fd, str, &end);
	if (end != -1)
		line = ft_copy(&str, line, &end, 0);
	return (end);
}
