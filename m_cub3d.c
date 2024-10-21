/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cub3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:11:48 by mrios-he          #+#    #+#             */
/*   Updated: 2024/10/21 18:32:11 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_cub3d.h"


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

int ft_charinstr(const char *str, char c)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

void set_keystate(t_keybinds *keybinds, int key, bool pressed)
{
	if (key == ROTATE_LEFT)
		keybinds->rotate_left = pressed;
	else if (key == ROTATE_RIGHT)
		keybinds->rotate_right = pressed;
	if (key == ROTATE_UP)
		keybinds->rotate_up = pressed;
	else if (key == ROTATE_DOWN)
		keybinds->rotate_down = pressed;
	else if (key == FORWARD_W_Z)
		keybinds->forwards = pressed;
	else if (key == BACK_S_S)
		keybinds->backwards = pressed;
	else if (key == LEFT_A_Q)
		keybinds->left = pressed;
	else if (key == RIGHT_D_D)
		keybinds->right = pressed;
	else if (key == JUMP_SPACE)
		keybinds->jump = pressed;
}

void clean_and_exit(int exit_code, t_game *game)
{
    int i;

    if (game->f_c)
    {
        for (i = 0; game->f_c[i]; i++)
        {
            free(game->f_c[i]);
        }
        free(game->f_c);
    }
    if (game->map)
    {
        for (i = 0; game->map[i]; i++)
        {
            free(game->map[i]);
        }
        free(game->map);
    }
    exit(exit_code);
}

void ft_error(t_game *game, const char *message)
{
    printf("Error: %s\n", message);

    clean_and_exit(EXIT_FAILURE, game);
}

int			key_press(int keycode, t_game *game)
{
	set_keystate(&(game->keybinds), keycode, true);
	if (keycode == ESC)
		clean_and_exit(0, game);
	return (0);
}

int			key_lift(int keycode, t_game *game)
{
	set_keystate(&(game->keybinds), keycode, false);
	return (0);
}
int		ft_is_map(char *str, t_game *game)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    if (ft_charinstr(str, '1') == 1 || ft_charinstr(str, '0') == 1)
    {
        while (str[i] != '\0')
        {
            if (str[i] != ' ' && str[i] != '0' && str[i] != '1' \
                    && str[i] != '2' && str[i] != 'N' && str[i] != 'S' \
                    && str[i] != 'E' && str[i] != 'W' && str[i] != '\n'
                    && str[i] != '\t')
            {
                game->wrongcharmap = 2;
                return (0);
            }
            i++;
        }
        return (1);
    }
    return (0);
}

void init_map_row(t_game *game, int y, int len)
{
    game->map[y] = malloc(sizeof(char) * (len + 1));
    if (!game->map[y])
    {
        perror("Failed to allocate memory for map row");
        exit(EXIT_FAILURE);
    }
    ft_memset(game->map[y], 0, len + 1);
}

int	lines_in_file(char *path)
{
	int		fd;
	char	*line;
	int		lines;

	fd = open(path, O_RDONLY);
	lines = 0;
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

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

int is_map_line(char *line)
{
	
    int i = 0;

	if (line == NULL)
	{
        return 0;
	}
    while (line[i] != '\0')
    {
        if (!ft_charinstr(ELEM, line[i]))
            return 0;
        i++;
    }
    return 1;
}

void read_texture(t_game *game, char *line)
{
	static int i = 0;

    if (check_texture(line, "NO"))
        game->paths.no_path = strstr(line, "textures");
    else if (check_texture(line, "SO"))
        game->paths.so_path = strstr(line, "textures");
    else if (check_texture(line, "EA"))
        game->paths.ea_path = strstr(line, "textures");
    else if (check_texture(line, "WE"))
        game->paths.we_path = strstr(line, "textures");
    else if (check_texture(line, "F"))
        game->paths.f_path = strstr(line, "textures");
    else if (check_texture(line, "C"))
        game->paths.c_path = strstr(line, "textures");
	else if (is_map_line(line))
	{
		init_map_row(game, i, strlen(line));
		game->map[i++] = line;
	}
}

int lines_with_one(const char *file_path)
{
    int fd;
    char *line;
    int count = 0;

    if ((fd = open(file_path, O_RDONLY)) == -1)
        return -1;

    while ((line = get_next_line(fd)) != NULL)
    {
        if (ft_strchr(line, '1') != NULL)
            count++;
        free(line);
    }
    close(fd);
    return count;
}

void ft_parsing(char *file_path, t_game *game)
{
    int fd;
    char *line;
    int i = 0;

    if ((fd = open(file_path, __O_DIRECTORY)) != -1)
    {
        close(fd);
        ft_error(game, "Invalid: is a directory\n");
    }
    if ((fd = open(file_path, O_RDONLY)) == -1)
	{
		ft_error(game, "Invalid .cub file\n");
	}
	game->map = (char **)malloc((lines_with_one(file_path) + 1) * sizeof(char *));
    if (!game->map)
    {
        close(fd);
        ft_error(game, "Memory allocation failed\n");
    }
	game->tmp = (char **)malloc((lines_with_one(file_path) + 1) * sizeof(char *));
    if (!game->tmp)
    {
        close(fd);
        ft_error(game, "Memory allocation failed\n");
    }
    line = get_next_line(fd);
    while (line != NULL)
    {
    	read_texture(game, line);
        line = get_next_line(fd);
    }
	game->map[i] = NULL;
	game->tmp[i] = NULL;
    close(fd);
}

int		ft_cub(char *str, t_game *game)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_error(game, "Map name invalid\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, game);
	else
		ft_error(game, "Map name invalid\n");
	return (0);
}

int	beflastline(char **map, int y)
{
	if (map[y + 1] != NULL && map[y + 2] != NULL)
		return (1);
	return (0);
}

size_t	line_length(char *line, char *pos)
{
	size_t	i;

	i = 0;
	while (line[i] && &line[i] != pos)
	{
		i++;
	}
	return (i + 1);
}

int	valid_cell_path(t_game *game, int y, int x)
{
	char	pos;
	size_t	length;

	pos = game->p_dir;
	length = line_length(game->tmp[y], &game->tmp[y][x]);
	if (y > 0 && length > (ft_strlen(game->tmp[y - 1]) - 1))
		return (1);
	else if (game->tmp[y + 1] && length > (ft_strlen(game->tmp[y + 1]) 
			- beflastline(game->tmp, y)))
		return (1);
	if (game->tmp[y][x] == ' ' || ((game->tmp[y][x] == '0' || game->tmp[y][x] 
			== pos) && y == 0) 
		|| ((game->tmp[y][x] == '0' || game->tmp[y][x] == 
			pos) && game->tmp[y + 1] == NULL) 
		|| ((game->tmp[y][x] == '0' || game->tmp[y][x] 
			== pos) && x == 0) 
		|| ((game->tmp[y][x] == '0' || game->tmp[y][x] 
			== pos) && (game->tmp[y][x + 1] == '\n' 
		|| game->tmp[y][x + 1] == '\0')))
	{
		return (1);
	}
	return (0);
}

void check_valid_path(t_game *game, int y, int x)
{
	 if (x < 0 || y < 0 || game->map[y] == NULL || x >= (int)strlen(game->map[y]))
        return;
    if (game->map[y][x] == 'V' || game->map[y][x] == '1')
        return;

    if (valid_cell_path(game, y, x))
    {
        printf("Map path isn't valid\n");
        exit(1);
    }
    else if (game->map[y][x] == game->p_dir || game->map[y][x] == '0')
    {
        game->map[y][x] = 'V';
        check_valid_path(game, y, x + 1);
        if (x > 0)
            check_valid_path(game, y, x - 1);
        if (game->map[y + 1] != NULL)
            check_valid_path(game, y + 1, x);
        if (y > 0)
            check_valid_path(game, y - 1, x);
    }
}

void check_map_walls(t_game *game)
{
    int i = 0;
    int j;

    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j] && game->map[i][j] != '\n')
        {
            if (i == 0 || game->map[i + 1] == NULL)
            {
                if (game->map[i][j] != '1' && game->map[i][j] != ' ')
                    exit(1);
            }
            else if (j == 0 || game->map[i][j + 1] == '\n')
            {
                if (game->map[i][j] != '1' && game->map[i][j] != ' ')
                    exit(1);
            }
            j++;
        }
        i++;
    }
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

void	check_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		if (is_map_line(game->map[i]) == 1 || !empty_line(game->map[i]))
		{
			printf("Error, Map can only be composed of 01NSWE.\n");
			exit(1);
		}
		i++;
	}
}

void	duplicate_player(t_game *game)
{
	int	i;
	int	j;
	int	v;

	i = 0;
	v = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
				v++;
			j++;
		}
		i++;
	}
	if (v != 1)
	{
		printf("NO DUPLICATES\n");
		exit(1);
	}
}

void get_player_pos(t_game *game)
{
    int i = 0;
    int j;

    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || 
                game->map[i][j] == 'E' || game->map[i][j] == 'W')
            {
                game->p_dir = game->map[i][j];
                game->p_x = i;
                game->p_y = j;
                return;
            }
            j++;
        }
        i++;
    }
}
/*
void	play_sound_alt(uint32_t s, bool play, bool loop)
{
	if (!s)
		return ;
	if (loop)
		BASS_ChannelFlags(s,
			BASS_SAMPLE_LOOP, BASS_SAMPLE_LOOP);
	if (play)
		BASS_ChannelPlay(s, 0);
	else
		BASS_ChannelPause(s);
}*/

int		main(int argc, char **argv)
{
	t_game game;

	game.mlx = mlx_init();
	game.f_c = NULL;
    game.map = NULL;
	if (argc == 2)
	{
	    ft_cub(argv[1], &game);
	    game.win = mlx_new_window(game.mlx, 1700, 1000, "Cub3D");
	    //if (game.sounds.ambient)
	    //	play_sound_alt(game.sounds.ambient, true, true);
		check_map(&game);
		//duplicate_player(&game);
		get_player_pos(&game);	
		check_map_walls(&game);
		check_valid_path(&game, game.p_x, game.p_y);    	
		mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	    mlx_hook(game.win, 3, 1L << 1, key_lift, &game);
	    //mlx_hook(game.win, 33, 1L << 17, clean_and_exit_z, &game);
	    mlx_loop(game.mlx);	
  	}
	else
		write(1, "Error\nArguments\n", 16);
}
