/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:50:06 by yhetman           #+#    #+#             */
/*   Updated: 2018/11/25 17:50:11 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_piece(t_piece *piece, char **map, int y, int x)
{
	int		row;
	int		col;
	int		i;

	i = 0;
	col = 0;
	while (piece->height > col)
	{
		row = 0;
		while (piece->width > row)
		{
			if (piece->x[i] == col && piece->y[i] == row)
			{
				map[col + y][row + x] = piece->letter;
				i += 1;
			}
			row += 1;
		}
		col += 1;
	}
}

int		check_place(t_piece *piece, char **map, int y, int x)
{
	int		row;
	int		col;
	int		i;

	i = 0;
	col = 0;
	while (piece->height > col)
	{
		row = 0;
		while (piece->width > row)
		{
			if (piece->x[i] == col && piece->y[i] == row && i < 4)
			{
				if (map[col + y][row + x] != '.')
					return (0);
				i += 1;
			}
			row += 1;
		}
		col += 1;
	}
	set_piece(piece, map, y, x);
	return (1);
}
