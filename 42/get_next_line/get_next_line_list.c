/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 17:20:26 by pibenoit          #+#    #+#             */
/*   Updated: 2016/01/11 13:29:23 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line.h"

char    *ft_strjoin_gnl(char *s1, char *s2, int *cpt)
{
	unsigned int    i;
	unsigned int    j;
	char            *str;

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

char    *ft_alloc_n_read(int const fd, char *str, int *end)
{
	char    *buf;
	int     cpt;

	if (!(buf = ft_strnew(BUFF_SIZE)))
	{
		*end = -1;
		free(str);
		return (NULL);
	}
	cpt = BUFF_SIZE;
	while (cpt == BUFF_SIZE)
	{
		if((cpt = read(fd, buf, BUFF_SIZE)) == -1)
		{
			*end = -1;
			free(buf);
			free(str);
			return (NULL);
		}
		str = ft_strjoin_gnl(str, buf, &cpt);
		if (cpt != BUFF_SIZE && cpt != -2)
			*end = 0;
	}
	free (buf);
	return (str);
}

char    **ft_copy(char **str, char **line, int *end, int cpt)
{
	char    *s2;
	int     i;

	if (*str != NULL)
		while ((*str)[cpt] != '\n' && (*str)[cpt] != '\0')
			cpt++;
	i = -1;
	if (!(*line = ft_strnew(cpt)))
		return (NULL);
	while (++i < cpt && str != NULL)
		(*line)[i] = (*str)[i];
	if ((*end == 1 /*||  *end == 0*/) && (*str)[cpt] == '\n')
	{
		s2 = ft_strsub((*str), cpt + 1, ft_strlen((*str) + cpt + 1));
		free(*str);
		*str = s2;
	}
	if (*end == 0)
		free(*str);
	return (line);
}

t_list	*ft_help(t_list **debut, int const fd)
{
	int		i;
	t_list	*list;

	i = 1;
	list = *debut;
	if (list != NULL)
	{
		while (list != NULL && i)
		{
			if ((int)(list->content_size) != fd)
				list = list->next;
			else
				i = 0;
		}
	}
	if (list == NULL)
	{
		
		if (!(list = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		if (!(list->content = (ft_strnew(0))))
			return (NULL);
		list->content_size = fd;
	}
	list->next = *debut;
	*debut = list;
	return (list);
}

int	get_next_line(int const fd, char **line)
{
	static t_list	*lst;
//	t_list			*lstnow;
	int				end;
	int				i;

//	lstnow = (t_list *)malloc(sizeof(t_list));
//	lst = &lstnow;
//	lst->next = (t_list *)malloc(sizeof(t_list));
//	
//	lst = lst->next;
	end = 1;
	i = 0;
//	lstnow = &lst;
	if(!(lst = ft_help(&lst, fd)) || line == NULL || fd < 0 || fd == 1)
		return (-1);
/*	if (lstnow != NULL)
	{
		end = 2;
		while (lstnow != NULL && end == 2)
		{
			if (lstnow->content_size != fd)
				lstnow = lstnow->next;
			else
				end = 1;
		}	
	}
	if (lstnow == NULL)
	{
		if (!(lstnow = (t_list*)malloc(sizeof(t_list))))
			return (-1);
		if (!(listnow->content = (ft_strnew(0))))
			return (-1);
		lstnow->content_size = fd;
	}*/
	while ((((char*)lst->content)[i]) != '\n' && (((char*)lst->content)[i]) != '\0')
		i++;
	if ((((char*)lst->content)[i]) == '\0')
		lst->content = ft_alloc_n_read(fd, lst->content, &end);
	if (end != -1)
		line = ft_copy((char**)(&(lst->content)), line, &end, 0);
//	if ((*line) != NULL)
//		if ((*line)[0] == '\0')
//			free(*line);
	return (end);
}
