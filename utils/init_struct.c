/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:09:46 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/12 17:24:48 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_cub3d.h"

void	init_struct(t_game *game, char **argv)
{
	game->mlx = mlx_init();
	game->mapinfo.map = NULL;
	game->mapinfo.tmp = NULL;
	game->paths.no_path = NULL;
	game->paths.so_path = NULL;
	game->paths.ea_path = NULL;
	game->paths.we_path = NULL;
	game->paths.f_path = NULL;
	game->paths.c_path = NULL;
	game->foes = NULL;
	game->n_foes = 0;
	game->x_exit = 0;
	game->y_exit = 0;
	init_map(argv[1], game);
}

void	get_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->mapinfo.map[i])
	{
		j = 0;
		while (game->mapinfo.map[i][j])
		{
			if (game->mapinfo.map[i][j] == 'X')
			{
				game->x_exit = j;
				game->y_exit = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	validate_map(t_game *game)
{
	check_map(game);
	duplicate_player(game);
	get_player_pos(game);
	get_exit(game);
	check_map_walls(game);
}

void	init_map_row(t_game *game, int y, int len)
{
	game->mapinfo.map[y] = malloc(sizeof(char) * (len + 1));
	if (!game->mapinfo.map[y])
	{
		ft_error(game, "Failed to allocate memory for map row");
		on_d(game);
	}
	ft_memset(game->mapinfo.map[y], 0, len + 1);
}

int	init_map(char *str, t_game *game)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
			ft_error(game, "Map name invalid\n");
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		read_map(str, game);
	else
		ft_error(game, "Map name invalid\n");
	return (0);
}
