/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:11:52 by tpapatza          #+#    #+#             */
/*   Updated: 2024/11/12 17:30:37 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_torch(t_torch *torch)
{
	int	img_w;
	int	img_h;

	img_w = WIN_W / 5;
	img_h = img_w * 2;
	torch->pos_x = (3 * WIN_W / 4) - (img_w / 2);
	torch->pos_y = WIN_H - img_h;
	torch->win_w = img_w;
	torch->win_h = img_h;
	torch->next = NULL;
	torch->img.img = NULL;
	torch->img.addr = NULL;
	torch->img.w = 0;
	torch->img.h = 0;
	torch->num = 0;
}

void	init_imgs(t_game *game)
{
	game->imgs.img_no.img = NULL;
	game->imgs.img_so.img = NULL;
	game->imgs.img_ea.img = NULL;
	game->imgs.img_we.img = NULL;
	game->imgs.img_door_c.img = NULL;
	game->imgs.img_door_o.img = NULL;
	game->imgs.f_color = -1;
	game->imgs.c_color = -1;
}

void	init_mapinfo(t_game *game)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	while (game->mapinfo.map[y])
	{
		i = 0;
		while (x < (int)ft_strlen(game->mapinfo.map[y]))
		{
			if (x < i)
				x++;
			i++;
		}
		y++;
	}
	game->mapinfo.width = x;
	game->mapinfo.height = y;
	game->mapinfo.map[(int)game->player.pos_y][(int)game->player.pos_x] = '0';
}

void	init_ray(t_ray *ray)
{
	ray->perp_wall_dist = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->camera_x = 0;
	ray->wall_x = 0;
	ray->line_h = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->hit = 0;
	ray->hit_obj = 0;
}

void	init_torches(t_torch *torches, int num_torches)
{
	int	i;

	i = 0;
	while (i < num_torches)
	{
		init_torch(&torches[i]);
		i++;
	}
}
