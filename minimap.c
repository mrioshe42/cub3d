#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MINIMAP_SIZE 10
#define COLOR_MAP_WALL 0x333333
#define COLOR_MAP_SPRITE 0x999999
#define COLOR_MAP_FLOOR 0xFFFFFF
#define COLOR_MAP_DOOR 0xFF9900
#define COLOR_MAP_PLAYER 0x00FF00
#define COLOR_MAP_OUTSIDE 0x000000

typedef struct s_env {
    char **map;
    int map_width;
    int map_height;
    int width;
    int height;
    int player_x;
    int player_y;
    // Other environment details like image or window pointer here
} t_env;

// Drawing pixel in the image (placeholder function)
void ft_put_pixel(void *img, int color, int x, int y) {
    // Implementation to draw a pixel to the window/image
}

// Draws a square at position (x, y) of a given color
void draw_square(t_env env, int x, int y, int color) {
    int i, j;
    int width = MINIMAP_SIZE;
    int height = MINIMAP_SIZE;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            ft_put_pixel(env.img, color, x + j, y + i);
        }
    }
}

// Determines the color of the minimap element based on the map character
int get_color_minimap(t_env env, int i, int j) {
    if (i < 0 || j < 0 || i >= env.map_height || j >= env.map_width)
        return COLOR_MAP_OUTSIDE;

    char tile = env.map[i][j];
    if (tile == '1') return COLOR_MAP_WALL;
    if (tile == '2' || tile == '3') return COLOR_MAP_SPRITE;
    if (tile == '0' || tile == 'N' || tile == 'S' || tile == 'E' || tile == 'W') return COLOR_MAP_FLOOR;
    if (tile == 'D') return COLOR_MAP_DOOR;
    // Add more map element conditions as needed
    return COLOR_MAP_OUTSIDE;
}

// Function to draw the minimap in a spiral from the player's position
void draw_spiral_minimap(t_env env, int max_elements) {
    int player_x = env.player_x;
    int player_y = env.player_y;
    int x = 0, y = 0; // Spiral coordinates (relative to player)
    int dx = 0, dy = -1;
    int radius = 1;
    int count = 0;

    int center_x = player_x * MINIMAP_SIZE;
    int center_y = player_y * MINIMAP_SIZE;
    
    for (int n = 0; n < max_elements; n++) {
        int map_x = player_x + x;
        int map_y = player_y + y;

        // Get the color of the current map element (or black if outside)
        int color = get_color_minimap(env, map_x, map_y);
        
        // Draw a square at the computed position (offset by the player's position)
        draw_square(env, center_x + x * MINIMAP_SIZE, center_y + y * MINIMAP_SIZE, color);

        // Spiral algorithm logic: Change direction when necessary
        if (x == y || (x < 0 && x == -y) || (x > 0 && x == 1 - y)) {
            int temp = dx;
            dx = -dy;
            dy = temp;
        }

        // Move to the next element in the spiral
        x += dx;
        y += dy;
        count++;

        // Stop if we have drawn the maximum number of elements
        if (count >= max_elements) break;
    }

    // Draw the player in the center
    draw_square(env, center_x, center_y, COLOR_MAP_PLAYER);
}

#define DOOR_CLOSED '8'
#define DOOR_LOCKED '9'
#define DOOR_OPEN '7'
#define TILE_SIZE 32
#define STEP_SIZE 16

void play_door_sound(t_game *game)
{
	if (game->sounds->sound)
		system("afplay music/wind.mp3 &");
}

bool is_door(char tile)
{
	return tile == DOOR_CLOSED || tile == DOOR_LOCKED || tile == DOOR_OPEN;
}

void toggle_door(t_game *game, int x, int y)
{
	char *tile = &game->map->big_map[y][x];

	if (*tile == DOOR_CLOSED || *tile == DOOR_LOCKED)
	{
		*tile = DOOR_OPEN;
		play_door_sound(game);
	}
	else if (*tile == DOOR_OPEN)
	{
		*tile = DOOR_CLOSED;
		play_door_sound(game);
	}
}

void open_door(t_game *game, int dirX, int dirY)
{
	float playerX = game->map->player[0];
	float playerY = game->map->player[1];
	int next_x = (playerX + dirX * STEP_SIZE) / TILE_SIZE;
	int next_y = (playerY + dirY * STEP_SIZE) / TILE_SIZE;

	// Check if the calculated position is within bounds
	if (next_x >= 0 && next_x < game->map->x && next_y >= 0 && next_y < game->map->y)
	{
		char tile = game->map->big_map[next_y][next_x];
		if (is_door(tile))
			toggle_door(game, next_x, next_y);
	}
}
