/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:00:56 by tpapatza          #+#    #+#             */
/*   Updated: 2024/11/12 16:59:48 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_f_c_colors(t_game *game, char *line, int *color)
{
	int		r;
	int		g;
	int		b;
	char	**colors;

	colors = ft_split(line, ',');
	if (colors[0] && colors[1] && colors[2])
	{
		r = ft_atoi(colors[0]);
		g = ft_atoi(colors[1]);
		b = ft_atoi(colors[2]);
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		{
			free_colors(colors);
			exit_error(game, "Invalid color format.\n", 2);
		}
		*color = r << 16 | g << 8 | b;
	}
	else
	{
		free_colors(colors);
		exit_error(game, "Invalid color format.\n", 2);
	}
	free_colors(colors);
}

static void	load_img_data(t_game *game, t_img *img, char *path)
{
	if (path == NULL)
		exit_error(game, "Failed to load texture.\n", 2);
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->w, &img->h);
	if (img->img)
	{
		img->addr = (int *)mlx_get_data_addr(img->img, &img->b_p_p,
				&img->size_line, &img->endian);
		if (!img->addr)
			exit_error(game, "Failed to get image data.\n", 2);
	}
	else
		exit_error(game, "Failed to load texture.\n", 2);
}

static void	load_tortches(t_game *game)
{
	char	img_name[34];
	char	*img_num;
	int		i;

	i = 0;
	init_torch(&game->torches[i]);
	while (++i < 32)
	{
		img_num = ft_itoa(i);
		ft_strlcpy(img_name, "./textures/torch_xpm/torch", 27);
		ft_strlcat(img_name, img_num, ft_strlen(img_num) + 27);
		ft_strlcat(img_name, ".xpm", ft_strlen(img_name) + 5);
		free(img_num);
		init_torch(&game->torches[i]);
		load_img_data(game, &game->torches[i].img, img_name);
		game->torches[i].num = i;
	}
	i--;
	game->torches[i].next = &game->torches[1];
	while (--i >= 0)
		game->torches[i].next = &game->torches[i + 1];
}

static void	load_enemies(t_game *game)
{
	char	img_name[34];
	char	*img_num;
	int		i;

	i = 0;
	while (++i < 35)
	{
		img_num = ft_itoa(i);
		ft_strlcpy(img_name, "./textures/enemy_xpm/enemy", 27);
		ft_strlcat(img_name, img_num, ft_strlen(img_num) + 27);
		ft_strlcat(img_name, ".xpm", ft_strlen(img_name) + 5);
		free(img_num);
		load_img_data(game, &game->enemies[i].img, img_name);
	}
	i--;
	game->enemies[i].next = &game->enemies[1];
	while (--i >= 0)
		game->enemies[i].next = &game->enemies[i + 1];
}

void	load_textures(t_game *game)
{
	init_imgs(game);
	load_img_data(game, &game->imgs.img_no, game->paths.no_path);
	load_img_data(game, &game->imgs.img_so, game->paths.so_path);
	load_img_data(game, &game->imgs.img_ea, game->paths.ea_path);
	load_img_data(game, &game->imgs.img_we, game->paths.we_path);
	set_f_c_colors(game, game->paths.f_path, &game->imgs.f_color);
	set_f_c_colors(game, game->paths.c_path, &game->imgs.c_color);
	load_img_data(game, &game->imgs.img_door_c, "./textures/door_c.xpm");
	load_img_data(game, &game->imgs.img_door_o, "./textures/door_o.xpm");
	load_img_data(game, &game->imgs.img_exit, "./textures/exit.xpm");
	load_tortches(game);
	load_enemies(game);
}
