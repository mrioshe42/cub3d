NAME = cub3d

NAME_B = cub3d_bonus

CC = cc

FLAGS = -Wall -Wextra -Werror -g

MLXFLAGS = -L ./minilibx-linux -lmlx_Linux -lXext -lX11 -lm

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft

MINILIBX_PATH = minilibx-linux

MINILIBX = $(MINILIBX_PATH)/libmlx.a

SRC = ./main/main.c ./main/inputs.c ./main/check_args.c \
		./main/exit.c ./main/read_map.c \
		./main/textures.c ./main/erorrs.c \
		./main/cub3d.c ./main/on_keypress.c \
		./render/raycasting.c ./render/render.c ./render/load_img.c \
		./player/player_position.c ./player/door.c \
		./player/player_rotate.c ./player/player_move.c \
		./utils/init.c ./utils/cub3d_utils.c ./utils/init_struct.c \
		./enemy/enemy.c ./enemy/enemy_utils.c ./main/init_utils.c \
		./main/initial_utils.c ./utils/get_next_line.c ./render/render_utils.c

OBJS_DIR = ./objects
OBJ = $(SRC:%.c=$(OBJS_DIR)/%.o)

all: ${NAME}

${NAME}: $(OBJ)
	$(MAKE) -C $(MINILIBX_PATH)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(FLAGS) -lm $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	
bonus: $(OBJ)
	$(MAKE) -C $(MINILIBX_PATH)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(FLAGS) -lm $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME_B)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)/$(dir $<)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx-linux
	@rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	@rm -rf $(NAME) $(OBJS_DIR) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus
