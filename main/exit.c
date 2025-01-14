/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:44:29 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/12 17:24:48 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_cub3d.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->mapinfo.map)
	{
		while (game->mapinfo.map[i])
		{
			free(game->mapinfo.map[i]);
			i++;
		}
		free(game->mapinfo.map);
		game->mapinfo.map = NULL;
	}
	i = 0;
	if (game->mapinfo.tmp)
	{
		while (game->mapinfo.tmp[i])
		{
			free(game->mapinfo.tmp[i]);
			i++;
		}
		free(game->mapinfo.tmp);
		game->mapinfo.tmp = NULL;
	}
}

int	close_window(t_game *game)
{
	clean_exit(game);
	return (0);
}

void	clean_exit(t_game *game)
{
	free_map(game);
	free_texture_paths(game);
	printf("Exiting game.\n");
	system("pkill vlc");
	mlx_loop_end(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

void	exit_error(t_game *game, char *msg, int nbr)
{
	free_texture_paths(game);
	if (msg)
		write(2, msg, ft_strlen(msg));
	free_map(game);
	if (game->imgs.img_no.img)
		mlx_destroy_image(game->mlx, game->imgs.img_no.img);
	if (game->imgs.img_so.img)
		mlx_destroy_image(game->mlx, game->imgs.img_so.img);
	if (game->imgs.img_ea.img)
		mlx_destroy_image(game->mlx, game->imgs.img_ea.img);
	if (game->imgs.img_we.img)
		mlx_destroy_image(game->mlx, game->imgs.img_we.img);
	if (game->imgs.img_door_c.img)
		mlx_destroy_image(game->mlx, game->imgs.img_door_c.img);
	if (game->imgs.img_door_o.img)
		mlx_destroy_image(game->mlx, game->imgs.img_door_o.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->foes);
	free(game->mlx);
	exit(nbr);
}

void	check_exit(t_game *game)
{
	if ((int)game->player.pos_x == game->x_exit
		&& (int)game->player.pos_y == game->y_exit)
	{
		mlx_loop_end(game->mlx);
		game->img.img = mlx_xpm_file_to_image(game->mlx, "textures/win.xpm",
				&game->img.w, &game->img.h);
		if (game->img.img)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img.img,
				(WIN_W - game->img.w) / 2, (WIN_H - game->img.h) / 2);
			mlx_do_sync(game->mlx);
		}
		sleep(5);
		system("pkill vlc");
		on_d(game);
	}
}
