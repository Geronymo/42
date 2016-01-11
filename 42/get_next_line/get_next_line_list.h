/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 19:00:07 by pibenoit          #+#    #+#             */
/*   Updated: 2016/01/10 19:21:36 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_LIST_H
# define GET_NEXT_LINE_LIST_H
# include "libft/libft.h"
# define BUFF_SIZE 1000

char	*ft_strjoin_gnl(char* s1, char *s2, int *cpt);
char	*ft_alloc_n_read(int const fd, char *str, int *end);
char	**ft_copy(char **str, char **line, int *end, int cpt);
t_list	*ft_help(t_list **debut, int const fd);
int		get_next_line(int const fd, char **line);

#endif

