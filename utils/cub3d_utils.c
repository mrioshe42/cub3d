/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:23:55 by mrios-he          #+#    #+#             */
/*   Updated: 2024/10/23 19:04:00 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_cub3d.h"

int	ft_charinstr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen_n(const char *str)
{
	int	count;

	count = 0;
	while (*str != '\n')
	{
		count++;
		str++;
	}
	return (count);
}

int	map_row(const char *line)
{
	if (line[0] == '\0' || line[0] == '\n'
		|| (line[0] == 'N' && line[1] == 'O')
		|| (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'W' && line[1] == 'E')
		|| (line[0] == 'E' && line[1] == 'A')
		|| (line[0] == 'F' && line[1] == ' ')
		|| (line[0] == 'C' && line[1] == ' '))
		return (0);
	return (1);
}

int	lines_with_one(t_game *game, char *file_path)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_error(game, "Fail to open file");
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (map_row(line))
			count++;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (count);
}

void	get_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->mapinfo.map[i])
	{
		j = 0;
		while (game->mapinfo.map[i][j])
		{
			if (game->mapinfo.map[i][j] == 'N'
				|| game->mapinfo.map[i][j] == 'S'
				|| game->mapinfo.map[i][j] == 'E'
				|| game->mapinfo.map[i][j] == 'W')
			{
				game->player.p_dir = game->mapinfo.map[i][j];
				game->player.pos_x = j;
				game->player.pos_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
