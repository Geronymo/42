/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:52:32 by pibenoit          #+#    #+#             */
/*   Updated: 2016/01/09 18:12:17 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include "libft/libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2, int *cpt);
char	*ft_alloc_n_read(int const fd, char *str, char *end);
char	**ft_copy(char **str, char **line, char *end);
int		get_next_line(int const fd, char **line);
char	*ft_strsub_gnl(char *s, unsigned int start, size_t len);

#endif