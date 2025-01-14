/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:08:47 by tpapatza          #+#    #+#             */
/*   Updated: 2024/11/11 16:45:31 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	new_pos_x_y(t_game *game, double *new_pos_x, double *new_pos_y)
{
	if (game->player.move_b_f == -1)
	{
		*new_pos_x -= game->player.dir_x * PLAYER_SPEED;
		*new_pos_y -= game->player.dir_y * PLAYER_SPEED;
	}
	else if (game->player.move_b_f == 1)
	{
		*new_pos_x += game->player.dir_x * PLAYER_SPEED;
		*new_pos_y += game->player.dir_y * PLAYER_SPEED;
	}
	else if (game->player.move_l_r == -1)
	{
		*new_pos_x += game->player.dir_y * PLAYER_SPEED;
		*new_pos_y -= game->player.dir_x * PLAYER_SPEED;
	}
	else if (game->player.move_l_r == 1)
	{
		*new_pos_x -= game->player.dir_y * PLAYER_SPEED;
		*new_pos_y += game->player.dir_x * PLAYER_SPEED;
	}
}

void	player_move(t_game *game)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game->player.pos_x;
	new_pos_y = game->player.pos_y;
	new_pos_x_y(game, &new_pos_x, &new_pos_y);
	if (game->mapinfo.map[(int)new_pos_y][(int)game->player.pos_x] != '1'
		&& game->mapinfo.map[(int)new_pos_y][(int)game->player.pos_x] != 'D')
		game->player.pos_y = new_pos_y;
	if (game->mapinfo.map[(int)game->player.pos_y][(int)new_pos_x] != '1'
		&& game->mapinfo.map[(int)game->player.pos_y][(int)new_pos_x] != 'D')
		game->player.pos_x = new_pos_x;
	if (game->player.rotate == -1)
		player_rotate(game, 2);
	else if (game->player.rotate == 1)
		player_rotate(game, -2);
}
