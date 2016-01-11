/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibenoit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:31:48 by pibenoit          #+#    #+#             */
/*   Updated: 2015/12/21 21:13:42 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

void	ft_exit(char map[16][16], int taille);
void	ft_free(char **ptr);
void	ft_point(char **map, char taille);
char	**ft_init(char taille);
void	ft_file(const char *str_in, char BUF[547]);
void	ft_ragequit(void);
void	test_number(char *str);
void	test_char(char *str);
void	test_return(char *str);
void	ft_erreur(char *str);
int		ft_sqrt(unsigned char nb);
void	ft_search_other(char *str, char order_figure[27], unsigned int i);
void	ft_search_five(char *str, char order_figure[27]);
void	ft_search_six(char *str, char order_figure[27]);
void	ft_search_seven(char *str, char order_figure[27]);
void	ft_search_eight(char *str, char order_figure[27]);
void	ft_search_nine(char *str, char order_figure[27]);
void	ft_search_ten(char *str, char order_figure[27]);
void	ft_recognition(char *str, char order_figure[27]);
void	ft_search(char *str, char order_figure[27]);
int		ft_place(char **square, char forme, char letter, int tab[3]);
int		ft_threed(char **square, char forme, char letter, int tab[3]);
int		ft_twod(char **square, char forme, char letter, int tab[3]);
int		ft_twodi(char **square, char forme, char letter, int tab[3]);
int		ft_onedthreeptwod(char **square, char forme, char letter, int tab[3]);
int		ft_onedthreep(char **square, char forme, char letter, int tab[3]);
int		ft_onedtwop(char **square, char forme, char letter, int tab[3]);
int		ft_deplace(char **map, char figure, char letter, int tab[3]);
void	ft_copy(char **map, char save[16][16], char taille);
int		ft_try_copy(char **map, char save[16][16], int taille);
void	ft_select_copy(char **m, char s[16][16], int t, int l);
int		ft_save(char **ptr_map, char ptr_map_saved[16][16], char taille, char nb_figure);
int		ft_len(char **ptr_map);
void	ft_del(char **ptr_map, char letter, char taille);
int		ft_treatment(char **ptr_map, char ptr_map_saved[16][16], char order_figure[27], int i);
void	ft_zero(void *s, unsigned int n);
void	ft_bzero(void *s, unsigned int n);

void	print_test(char **map);
int		ft_len_save(char s[16][16]);
void	ft_clean(char s[16][16], int taille);

#endif
