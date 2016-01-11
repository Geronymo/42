/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oned.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:54:33 by pbenoit           #+#    #+#             */
/*   Updated: 2015/12/21 21:34:33 by pibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"
#include <unistd.h>

int    ft_onedtwop(char **square, char forme, char letter, int tab[3])
{
	if (forme == 10 && square[tab[0] + 1][tab[1] - 2] == '.' && (tab[1] - 2) >= 0)
		square[tab[0] + 1][tab[1] - 2] = letter;
	else if (forme == 11 && square[tab[0] + 1][tab[1] + 1] == '.' && (tab[1] + 1) < tab[2])
		square[tab[0] + 1][tab[1] + 1] = letter;
	else if (forme == 12 && square[tab[0] + 2][tab[1] - 1] == '.' && (tab[0] + 2) < tab[2])
		square[tab[0] + 2][tab[1] - 1] = letter;
	else if (forme == 13 && square[tab[0] + 2][tab[1]] == '.' && (tab[0] + 2) < tab[2])
		square[tab[0] + 2][tab[1]] = letter;
	else
		return (0);
	square[tab[0]][tab[1]] = letter;
	square[tab[0] + 1][tab[1]] = letter;
	square[tab[0] + 1][tab[1] - 1] = letter;
	return (1);
}

int    ft_onedthreeptwod(char **square, char forme, char letter, int tab[3])
{
	if (forme == 14 && square[tab[0] + 2][tab[1]] == '.' && (tab[0] + 2) < tab[2])
		square[tab[0] + 2][tab[1]] = letter;
	else if (forme == 15 && square[tab[0] + 1][tab[1] + 2] == '.' && (tab[1] + 2) < tab[2]) 
		square[tab[0] + 1][tab[1] + 2] = letter;
	else if (forme == 16 && square[tab[0] + 2][tab[1] + 1] == '.' && (tab[0] + 2) < tab[2])
		square[tab[0] + 2][tab[1] + 1] = letter;
	else
		return (0);
	square[tab[0]][tab[1]] = letter;
	square[tab[0] + 1][tab[1]] = letter;
	square[tab[0] + 1][tab[1] + 1] = letter;
	return (1);
}

int    ft_onedthreep(char **square, char forme, char letter, int tab[3])
{
	if (forme == 17 && square[tab[0] + 2][tab[1] - 1] == '.' && (tab[1] - 1) >= 0)
		square[tab[0] + 2][tab[1] - 1] = letter;
	else if (forme == 18 && square[tab[0] + 2][tab[1] + 1] == '.' && (tab[1] + 1) < tab[2])
		square[tab[0] + 2][tab[1] + 1] = letter;
	else if (forme == 19 && square[tab[0] + 3][tab[1]] == '.' && (tab[0] + 3) < tab[2])
		square[tab[0] + 3][tab[1]] = letter;
	else
		return (0);
	square[tab[0]][tab[1]] = letter;
	square[tab[0] + 1][tab[1]] = letter;
	square[tab[0] + 2][tab[1]] = letter;
	return (1);
}
