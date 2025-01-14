/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:11:48 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/12 17:26:56 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_cub3d.h"

void	check_lose(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->n_foes)
	{
		if ((int)game->player.pos_x == game->foes[i].x
			&& (int)game->player.pos_y == game->foes[i].y)
		{
			mlx_loop_end(game->mlx);
			system("pkill vlc");
			system("cvlc --play-and-exit ./audio/music_lose.mp3 &");
			game->img.img = mlx_xpm_file_to_image(game->mlx,
					"textures/game_over.xpm", &game->img.w, &game->img.h);
			if (game->img.img)
			{
				mlx_put_image_to_window(game->mlx, game->win, game->img.img,
					(WIN_W - game->img.w) / 2, (WIN_H - game->img.h) / 2);
				mlx_do_sync(game->mlx);
			}
			sleep(8);
			on_d(game);
		}
		i++;
	}
}

int	main_loop(t_game *game)
{
	player_move(game);
	raycasting(game);
	check_lose(game);
	check_exit(game);
	game->torches[0] = *game->torches[0].next;
	game->enemies[0] = *game->enemies[0].next;
	return (0);
}

int	handle_intro(int keysym, t_game *game)
{
	if (keysym == 65307)
	{
		mlx_loop_end(game->mlx);
	}
	return (0);
}

void	display_intro(t_game *game)
{
	char	filename[64];
	char	*num_str;
	int		i;

	i = 0;
	game->win = mlx_new_window(game->mlx, 1280, 720, "Intro");
	while (i < 81)
	{
		i++;
		num_str = ft_itoa(i);
		ft_strlcpy(filename, "intro_xpm/intro", sizeof(filename));
		ft_strlcat(filename, num_str, sizeof(filename));
		ft_strlcat(filename, ".xpm", sizeof(filename));
		free(num_str);
		game->img.img = mlx_xpm_file_to_image(game->mlx, filename,
				&game->img.w, &game->img.h);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
		mlx_destroy_image(game->mlx, game->img.img);
		usleep(80000);
	}
	mlx_destroy_window(game->mlx, game->win);
	usleep(500000);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc == 2)
	{
		system("cvlc --play-and-exit ./audio/music.mp3 &");
		init_struct(&game, argv);
		validate_map(&game);
		display_intro(&game);
		game.win = mlx_new_window(game.mlx, WIN_W, WIN_H, "Cub3D");
		init_game(&game);
		init_torches(game.torches, 32);
		load_textures(&game);
		game.thread_active = 1;
		if (pthread_create(&game.enemy_thread, NULL, update_ep, &game) != 0)
			return (perror("Failed to create enemy thread"), 1);
		mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &on_d, &game);
		mlx_hook(game.win, KeyPress, KeyPressMask, &on_keypress, &game);
		mlx_hook(game.win, KeyRelease, KeyReleaseMask, &on_keyrelease, &game);
		mlx_hook(game.win, MotionNotify, PointerMotionMask, &on_mm, &game);
		mlx_loop_hook(game.mlx, main_loop, &game);
		mlx_loop(game.mlx);
		end_thread(&game);
	}
	return (0);
}
