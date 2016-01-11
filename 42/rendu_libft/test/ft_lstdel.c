/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:09:01 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/10 20:52:44 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (alst != NULL)
	{
		if ((*alst)->next != NULL)
			ft_lstdel(&(*alst)->next, del);
		del((*alst)->content, (*alst)->content_size);
		free((*alst)->next);
		free(*alst);
		*alst = NULL;
	}
}
