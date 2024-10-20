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

int		ft_is_map(char *str, t_recup *recup)
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
				if (recup->insidemap == 1)
					recup->wrongcharmap = 2;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	init_map_row(t_game *game, int y, int len)
{
	int	i;

	i = 0;
	game->map->data[y] = malloc(sizeof(char) * (len + 1));
	ft_memset(game->map->data[y], 0, len + 1);
}
void	ft_parsing(char *fichier, t_recup *recup)
{
	int			fd;
	char		*str;

	str = NULL;
	if ((fd = open(fichier, O_DIRECTORY)) != -1)
		ft_error(recup, "Invalide : is a directory\n");
	if ((fd = open(fichier, O_RDONLY)) == -1)
		ft_error(recup, "Fichier .cub invalide\n");
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
		{
			x = 0;
			y++;
			continue ;
		}
		if (x == 0)
			init_map_row(game, y, sizeof(buff));
		handle_character(game, buffer, x, y);
		game->map->data[y][x] = buffer;
		x++;
	}
	close(fd);
	if (recup->sizeline == 0 || recup->nblines == 0)
		ft_error(recup, "Map absente\n");
	ft_parsing_map(fichier, recup);
}
int		ft_cub(char *str, t_recup *recup)
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
			ft_error(recup, "Nom de la map invalide\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, recup);
	else
		ft_error(recup, "Nom de la map invalide\n");
	return (0);
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
    	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
    	mlx_hook(vars.win, 3, 1L << 1, key_lift, &vars);
    	mlx_hook(vars.win, LINUX ? 33 : 17, 1L << 17, clean_and_exit_z, &vars);
    	mlx_loop(vars.mlx);	
  }
	else
		write(1, "Error\nArguments invalides\n", 30);
  return (0);
}
