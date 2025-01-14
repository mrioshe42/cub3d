/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:12:27 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/11 16:41:41 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_CUB3D_H
# define M_CUB3D_H

# include "./cub3d.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>

# define ESC 65307
# define BUFFER_SIZE 42
# define ELEM "01NSEWDOZX "

void	init_struct(t_game *game, char **argv);
int		init_map(char *str, t_game *game);
void	validate_map(t_game *game);
void	check_map(t_game *game);
void	duplicate_player(t_game *game);
void	get_player_pos(t_game *game);
void	check_map_walls(t_game *game);
int		close_window(t_game *game);
void	clean_exit(t_game *game);
void	duplicate_player(t_game *game);
void	ft_error(t_game *game, char *message);
void	read_map(char *file_path, t_game *game);
void	init_map_row(t_game *game, int y, int len);
char	*get_next_line(int fd);
int		ft_charinstr(char *str, char c);
size_t	ft_strlen_n(const char *str);
void	read_texture(t_game *game, char *line);
int		lines_with_one(t_game *game, char *file_path);
int		map_row(const char *line);
int		key_press(int keycode, t_game *game);

#endif
