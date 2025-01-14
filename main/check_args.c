/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:47:29 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/12 16:18:29 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_cub3d.h"

void	duplicate_player(t_game *game)
{
	char	**map;
	int		i;
	int		j;
	int		v;

	i = 0;
	v = 0;
	map = game->mapinfo.map;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W'))
				v++;
			j++;
		}
		i++;
	}
	if (v != 1)
	{
		ft_error(game, "duplicates found.\n");
		clean_exit(game);
	}
}

void	flood_fill(t_game *game, int x, int y)
{
	if (game->mapinfo.tmp[x][y] == '1')
		return ;
	if (game->mapinfo.tmp[x][y] == ' ' || game->mapinfo.tmp[x][y] == '\0')
		ft_error(game, "Map is not closed\n");
	if (game->mapinfo.tmp[x][y] == 'V')
		return ;
	game->mapinfo.tmp[x][y] = 'V';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	check_map_walls(t_game *game)
{
	if (!game->mapinfo.tmp || !game->mapinfo.tmp[0])
	{
		ft_error(game, "Map is not initialized\n");
	}
	flood_fill(game, game->player.pos_y, game->player.pos_x);
}

void	check_map(t_game *game)
{
	size_t	i;
	size_t	j;

	if (!game->mapinfo.map[0])
		ft_error(game, "no map\n");
	i = 0;
	while (game->mapinfo.map[i])
	{
		j = 0;
		while (game->mapinfo.map[i][j] != '\0')
		{
			if (!ft_charinstr(ELEM, game->mapinfo.map[i][j]))
				ft_error(game, "Invalid element.\n");
			j++;
		}
		i++;
	}
}
