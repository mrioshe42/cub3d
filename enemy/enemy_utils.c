/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:38:10 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/12 16:38:48 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_directions	get_random_direction(void)
{
	return ((t_directions)(rand() % NUM_DIRECTIONS));
}

void	calculate_next_position(int *next_x, int *next_y, t_directions dir)
{
	if (dir == LEFT)
		(*next_x) -= 1;
	else if (dir == RIGHT)
		(*next_x) += 1;
	else if (dir == UP)
		(*next_y) -= 1;
	else if (dir == DOWN)
		(*next_y) += 1;
}
