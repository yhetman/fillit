/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 20:52:57 by yhetman           #+#    #+#             */
/*   Updated: 2018/11/25 17:51:18 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_chars(char *piece)
{
	int		i;
	int		endl;
	int		hash;
	int		chars;

	i = 0;
	hash = 0;
	chars = 0;
	endl = 0;
	while ((piece[i] == '.' || piece[i] == '#'
		|| piece[i] == '\n') && piece[i] && (endl != 4))
	{
		if (piece[i] == '.' || piece[i] == '#')
		{
			if (piece[i] == '#')
				hash += 1;
			chars += 1;
		}
		if (piece[i++] == '\n')
			endl += 1;
	}
	if (((chars) == 16) && (endl == 4) && (hash == 4)
		&& (piece[i] == '\n' || piece[i] == '\0'))
		return (1);
	return (0);
}

int		count_neighbours(char **piece)
{
	int		neighbour;
	int		x;
	int		y;

	neighbour = 0;
	y = -1;
	while (4 > ++y)
	{
		x = -1;
		while (4 > ++x)
		{
			if (piece[y][x] == '#' && x < 3)
				piece[y][x + 1] == '#' ? neighbour++ : neighbour;
			if (piece[y][x] == '#' && x > 0)
				piece[y][x - 1] == '#' ? neighbour++ : neighbour;
			if (piece[y][x] == '#' && y < 3)
				piece[y + 1][x] == '#' ? neighbour++ : neighbour;
			if (piece[y][x] == '#' && y > 0)
				piece[y - 1][x] == '#' ? neighbour++ : neighbour;
		}
	}
	if (neighbour == 6 || neighbour == 8)
		return (1);
	return (0);
}

int		is_valid(char *piece)
{
	if (check_chars(piece))
		if (count_neighbours((ft_strsplit(piece, '\n'))))
			return (1);
	return (0);
}
