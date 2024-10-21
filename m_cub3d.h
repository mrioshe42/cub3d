/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:12:27 by mrios-he          #+#    #+#             */
/*   Updated: 2024/10/21 18:15:12 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_CUB3D_H
# define M_CUB3D_H

#include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>

# define ROTATE_LEFT 0xff51
# define ROTATE_RIGHT 0xff53
# define ROTATE_UP 0xff52
# define ROTATE_DOWN 0xff54
# define FORWARD_W_Z 0x0077
# define BACK_S_S 0x0073
# define RIGHT_D_D 0x0064
# define LEFT_A_Q 0x0061
# define JUMP_SPACE 0x0020
# define ESC 0xff1b
# define BUFFER_SIZE 42

#define ELEM "01NSEW "

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
} t_keybinds;


typedef struct s_paths {
	char *no_path;
	char *so_path;
	char *ea_path;
	char *we_path;
	char *f_path;
	char *c_path;
} t_paths;

typedef struct s_game {
	void	*mlx;
	void	*win;
	char    **map;
	char    **tmp;
	char    p_dir;
	float	fov_rd;
	double	angle;
	int     p_x;
	int     pp_x;
	int     p_y;
	int     pp_y;
	char		**f_c;
	int			wrongcharmap;
	t_keybinds	keybinds;
	t_paths	paths;
} t_game;


#endif