/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:26:20 by tpapatza          #+#    #+#             */
/*   Updated: 2024/11/12 17:17:20 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_rays(t_game *game)
{
	game->ray.hit_obj = 0;
	game->ray.wall_x = 0.0;
	game->ray.perp_wall_dist = 1.0;
	game->ray.line_h = 0;
}

void	init_obj(t_game *game)
{
	game->ray.obj.draw_s = 0;
	game->ray.obj.draw_e = 0;
	game->ray.obj.obj_x = 0.0;
	game->ray.obj.height = 0;
}

void	init_img(t_game *game)
{
	game->img.img = NULL;
	game->img.w = 0;
	game->img.h = 0;
	game->img.addr = NULL;
}

void	init_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < 35)
	{
		game->enemies[i].img.img = NULL;
		game->enemies[i].img.w = 0.0;
		game->enemies[i].img.h = 0.0;
		i++;
	}
}

void	init_game(t_game *game)
{
	init_player(game);
	init_map_and_enemies(game);
	init_minimap(game);
	init_rays(game);
	init_obj(game);
	init_img(game);
	init_enemies(game);
}
