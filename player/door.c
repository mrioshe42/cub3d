/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:07:59 by mrios-he          #+#    #+#             */
/*   Updated: 2024/10/29 16:12:35 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	toggle_door(t_game *game, int x, int y)
{
	char	*tile;

	tile = &game->mapinfo.map[y][x];
	if (*tile == DOOR_CLOSED)
		*tile = DOOR_OPEN;
	else if (*tile == DOOR_OPEN)
		*tile = DOOR_CLOSED;
}

void	open_door(t_game *game, double dir_x, double dir_y, char *tile)
{
	double	length;
	int		x;
	int		y;
	int		i;

	i = 1;
	length = sqrt(dir_x * dir_x + dir_y * dir_y);
	if (length != 0)
	{
		dir_x /= length;
		dir_y /= length;
	}
	while (i <= 2)
	{
		x = (int)(game->player.pos_x + i * dir_x);
		y = (int)(game->player.pos_y + i * dir_y);
		if (x >= 0 && (x < game->mapinfo.width && (y >= 0
					&& y < game->mapinfo.height)))
		{
			*tile = game->mapinfo.map[y][x];
			if (*tile == DOOR_CLOSED || *tile == DOOR_OPEN)
				return (toggle_door(game, x, y));
		}
		i++;
	}
}
