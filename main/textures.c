/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:01:19 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/12 17:27:16 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_cub3d.h"

int	check_texture(char *line, char *direction)
{
	if (ft_strnstr(line, direction, ft_strlen(line)))
		return (1);
	return (0);
}

char	*rm_nl(char *str)
{
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	trimmed = malloc((sizeof(char) * i) + 1);
	while (str[j] && str[j] != '\n')
	{
		trimmed[j] = str[j];
		j++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}

void	set_texture_path(char *line, char *texture, char **path)
{
	char	*temp;
	char	*trimmed_temp;
	char	*found_texture;

	found_texture = ft_strnstr(line, texture, ft_strlen(line));
	if (found_texture)
	{
		temp = rm_nl(found_texture + ft_strlen(texture));
		trimmed_temp = temp;
		while (*trimmed_temp == ' ' || *trimmed_temp == '\t'
			|| *trimmed_temp == '\n' || *trimmed_temp == '\r'
			|| *trimmed_temp == '\v' || *trimmed_temp == '\f')
			trimmed_temp++;
		if (*path != NULL)
			free(*path);
		*path = malloc(ft_strlen(trimmed_temp) + 1);
		if (*path == NULL)
		{
			perror("Failed to allocate memory");
			exit(EXIT_FAILURE);
		}
		ft_strlcpy(*path, trimmed_temp, ft_strlen(trimmed_temp) + 1);
		free(temp);
	}
}

void	read_texture(t_game *game, char *line)
{
	set_texture_path(line, "NO", &game->paths.no_path);
	set_texture_path(line, "SO", &game->paths.so_path);
	set_texture_path(line, "EA", &game->paths.ea_path);
	set_texture_path(line, "WE", &game->paths.we_path);
	set_texture_path(line, "F", &game->paths.f_path);
	set_texture_path(line, "C", &game->paths.c_path);
}
