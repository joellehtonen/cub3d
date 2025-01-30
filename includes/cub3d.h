/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:57 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/30 16:51:20 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef cub3d_H
# define cub3d_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define TILE_SIZE 32
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MINIMAP_WIDTH 533
# define MINIMAP_HEIGHT 300
# define MAX_WIDTH_IN_TILES 120
# define MAX_HEIGHT_IN_TILES 64
# define MOVE_SIZE 2
# define MOVE_SPEED 4
# define PI 3.14159265358979323846
# define FOV (60 * (PI / 180))
# define ROTATE_SPEED 0.2
# define DEGREE FOV / WINDOW_WIDTH;

# define FORWARD 0
# define RIGHT (PI / 2)
# define BACK PI
# define LEFT (3 * PI / 2)

# define NORTH 200
# define EAST 201
# define SOUTH 202
# define WEST 203

# define FLOOR_RGB 100
# define CEILING_RGB 101

# define DARK 1

# define FLAME_SIZE 500
# define FLAME_X 1160
# define FLAME_Y 600
# define ZIPPO_SIZE 700
# define ZIPPO_X FLAME_X - 228
# define ZIPPO_Y FLAME_Y + 100
# define ZIPPO_MOVE_SPD 6
# define ZIPPO_BOB_SPD 8

typedef struct s_ray
{
    float				x;
	float				y;
	float				hx;
	float				hy;
	float				vx;
	float				vy;
    float				angle;
	double				length;
	float				wall_height;
	bool				direction_left;
	bool				direction_up;
	bool				horizontal;
} t_ray;

typedef struct s_box
{
	float				top_left_x;
	float				top_left_y;
	float				top_right_x;
	float				top_right_y;
	float				bottom_left_x;
	float				bottom_left_y;
	float				bottom_right_x;
	float				bottom_right_y;
} t_box;

typedef struct s_player
{
	float				x;
	float				y;
    float 				angle;
	float				initial_direction;
	mlx_image_t			*player_img;
}	t_player;

typedef struct s_game
{
    char				**map;
	char				**file;
    char				*path_to_north_texture;
    char				*path_to_south_texture;
    char				*path_to_west_texture;
    char				*path_to_east_texture;
    int					floor_R;
	int					floor_G;
	int					floor_B;
	unsigned int		floor_RGB;
    int					ceiling_R;
	int					ceiling_G;
	int					ceiling_B;
	unsigned int		ceiling_RGB;
	bool				found_floor_rgb;
	bool				found_ceiling_rgb;
	int 				width_in_tiles;
	int 				height_in_tiles;
	float				starting_direction;
	mlx_t				*mlx;
	mlx_image_t			*frame;
	mlx_texture_t		*north_texture;
	mlx_texture_t		*east_texture;
	mlx_texture_t		*south_texture;
	mlx_texture_t		*west_texture;
	mlx_texture_t		*wall_texture;
	mlx_image_t			*minimap_wall_img;
	mlx_texture_t		*floor_texture;
	mlx_image_t			*minimap_floor_img;
	mlx_texture_t		*player_texture;
	mlx_image_t			*minimap_img;
	mlx_texture_t		*flame_texture[12];
	mlx_image_t			*flame_img[12];
	mlx_image_t			*flame_mem_img;
	mlx_texture_t		*zippo_texture;
	mlx_image_t			*zippo_img;
	int					flame_x;
	int					flame_y;
	int					zippo_x;
	int					zippo_y;
	int					frame_counter;
	int					zippo_counter;
	struct s_player		player;
	struct s_ray		ray;
} t_game;

void	error_exit(char *error);
void	error_exit_and_free(t_game *game, char *error);
void	validate_filetype(char *filename);
void	create_copy_of_file(t_game *game, char *filename);
void    parse_file(t_game *game);
void	free_all(t_game *game);
void	check_for_path(t_game *game, int i, int *j, char **path);
void	create_textures(t_game *game);
void	create_images(t_game *game);
void	resize_images(t_game *game);
void	display_images(t_game *game);
// raycasting functions
void	raycasting(t_game *game);
void	determine_ray_direction(t_game *game);
void	reset_angles(t_game *game);
void	choose_shorter_distance(t_game *game, double h_inter, double v_inter);
// main loop
void	rendering(void *content);
bool	controls(t_game *game);
// checks
bool	is_wall(t_game *game, int x, int y);
bool	is_wall_ray(t_game *game, float x, float y);
// drawing functions
void 	draw_line(t_game *game);
void 	clear_line(t_game *game);
void    render_ray_into_frame(t_game *game, int ray);
void    render_ray_into_frame_dark(t_game *game, int ray);
void	correct_distortion(t_game *game);
int		get_color(t_game *game);
int		get_x_coordinate(t_game *game, mlx_texture_t *texture);
mlx_texture_t	*choose_texture(t_game *game);
uint32_t		extract_color_data(mlx_texture_t *texture, uint32_t *rgba, unsigned int location);

void 	check_for_rgb(t_game *game, int i, int *j, int element);
void	copy_map(t_game *game, char **file);
void	validate_map(t_game *game);
void	torch_animation(t_game *game);
void 	disable_all_flames(t_game *game);

#endif