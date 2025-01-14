/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:09:59 by tpapatza          #+#    #+#             */
/*   Updated: 2024/11/12 17:30:03 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_object_color(t_ray *ray, t_obj *obj, t_img *img, int y)
{
	int		color;
	int		t_x;
	int		t_y;

	if (ray->hit_obj && y >= obj->draw_s && y <= obj->draw_e)
	{
		t_x = (int)(obj->obj_x * img->w);
		t_y = (int)(y * 2 - WIN_H + obj->height)
			* (img->h / 2) / obj->height;
		if (t_x < 0 || t_x >= img->w || t_y < 0 || t_y >= img->h)
			return (0);
		color = img->addr[t_y * img->w + t_x];
		if (color >= 0x00000000)
			return (1);
	}
	return (0);
}

static int	get_texture_color(t_ray *ray, t_img *img, int y, int turn)
{
	double	d_factor;
	int		color;
	int		t_x;
	int		t_y;

	t_x = (int)(ray->wall_x * img->w);
	t_y = (int)(y * 2 - WIN_H + ray->line_h) * (img->h / 2) / ray->line_h;
	color = img->addr[t_y * img->w + t_x];
	d_factor = 1.0 / (ray->perp_wall_dist * 0.8);
	if (turn % 4 == 0)
		d_factor += 0.05;
	else if (turn % 3 == 0)
		d_factor -= 0.05;
	if (d_factor > 1.0)
		d_factor = 1.0;
	else if (d_factor < 0.1)
		d_factor = 0.1;
	set_color(d_factor, &color);
	return (color);
}

static void	get_wall_color(t_game *game, t_ray *ray, int *color, int y)
{
	int		turn;

	turn = game->torches->num;
	if (ray->perp_wall_dist > 10)
	{
		*color = 0x00000000;
		return ;
	}
	if (game->mapinfo.map[ray->map_y][ray->map_x] == 'D')
		*color = get_texture_color(ray, &game->imgs.img_door_c, y, turn);
	else if (game->mapinfo.map[ray->map_y][ray->map_x] == 'X')
		*color = get_texture_color(ray, &game->imgs.img_exit, y, turn);
	else if (ray->side == 1 && ray->ray_dir_y < 0)
		*color = get_texture_color(ray, &game->imgs.img_no, y, turn);
	else if (ray->side == 1 && ray->ray_dir_y > 0)
		*color = get_texture_color(ray, &game->imgs.img_so, y, turn);
	else if (ray->side == 0 && ray->ray_dir_x > 0)
		*color = get_texture_color(ray, &game->imgs.img_ea, y, turn);
	else if (ray->side == 0 && ray->ray_dir_x < 0)
		*color = get_texture_color(ray, &game->imgs.img_we, y, turn);
}

static int	get_torch_color(t_torch *torch, int *color, int x, int y)
{
	int		t_x;
	int		t_y;

	t_x = 0;
	t_y = 0;
	if (y >= torch->pos_y && x >= torch->pos_x
		&& x < torch->pos_x + torch->win_w
		&& y < torch->pos_y + torch->win_h)
	{
		t_x = (x - torch->pos_x) * torch->img.w / torch->win_w;
		t_y = (y - torch->pos_y) * torch->img.h / torch->win_h;
		if (t_x < 0 || t_x >= torch->img.w || t_y < 0 || t_y >= torch->img.h)
			return (0);
		*color = torch->img.addr[t_y * torch->img.w + t_x];
		if (*color >= 0x00000000)
			return (1);
	}
	return (0);
}

void	draw_vertical_line(t_game *game, t_ray *ray, int x)
{
	int	color;
	int	y;

	y = 0;
	color = 0;
	while (y < WIN_H)
	{
		if (y < game->mm_m && x < game->mm_m)
			mini_map(game, x / game->mm_d, y / game->mm_d);
		else if (get_torch_color(game->torches, &color, x, y))
			mlx_pixel_put(game->mlx, game->win, x, y, color);
		else if (check_object_color(ray, &ray->obj, &game->enemies->img, y))
			mlx_pixel_put(game->mlx, game->win, x, y, 0x00000000);
		else if (y < ray->draw_start)
			mlx_pixel_put(game->mlx, game->win, x, y, game->imgs.c_color);
		else if (y >= ray->draw_start && y <= ray->draw_end)
		{
			get_wall_color(game, ray, &color, y);
			mlx_pixel_put(game->mlx, game->win, x, y, color);
		}
		else
			mlx_pixel_put(game->mlx, game->win, x, y, game->imgs.f_color);
		y++;
	}
}
