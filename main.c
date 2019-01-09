/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:43:56 by aspizhav          #+#    #+#             */
/*   Updated: 2018/11/26 11:43:59 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**map;
	t_piece *pieces;

	if (argc != 2)
		ft_putstr("usage: fillit source_file\n");
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			print_error();
		else if ((map = read_file(fd)) && (ft_strlen(map[0])) &&
			(!map[g_tetrimino - 1][20]))
		{
			pieces = tetromino(map);
			map = solvation(pieces);
			print_map(map);
			free(pieces);
			ft_memdel((void **)map);
		}
		else
			print_error();
		close(fd);
	}
	return (0);
}
