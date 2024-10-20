#  define ROTATE_LEFT 0xff51
#  define ROTATE_RIGHT 0xff53
#  define ROTATE_UP 0xff52
#  define ROTATE_DOWN 0xff54
#  define FORWARD_W_Z 0x0077
#  define BACK_S_S 0x0073
#  define RIGHT_D_D 0x0064
#  define LEFT_A_Q 0x0061
#  define JUMP_SPACE 0x0020
#  define SNEAK_MAJ 0xffe1
#  define MAKE_PORTAL 0xff0d
#  define ESC 0xff1b
# else
#  define ROTATE_LEFT 123
#  define ROTATE_RIGHT 124
#  define ROTATE_UP 126
#  define ROTATE_DOWN 125
#  define FORWARD_W_Z 13
#  define BACK_S_S 1
#  define RIGHT_D_D 2
#  define LEFT_A_Q 0
#  define JUMP_SPACE 49
#  define SNEAK_MAJ 3
#  define MAKE_PORTAL 36
#  define ESC 53

typedef struct s_keybinds {
    bool rotate_left;
    bool rotate_right;
    bool rotate_up;
    bool rotate_down;
    bool forwards;
    bool backwards;
    bool left;
    bool right;
    bool jump;
    bool sneak;
} t_keybinds;

typedef struct s_map {
    char **data;
} t_map;

typedef struct s_player {
    char direction;
    int i;
    int j;
} t_player;

typedef struct s_paths {
    char *no_path; // Path for north texture
    char *so_path; // Path for south texture
    char *ea_path; // Path for east texture
    char *we_path; // Path for west texture
} t_paths;

typedef struct s_game {
    void *mlx;              // Pointer to the graphics library
    void *win;              // Pointer to the window
    t_keybinds keybinds;   // Key bindings for the game
    t_map *map;            // Game map
    t_player player;       // Player information
    t_paths paths;         // Texture paths
    char **file_content;    // Lines from the configuration file
    int wrongcharmap;      // Error code for invalid map characters
    // Add other fields as needed, e.g., for textures, sounds, etc.
} t_game;

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
	else if (key == SNEAK_MAJ)
		keybinds->sneak = pressed;
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
                game->wrongcharmap = 2; // Store error in the game structure
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
    if (!game->map[y]) // Check for successful memory allocation
    {
        perror("Failed to allocate memory for map row");
        exit(EXIT_FAILURE);
    }
    memset(game->map[y], 0, len + 1);
}

void parse_map_data(char *file_path, t_game *game)
{
    int fd;
    char buffer;
    int x = 0, y = 0;

    if ((fd = open(file_path, O_DIRECTORY)) != -1)
        ft_error(game, "Invalid: is a directory\n");
    if ((fd = open(file_path, O_RDONLY)) == -1)
        ft_error(game, "Invalid .cub file\n");

    while (read(fd, &buffer, 1) > 0)
    {
        if (buffer == '\n')
        {
            x = 0;
            y++;
            continue;
        }
        if (x == 0)
            init_map_row(game, y, sizeof(buffer));
        ft_is_map(game, buffer, x, y);
        game->map[y][x] = buffer;
        x++;
    }
    close(fd);

    if (game->map[0] == 0)
        ft_error(game, "Map missing\n");
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
			ft_error(game, "Nom de la map invalide\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, game);
	else
		ft_error(game, "Nom de la map invalide\n");
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

	pos = game->player.direction;
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
    if (game->map[y][x] == 'V' || game->map[y][x] == '1')
        return;

    if (valid_cell_path(game, y, x))
    {
        printf("Map path isn't valid\n");
        exit(1);
    }
    else if (game->map[y][x] == game->player.direction || game->map[y][x] == '0')
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

int	check_which_texture(t_game *game, int i, char *direction)
{
	if (ft_strnstr(game->file_content[i], 
			direction, ft_strlen(game->file_content[i])))
	{
		valid_texture_line(game->file_content[i], direction);
		return (1);
	}
	return (0);
}
char	*remove_newline(char *str)
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

void	store_texture(t_game *game, int i)
{
	if (check_which_texture(game, i, "NO"))
	{
		game->paths.no_path = remove_newline(ft_strnstr(game->file_content[i],
					"textures", ft_strlen(game->file_content[i])));
	}
	else if (check_which_texture(game, i, "SO"))
	{
		game->paths.so_path = remove_newline(ft_strnstr(game->file_content[i],
					"textures", ft_strlen(game->file_content[i])));
	}
	else if (check_which_texture(game, i, "EA"))
	{
		game->paths.ea_path = remove_newline(ft_strnstr(game->file_content[i],
					"textures", ft_strlen(game->file_content[i])));
	}
	else if (check_which_texture(game, i, "WE"))
	{
		game->paths.we_path = remove_newline(ft_strnstr(game->file_content[i],
					"textures", ft_strlen(game->file_content[i])));
	}
}
int	store_textures_path(t_game *game, int length)
{
	int	i;

	i = 0;
	while (game->file_content[i] != NULL && i < length)
	{
		store_texture(game, i);
		i++;
	}
	if (check_path_rgb(game) == 0)
		return (0);
	exit(1);
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

void	parse_file_content(t_game *game)
{
	int	v;
	int	i;

	i = 0;
	v = 0;
	while (game->file_content[i] != NULL)
	{
		if (empty_line(game->file_content[i]))
			v++;
		if (v == 6)
			break ;
		i++;
	}
	if (store_textures_path(game, ++i) == 0)
	{
		store_map(game, i);
		check_map(game);
	}
	else
	{
		printf("Error, Textures needed weren't provided.\n");
		exit(1);
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
		printf("Please provide a player position in the map (NO DUPLICATES)\n");
		exit(1);
	}
}

void get_player_position(t_game *game)
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
                game->player.direction = game->map[i][j];
                game->player.i = i;
                game->player.j = j;
                return;
            }
            j++;
        }
        i++;
    }
}

int		main(int argc, char **argv)
{
	t_game game;

	game.mlx = mlx_init();
	ft_initialisation(&recup);
	if (argc == 2)
	{
	    	ft_cub(argv[1], &recup);
	        vars.win = mlx_new_window(vars.mlx, vars.resx, vars.resy, "Cub3D");
	    	if (vars.sounds.ambient)
	    		play_sound_alt(vars.sounds.ambient, true, true);
		duplicate_player(data);
		get_player_pos(data);	
		check_walls(data);
		check_valid_path(data, data->player.i, data->player.j);    	
		mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	    	mlx_hook(vars.win, 3, 1L << 1, key_lift, &vars);
	    	mlx_hook(vars.win, LINUX ? 33 : 17, 1L << 17, clean_and_exit_z, &vars);
	    	mlx_loop(vars.mlx);	
  	}
	else
		write(1, "Error\nArguments\n", 16);
  return (0);
}
