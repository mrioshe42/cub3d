/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:26:15 by tpapatza          #+#    #+#             */
/*   Updated: 2024/11/12 17:24:48 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <ctype.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
//# define WIN_W 640
//# define WIN_H 480
# define WIN_W 720
# define WIN_H 480
//# define WIN_W 1280
//# define WIN_H 720
# define FOV 0.785398163
# define PLAYER_SPEED 0.08
# define ROTATE_SPEED 0.025

# define MAP_WALL 0x0000FF
# define MAP_FLOOR 0xFFFFFF
# define MAP_DOOR 0x40E0D0
# define MAP_PLAYER 0x00FF00
# define MAP_OUTSIDE 0x000000
# define MAP_FOE 0x00FF0000
# define MAP_EXIT 0xFFA500

# define DOOR_CLOSED 'D'
# define DOOR_OPEN 'O'

typedef enum s_directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NUM_DIRECTIONS
}	t_directions;

typedef struct s_foe
{
	int		x;
	int		y;
	void	*img_ptr;
}	t_foe;

typedef struct s_obj
{
	double	x;
	double	y;
	double	dist;
	double	obj_dir_x;
	double	obj_dir_y;
	double	obj_x;
	int		draw_s;
	int		draw_e;
	int		width;
	int		height;
	int		side;
}	t_obj;

typedef struct s_ray
{
	double	perp_wall_dist;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
	double	wall_x;
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
	int		hit_obj;
	t_obj	obj;
}	t_ray;

typedef struct s_map
{
	char	**map;
	char	**tmp;
	int		height;
	int		width;
}	t_map;

typedef struct s_player
{
	double	pos_x; // Player's position x axis
	double	pos_y; // Player's position y axis
	double	dir_x; // Player's direction vector x axis
	double	dir_y; // Player's direction vector y axis
	double	plane_x; // Camera plane (perpendicular to the direction) x axis
	double	plane_y; // Camera plane (perpendicular to the direction) y axis
	double	angle; // Player's rotation angle
	char	p_dir;
	int		move_b_f; // Movement direction backward/forward
	int		move_l_r; // Movement direction left/right
	int		rotate; // Rotation direction
}	t_player;

typedef struct s_paths
{
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	char	*f_path;
	char	*c_path;
}	t_paths;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		b_p_p;
	int		size_line;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_imgs
{
	t_img	img_no;
	t_img	img_so;
	t_img	img_ea;
	t_img	img_we;
	t_img	img_door_c;
	t_img	img_door_o;
	t_img	img_exit;
	int		f_color;
	int		c_color;
}	t_imgs;

typedef struct s_torch
{
	t_img			img;
	int				num;
	int				pos_x;
	int				pos_y;
	int				win_w;
	int				win_h;
	struct s_torch	*next;
}	t_torch;

typedef struct s_enemy
{
	t_img			img;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_paths		paths;
	t_player	player;
	t_img		img;
	t_imgs		imgs;
	t_ray		ray;
	t_map		mapinfo;
	t_torch		torches[32];
	t_enemy		enemies[35];
	t_foe		*foes;
	pthread_t	enemy_thread;
	int			n_foes;
	double		mm_m;
	double		mm_d;
	int			x_exit;
	int			y_exit;
	int			thread_active;
}	t_game;

void			init_ray(t_ray *ray);
void			init_mapinfo(t_game *game);
void			init_imgs(t_game *game);
void			init_torch(t_torch *torch);
void			init_game(t_game *game);
int				on_d(t_game *game);
int				on_keypress(int keysym, t_game *game);
int				on_keyrelease(int keysym, t_game *game);
int				on_mm(int x, int y, t_game *game);
int				player_rotate(t_game *game, double rotdir);
void			player_move(t_game *game);
int				check_position(t_game *game);
void			mini_map(t_game *game, int x, int y);
void			draw_vertical_line(t_game *game, t_ray *ray, int x);
void			raycasting(t_game *game);
int				main_loop(t_game *game);
void			open_door(t_game *game, double dir_x, double dir_y, char *tile);
void			load_textures(t_game *game);
void			free_map(t_game *game);
void			exit_error(t_game *game, char *msg, int nbr);
void			init_enemy(t_game *game);
void			*update_ep(void *arg);
void			display_intro(t_game *game);
void			check_exit(t_game *game);
void			free_texture_paths(t_game *game);
void			init_map_and_enemies(t_game *game);
void			init_minimap(t_game *game);
char			*get_next_line(int fd);
void			init_torches(t_torch *torches, int num_torches);
void			end_thread(t_game *game);
void			free_colors(char **colors);
void			calculate_initial_step_and_side_distances(t_game *game,
					t_ray *ray);
void			set_color(double d_factor, int *color);
void			init_player(t_game *game);
t_directions	get_random_direction(void);
void			calculate_next_position(int *next_x, int *next_y,
					t_directions dir);

#endif
