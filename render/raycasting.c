/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:03:39 by tpapatza          #+#    #+#             */
/*   Updated: 2024/11/12 17:29:21 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	initialize_ray_variables(t_game *game, t_ray *ray, int x)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_W - 1;
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
}

static void	object_collision(t_game *game, t_ray *ray)
{
	if (ray->hit_obj == 1)
		return ;
	ray->hit_obj = 1;
	ray->obj.x = ray->map_x + 0.5;
	ray->obj.y = ray->map_y + 0.5;
	ray->obj.side = ray->side;
	ray->obj.obj_dir_x = ray->ray_dir_x;
	ray->obj.obj_dir_y = ray->ray_dir_y;
	ray->obj.dist = sqrt(pow(game->player.pos_x - ray->obj.x, 2)
			+ pow(game->player.pos_y - ray->obj.y, 2));
	ray->obj.height = (int)(WIN_H / ray->obj.dist);
	ray->obj.draw_s = -(ray->obj.height) / 2 + WIN_H / 2;
	if (ray->obj.draw_s < 0)
		ray->obj.draw_s = 0;
	ray->obj.draw_e = ray->obj.height / 2 + WIN_H / 2;
	if (ray->obj.draw_e >= WIN_H)
		ray->obj.draw_e = WIN_H - 1;
	if (ray->obj.side == 0)
		ray->obj.obj_x = game->player.pos_y + ray->obj.dist
			* ray->obj.obj_dir_y;
	else
		ray->obj.obj_x = game->player.pos_x + ray->obj.dist
			* ray->obj.obj_dir_x;
	ray->obj.obj_x -= floor(ray->obj.obj_x);
}

void	perform_dda_algorithm(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25
			|| ray->map_y > WIN_H - 0.25
			|| ray->map_x > WIN_W - 1.25)
			break ;
		else if (game->mapinfo.map[ray->map_y][ray->map_x] == '1'
				|| game->mapinfo.map[ray->map_y][ray->map_x] == 'D'
				|| game->mapinfo.map[ray->map_y][ray->map_x] == 'X')
			ray->hit = 1;
		else if (game->mapinfo.map[ray->map_y][ray->map_x] == 'Z')
			object_collision(game, ray);
	}
}

void	calculate_line_height_and_draw_range(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_h = (int)(WIN_H / ray->perp_wall_dist);
	ray->draw_start = -(ray->line_h) / 2 + WIN_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_h / 2 + WIN_H / 2;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;
	if (ray->side == 0)
		ray->wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = game->ray;
	ray.hit_obj = 0;
	ray.wall_x = 0.0;
	ray.perp_wall_dist = 1.0;
	ray.line_h = 0;
	ray.obj.draw_s = 0;
	ray.obj.draw_e = 0;
	ray.obj.obj_x = 0.0;
	ray.obj.height = 0;
	while (x < WIN_W)
	{
		initialize_ray_variables(game, &ray, x);
		calculate_initial_step_and_side_distances(game, &ray);
		perform_dda_algorithm(game, &ray);
		calculate_line_height_and_draw_range(game, &ray);
		draw_vertical_line(game, &ray, x);
		x++;
	}
}
