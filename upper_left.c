/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhetman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:02:38 by yhetman           #+#    #+#             */
/*   Updated: 2018/11/25 17:51:24 by yhetman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_upperleft(t_piece *piece)
{
	int		i;
	int		x_position;
	int		y_position;

	while (piece)
	{
		i = -1;
		x_position = 3;
		y_position = 3;
		while (++i < 4)
		{
			if (piece->x[i] < x_position)
				x_position = piece->x[i];
			if (piece->y[i] < y_position)
				y_position = piece->y[i];
		}
		i = -1;
		while (++i < 4)
		{
			piece->x[i] -= x_position;
			piece->y[i] -= y_position;
		}
		piece = piece->next;
	}
}
