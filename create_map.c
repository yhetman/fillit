/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:50:27 by yhetman           #+#    #+#             */
/*   Updated: 2018/11/25 17:50:33 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int size)
{
	char	**map;
	int		row;
	int		col;

	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	row = 0;
	while (row < size)
	{
		if (!(map[row] = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		row += 1;
	}
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
			map[row][col++] = '.';
		map[row][col] = '\0';
		row += 1;
	}
	map[row] = NULL;
	return (map);
}
