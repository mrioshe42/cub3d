/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:50:04 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/12 16:50:31 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_cub3d.h"

static char	*read_line(int fd, char *buff, char *backup)
{
	int		read_line;
	char	*save;

	read_line = 1;
	while (read_line)
	{
		read_line = read(fd, buff, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buff[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		save = backup;
		backup = ft_strjoin(save, buff);
		free(save);
		save = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (backup);
}

static char	*get_line(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = read_line(fd, buff, backup);
	free(buff);
	if (!line)
		return (NULL);
	backup = get_line(line);
	return (line);
}
