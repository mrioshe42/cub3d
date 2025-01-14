/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:45:15 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/12 17:27:46 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_map_and_enemies(t_game *game)
{
	init_mapinfo(game);
	init_enemy(game);
}

void	init_minimap(t_game *game)
{
	game->mm_m = WIN_H * 0.25;
	game->mm_d = WIN_H * 0.2 / 10;
}
