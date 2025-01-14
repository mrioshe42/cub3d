/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:01:12 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/12 17:02:22 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calculate_initial_step_and_side_distances(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	set_color(double d_factor, int *color)
{
	int	r;
	int	g;
	int	b;

	r = (*color & 0xFF0000) >> 16;
	g = (*color & 0xFF00) >> 8;
	b = *color & 0xFF;
	r = (int)(r * d_factor);
	g = (int)(g * d_factor);
	b = (int)(b * d_factor);
	*color = r << 16 | g << 8 | b;
}
