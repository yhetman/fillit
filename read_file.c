/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:19:54 by yhetman           #+#    #+#             */
/*   Updated: 2018/11/25 17:51:08 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**read_file(int fd)
{
	int		i;
	char	**tetriminos;

	i = 0;
	if (!(tetriminos = (char **)malloc(sizeof(char *) * (BUFF_SIZE))))
		return (NULL);
	while (i < 26)
	{
		if (!(tetriminos[i] = (char *)malloc(sizeof(char) * 21)))
			return (NULL);
		ft_bzero(tetriminos[i], 21);
		if (!(read(fd, tetriminos[i], 21)))
			return (tetriminos);
		if (!(is_valid(tetriminos[i])))
			return (NULL);
		i += 1;
		g_tetrimino = i;
	}
	return (tetriminos);
}
