/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:42:47 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/12 17:27:34 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_north(t_game *game)
{
	game->player.dir_x = 0.0;
	game->player.dir_y = -1.0;
	game->player.plane_x = 0.66;
	game->player.plane_y = 0.0;
	game->player.angle = 0.0;
}

static void	init_south(t_game *game)
{
	game->player.dir_x = 0.0;
	game->player.dir_y = 1.0;
	game->player.plane_x = -0.66;
	game->player.plane_y = 0.0;
	game->player.angle = M_PI;
}

static void	init_east(t_game *game)
{
	game->player.dir_x = 1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
	game->player.angle = M_PI / 2;
}

static void	init_west(t_game *game)
{
	game->player.dir_x = -1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = -0.66;
	game->player.angle = 3 * M_PI / 2;
}

void	init_player(t_game *game)
{
	game->player.pos_x = game->player.pos_x + 0.5;
	game->player.pos_y = game->player.pos_y + 0.5;
	if (game->player.p_dir == 'N')
		init_north(game);
	else if (game->player.p_dir == 'S')
		init_south(game);
	else if (game->player.p_dir == 'E')
		init_east(game);
	else if (game->player.p_dir == 'W')
		init_west(game);
	game->player.rotate = 0;
	game->player.move_b_f = 0;
	game->player.move_l_r = 0;
}
