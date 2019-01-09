/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:43:40 by aspizhav          #+#    #+#             */
/*   Updated: 2018/11/26 17:18:49 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#define Y 0
#define X 1

int			ft_sqrt(int x)
{
	long	i;

	i = 1;
	if (x < 0)
		return (0);
	while (i * i < x)
		i++;
	return (i);
}

int			back_track(char **map, t_piece *pieces, int size, int coord[])
{
	if (track_that_back(map, pieces->next, size))
		return (1);
	if (pieces->next && (pieces->x)[0] == (pieces->next->x)[0] &&
		(pieces->x)[1] == (pieces->next->x)[1] &&
		(pieces->x)[2] == (pieces->next->x)[2] &&
		(pieces->x)[3] == (pieces->next->x)[3] &&
		(pieces->y)[0] == (pieces->next->y)[0] &&
		(pieces->y)[1] == (pieces->next->y)[1] &&
		(pieces->y)[2] == (pieces->next->y)[2] &&
		(pieces->y)[3] == (pieces->next->y)[3])
	{
		if (pieces->next)
			return (track_that_back(map, pieces->next, size));
		return (1);
	}
	pieces->letter = '.';
	set_piece(pieces, map, coord[Y], coord[X]);
	return (2);
}

int			track_that_back(char **map, t_piece *pieces, int size)
{
	int		coord[2];
	char	letter;
	int		ret;

	if (!pieces->next)
		return (1);
	coord[Y] = -1;
	letter = pieces->letter;
	while (++coord[Y] <= (size - pieces->height))
	{
		coord[X] = -1;
		while (++coord[X] <= (size - pieces->width))
		{
			if (check_place(pieces, map, coord[Y], coord[X]))
			{
				if ((ret = back_track(map, pieces, size, coord)) == 2)
					pieces->letter = letter;
				else
					return (ret);
			}
		}
	}
	return (0);
}

char		**solvation(t_piece *pieces)
{
	char	**map;
	int		size;

	if (!pieces)
		return (NULL);
	size = ft_sqrt(g_tetrimino * SIZE);
	map = create_map(size);
	move_upperleft(pieces);
	while (!track_that_back(map, pieces, size))
	{
		ft_memdel((void **)map);
		size += 1;
		map = create_map(size);
	}
	return (map);
}
