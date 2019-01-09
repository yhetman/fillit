/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 21:14:56 by yhetman           #+#    #+#             */
/*   Updated: 2018/11/25 17:50:18 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		set_size(t_piece *piece)
{
	int		line;
	int		column;
	int		width;
	int		height;

	line = -1;
	width = 0;
	height = 0;
	while (++line < 4)
	{
		column = -1;
		while (++column < 4)
		{
			(piece->x[line] == piece->x[column]) ? width += 1 : width;
			(piece->y[line] == piece->y[column]) ? height += 1 : height;
		}
	}
	if ((width % 4) || (height % 4))
	{
		width += 4;
		height += 4;
	}
	piece->width = (width / 4);
	piece->height = (height / 4);
}

char		***split_tetro(char **piece)
{
	int		i;
	char	***arr_of_tetro;

	i = 0;
	if (!(arr_of_tetro = (char ***)malloc(sizeof(char **) * g_tetrimino + 1)))
		return (NULL);
	while (i < g_tetrimino)
	{
		arr_of_tetro[i] = ft_strsplit(piece[i], '\n');
		i += 1;
	}
	return (arr_of_tetro);
}

t_piece		*new_tetro(int size)
{
	int			i;
	t_piece		*new;
	t_piece		*last;

	i = 0;
	if (!(new = (t_piece *)malloc(sizeof(t_piece) + 1)))
		return (NULL);
	last = new;
	while (i++ < size)
	{
		if (!(new->next = (t_piece *)malloc(sizeof(t_piece) + 1)))
			return (NULL);
		new = new->next;
	}
	ft_memset(new, 0, (sizeof(t_piece) + 1));
	return (last);
}

t_piece		*create_tetro(char ***arr_of_tetro, t_piece *piece,
			char letter, int *linker)
{
	t_piece		*last;

	last = piece;
	linker[0] = -1;
	while (++linker[0] < g_tetrimino)
	{
		linker[3] = 0;
		linker[1] = -1;
		while (++linker[1] < 4)
		{
			linker[2] = -1;
			while (++linker[2] < 4)
			{
				if (arr_of_tetro[linker[0]][linker[1]][linker[2]] == '#')
				{
					piece->x[linker[3]] = linker[1];
					piece->y[linker[3]++] = linker[2];
				}
			}
		}
		set_size(piece);
		piece->letter = letter++;
		piece = piece->next;
	}
	return (last);
}

t_piece		*tetromino(char **piece)
{
	int			*linker;
	char		***arr_of_tetro;
	t_piece		*new_piece;

	if (!(linker = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	if (!(arr_of_tetro = (char ***)malloc(sizeof(char **) * g_tetrimino + 1)))
		return (NULL);
	new_piece = new_tetro(g_tetrimino);
	arr_of_tetro = split_tetro(piece);
	return (create_tetro(arr_of_tetro, new_piece, 'A', linker));
}
