/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:08:40 by tpapatza          #+#    #+#             */
/*   Updated: 2024/11/12 17:29:00 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	rotate_left_right(t_game *game, double rotspeed)
{
	t_player	*p;
	double		tmp_x;

	p = &game->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rotspeed) - p->dir_y * sin(rotspeed);
	p->dir_y = tmp_x * sin(rotspeed) + p->dir_y * cos(rotspeed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rotspeed) - p->plane_y * sin(rotspeed);
	p->plane_y = tmp_x * sin(rotspeed) + p->plane_y * cos(rotspeed);
	return (1);
}

int	player_rotate(t_game *game, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTATE_SPEED * rotdir;
	moved += rotate_left_right(game, rotspeed);
	return (moved);
}
