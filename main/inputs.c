/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:26:17 by mrios-he          #+#    #+#             */
/*   Updated: 2024/10/23 19:04:22 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_cub3d.h"

int	handle_input(int keysym, t_game *game)
{
	if (keysym == 65307)
	{
		mlx_loop_end(game->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		clean_exit(game);
	return (0);
}
