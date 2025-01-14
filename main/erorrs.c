/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erorrs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:03:19 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/12 17:18:40 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_cub3d.h"

void	ft_error(t_game *game, char *message)
{
	write(2, "Error : ", 9);
	write(2, message, ft_strlen(message));
	clean_exit(game);
}

void	end_thread(t_game *game)
{
	if (game->thread_active)
	{
		if (pthread_join(game->enemy_thread, NULL) != 0)
			perror("Failed to join thread");
		if (pthread_join(game->enemy_thread, NULL) != 0)
			perror("Failed to join thread");
	}
}

void	free_texture_paths(t_game *game)
{
	if (game->paths.no_path)
		free(game->paths.no_path);
	if (game->paths.so_path)
		free(game->paths.so_path);
	if (game->paths.ea_path)
		free(game->paths.ea_path);
	if (game->paths.we_path)
		free(game->paths.we_path);
	if (game->paths.f_path)
		free(game->paths.f_path);
	if (game->paths.c_path)
		free(game->paths.c_path);
}

void	free_colors(char **colors)
{
	free(colors[0]);
	free(colors[1]);
	free(colors[2]);
	free(colors);
}
