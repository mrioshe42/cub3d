/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:52:13 by mrios-he          #+#    #+#             */
/*   Updated: 2024/10/23 18:52:56 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_cub3d.h"

int	open_map_file(char *file_path, t_game *game)
{
	int	fd;

	fd = open(file_path, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_error(game, "Map is a directory\n");
	}
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_error(game, "Invalid .cub file\n");
	}
	return (fd);
}

void	allocate_map_memory(t_game *game, size_t map_lines)
{
	game->mapinfo.map = (char **)malloc((map_lines + 1) * sizeof(char *));
	if (!game->mapinfo.map)
	{
		ft_error(game, "Memory allocation failed\n");
	}
}

void	read_map_lines(int fd, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (map_row(line))
		{
			init_map_row(game, i, ft_strlen_n(line));
			ft_strlcpy(game->mapinfo.map[i], line, ft_strlen_n(line) + 1);
			i++;
		}
		read_texture(game, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game->mapinfo.map[i] = NULL;
}

void	copy_map_to_tmp(t_game *game, size_t map_lines)
{
	size_t	row_len;
	int		i;

	i = 0;
	game->mapinfo.tmp = (char **)malloc((map_lines + 1) * sizeof(char *));
	if (!game->mapinfo.tmp)
	{
		ft_error(game, "Memory allocation failed\n");
	}
	while (game->mapinfo.map[i])
	{
		row_len = ft_strlen(game->mapinfo.map[i]);
		game->mapinfo.tmp[i] = (char *)malloc((row_len + 1) * sizeof(char));
		if (!game->mapinfo.tmp[i])
		{
			ft_error(game, "Memory allocation failed\n");
		}
		ft_strlcpy(game->mapinfo.tmp[i], game->mapinfo.map[i], row_len + 1);
		i++;
	}
	game->mapinfo.tmp[i] = NULL;
}

void	read_map(char *file_path, t_game *game)
{
	size_t	map_lines;
	int		fd;

	fd = open_map_file(file_path, game);
	map_lines = lines_with_one(game, file_path);
	if (!map_lines)
	{
		close(fd);
		ft_error(game, "Failed to read file\n");
	}
	allocate_map_memory(game, map_lines);
	read_map_lines(fd, game);
	copy_map_to_tmp(game, map_lines);
	close(fd);
}
