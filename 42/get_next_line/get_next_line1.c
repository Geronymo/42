/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:52:25 by pibenoit          #+#    #+#             */
/*   Updated: 2016/01/09 19:54:51 by pibenoit         ###   ########.fr       */
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

	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	while (s2[j] != '\0'/* && s2[j] != '$'*/)
	{
		*(str + i) = *(s2 + j);
		i++;
		j++;
	}
	if (s2[j] == '$')
		*cpt = 0;
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_alloc_n_read(int const fd, char *str, char *end)
{
	char	*buf;
	int		cpt;

	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (buf == NULL || BUFF_SIZE == 0)
	{
		*end = -1;
		free(str);
		return (NULL);
	}
	cpt = BUFF_SIZE;
	while (cpt > 0 && str != NULL)
	{
		cpt = read(fd, buf, BUFF_SIZE);
		if (cpt == -1)
			return (NULL);
		else if (cpt != 0)
		{
			buf[cpt] = '\0';
			str = ft_strjoin_gnl(str, buf, &cpt);
		}
	}
	free(buf);
	return (str);
}

char    *ft_strsub_gnl(char *s, unsigned int start, size_t len)
{
	unsigned int    i;
	char            *str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	free(s);
	return (str);
}

char	**ft_copy(char **str, char **line, char *end)
{
	int		cpt;
	int		i;

	cpt = 0;
	i = 0;
	while ((*str)[cpt] != '\n' && (*str)[cpt] != '\0')
		cpt++;
	write(1, "A\n", 2);
	if ((*str)[cpt] == '\0')
		*end = 0;
	*line = (char*)malloc(sizeof(char) * (cpt + 1));
	(*line)[cpt] = '\0';
	while (i < cpt)
	{
		(*line)[i] = (*str)[i];
		i++;
	}
	if (*end == 1)
		*str = ft_strsub_gnl((*str), cpt + 1, ft_strlen((*str) + cpt + 1));
	else
		free(*str);
	return (line);
}

int		get_next_line(int const fd, char **line)
{
	static char *str;
	char		end;

//	if (line == NULL)
//		return (-1);
	end = 1;
	if (fd == 1 || fd < 0)
		return (-1);
	if (str == NULL)
	{
		str = (char*)malloc(sizeof(char) * 1);
		if (str == NULL)
			return (-1);
		str[0] = '\0';
		if ((str = ft_alloc_n_read(fd, str, &end)) == NULL)
			return (-1);
	}
	line = ft_copy(&str, line, &end);
	return (end);
}
