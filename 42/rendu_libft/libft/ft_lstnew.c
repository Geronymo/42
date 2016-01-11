/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:01:44 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/12 21:54:24 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*t_new;

	t_new = malloc(sizeof(t_list));
	if (t_new == NULL)
		return (NULL);
	if (content == NULL)
	{
		t_new->content = NULL;
		t_new->content_size = 0;
	}
	else
	{
		t_new->content = malloc(sizeof(content));
		if (t_new->content == NULL)
		{
			free(t_new);
			return (NULL);
		}
		ft_memmove(t_new->content, content, content_size);
		t_new->content_size = content_size;
		t_new->next = NULL;
	}
	return (t_new);
}
