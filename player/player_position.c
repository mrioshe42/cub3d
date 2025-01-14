/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:03:54 by tpapatza          #+#    #+#             */
/*   Updated: 2024/11/12 17:28:40 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	put_map_pixel(t_game *game, int x, int y, int color)
{
	int	j;
	int	i;
	int	scale;

	scale = (WIN_H * 0.25) / 13;
	j = 0;
	while (j < scale)
	{
		i = 0;
		while (i < scale)
		{
			mlx_pixel_put(game->mlx, game->win, x * scale + i, y * scale + j,
				color);
			i++;
		}
		j++;
	}
}

int	get_color_minimap(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->mapinfo.height
		|| game->mapinfo.map[y] == NULL
		|| x >= (int)ft_strlen(game->mapinfo.map[y]))
		return (MAP_OUTSIDE);
	if (game->mapinfo.map[y][x] == '1')
		return (MAP_WALL);
	else if (x == (int)game->player.pos_x && y == (int)game->player.pos_y)
		return (MAP_PLAYER);
	else if (game->mapinfo.map[y][x] == 'Z')
		return (MAP_FOE);
	else if (game->mapinfo.map[y][x] == '0')
		return (MAP_FLOOR);
	else if (game->mapinfo.map[y][x] == 'D' || game->mapinfo.map[y][x] == 'O')
		return (MAP_DOOR);
	else if (game->mapinfo.map[y][x] == 'X')
		return (MAP_EXIT);
	else
		return (MAP_OUTSIDE);
}

void	mini_map(t_game *game, int x, int y)
{
	int	color;

	color = 0;
	color = get_color_minimap(game, (int)game->player.pos_x - 6 + x,
			(int)game->player.pos_y - 6 + y);
	put_map_pixel(game, x, y, color);
}
