/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:43:41 by aspizhav          #+#    #+#             */
/*   Updated: 2018/11/15 16:43:42 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
# define BUFF_SIZE (21 * 26)
# define SIZE 4

typedef struct		s_piece
{
	char			letter;
	int				x[4];
	int				y[4];
	int				width;
	int				height;
	struct s_piece	*next;
}					t_piece;

char				**read_file(int fd);
int					check_chars(char *piece);
int					count_neighbours(char **piece);
int					is_valid(char *piece);
void				move_upperleft(t_piece *piece);
void				print_map(char **area);
void				print_tetra(t_piece *tetra);
char				**create_map(int size);
void				set_size(t_piece *piece);
char				***split_tetro(char **piece);
t_piece				*new_tetro(int size);
t_piece				*create_tetro(char ***arr_of_tetro, t_piece *piece,
					char letter, int *linker);
t_piece				*tetromino(char **piece);
void				set_piece(t_piece *piece, char **map, int y, int x);
int					check_place(t_piece *piece, char **map, int y, int x);
int					track_that_back(char **map, t_piece *pieces, int size);
char				**solvation(t_piece *pieces);
int					ft_sqrt(int x);
int					g_tetrimino;

#endif
