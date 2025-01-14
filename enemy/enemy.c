/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:12:53 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/12 17:23:49 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_foe(t_game *game, int i)
{
	t_directions	dir;
	int				next_x;
	int				next_y;

	next_x = game->foes[i].x;
	next_y = game->foes[i].y;
	dir = get_random_direction();
	calculate_next_position(&next_x, &next_y, dir);
	if (next_y >= 0 && next_y < game->mapinfo.height && next_x >= 0
		&& next_x < game->mapinfo.width
		&& game->mapinfo.map[next_y][next_x] == '0')
	{
		game->mapinfo.map[game->foes[i].y][game->foes[i].x] = '0';
		game->foes[i].x = next_x;
		game->foes[i].y = next_y;
		game->mapinfo.map[next_y][next_x] = 'Z';
	}
}

void	update_all_foes(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->n_foes)
	{
		move_foe(game, i);
		i++;
	}
}

void	*update_ep(void *arg)
{
	t_game	*game;

	game = (t_game *)arg;
	while (1)
	{
		sleep(1);
		update_all_foes(game);
	}
	return (NULL);
}

void	handle_foe(t_game *game, int x, int y)
{
	t_foe	*new_foes;
	int		i;

	i = 0;
	new_foes = malloc(sizeof(t_foe) * (game->n_foes + 1));
	if (!new_foes)
	{
		if (game->foes)
			free(game->foes);
		exit(EXIT_FAILURE);
	}
	while (i < game->n_foes)
	{
		new_foes[i] = game->foes[i];
		i++;
	}
	new_foes[game->n_foes].x = x;
	new_foes[game->n_foes].y = y;
	game->n_foes++;
	free(game->foes);
	game->foes = new_foes;
}

void	init_enemy(t_game *game)
{
	int	y;
	int	x;
	int	row_length;

	y = 0;
	while (game->mapinfo.map[y] != NULL)
	{
		x = 0;
		row_length = ft_strlen(game->mapinfo.map[y]);
		while (x < row_length)
		{
			if (game->mapinfo.map[y][x] == 'Z')
			{
				handle_foe(game, x, y);
			}
			x++;
		}
		y++;
	}
}
