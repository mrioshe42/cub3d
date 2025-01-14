/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:48:59 by tpapatza          #+#    #+#             */
/*   Updated: 2024/11/12 17:26:10 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	destroy_images(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->imgs.img_no.img);
	mlx_destroy_image(game->mlx, game->imgs.img_so.img);
	mlx_destroy_image(game->mlx, game->imgs.img_ea.img);
	mlx_destroy_image(game->mlx, game->imgs.img_we.img);
	mlx_destroy_image(game->mlx, game->imgs.img_door_c.img);
	mlx_destroy_image(game->mlx, game->imgs.img_door_o.img);
	mlx_destroy_image(game->mlx, game->imgs.img_exit.img);
	while (++i < 32 && game->torches[i].img.img)
		mlx_destroy_image(game->mlx, game->torches[i].img.img);
	i = 0;
	while (++i < 35 && game->enemies[i].img.img)
		mlx_destroy_image(game->mlx, game->enemies[i].img.img);
}

int	on_d(t_game *game)
{
	printf("Exiting game.\n");
	free_map(game);
	free_texture_paths(game);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	destroy_images(game);
	free(game->foes);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	system("pkill -f 'cvlc ./audio/music.mp3'");
	if (game->thread_active)
	{
		if (pthread_cancel(game->enemy_thread) != 0)
			perror("Failed to cancel thread");
		if (pthread_join(game->enemy_thread, NULL) != 0)
			perror("Failed to join thread");
		game->thread_active = 0;
	}
	exit(0);
}

/* Key codes:
65307 is the ESC key
65361 is the left arrow key
65362 is the up arrow key
65363 is the right arrow key
65364 is the down arrow key
97 is the A key
100 is the D key
101 is the Q key
113 is the E key
115 is the S key
119 is the W key */

int	on_keypress(int keysym, t_game *game)
{
	char	tile;

	tile = '\0';
	(void)game;
	if (keysym == 65307)
	{
		system("pkill vlc");
		on_d(game);
	}
	else if (keysym == 97)
		game->player.move_l_r = -1;
	else if (keysym == 100)
		game->player.move_l_r = 1;
	else if (keysym == 65362 || keysym == 119)
		game->player.move_b_f = 1;
	else if (keysym == 65364 || keysym == 115)
		game->player.move_b_f = -1;
	else if (keysym == 65361 || keysym == 113)
		game->player.rotate = 1;
	else if (keysym == 65363 || keysym == 101)
		game->player.rotate = -1;
	else if (keysym == 102)
		open_door(game, game->player.dir_x, game->player.dir_y, &tile);
	return (0);
}

int	on_keyrelease(int keysym, t_game *game)
{
	if (keysym == 65307)
		on_d(game);
	else if (keysym == 97 && game->player.move_l_r == -1)
		game->player.move_l_r = 0;
	else if (keysym == 100 && game->player.move_l_r == 1)
		game->player.move_l_r = 0;
	else if ((keysym == 65362 || keysym == 119) && game->player.move_b_f == 1)
		game->player.move_b_f = 0;
	else if ((keysym == 65364 || keysym == 115) && game->player.move_b_f == -1)
		game->player.move_b_f = 0;
	else if ((keysym == 65361 || keysym == 113) && game->player.rotate == 1)
		game->player.rotate = 0;
	else if ((keysym == 65363 || keysym == 101) && game->player.rotate == -1)
		game->player.rotate = 0;
	return (0);
}

int	on_mm(int x, int y, t_game *game)
{
	(void)y;
	if (x < WIN_W / 2 - 100)
		game->player.rotate = 1;
	else if (x > WIN_W / 2 + 100)
		game->player.rotate = -1;
	else
		game->player.rotate = 0;
	return (0);
}
