/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:57 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/11 10:07:41 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define TILE_SIZE 8
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MINIMAP_WIDTH 256
# define MINIMAP_HEIGHT 128
# define MAX_WIDTH_IN_TILES 1000
# define MAX_HEIGHT_IN_TILES 1000
# define MOVE_SIZE 2
# define MOVE_SPEED 4
# define PI 3.14159265358979323846
# define FOV 1.0471975512 // (60 * (PI / 180))
# define ROTATE_SPEED 0.1
# define DEGREE 0.00054541539 // FOV / WINDOW_WIDTH;

# define FORWARD 0
# define RIGHT 1.57079632679 // (PI / 2)
# define BACK 3.14159265358979323846 // PI
# define LEFT 4.71238898038 // (3 * PI / 2)

# define NORTH 200
# define EAST 201
# define SOUTH 202
# define WEST 203

# define FLOOR_RGB 100
# define CEILING_RGB 101

# define DARK 0
# define SHRINK_RATE 0.05

# define FLAME_SIZE 500
# define FLAME_X 1160
# define FLAME_Y 600
# define ZIPPO_SIZE 700
# define ZIPPO_X 932
# define ZIPPO_Y 700
# define ZIPPO_MOVE_SPEED 6
# define ZIPPO_BOB_SPEED 8

typedef struct line
{
	int					x1;
	int					x2;
	int					y1;
	int					y2;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
	int					e2;
}	t_line;

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
	bool				horizontal_wall_hit;
	bool				horizontal_door_hit;
	bool				vertical_door_hit;
}	t_ray;

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
}	t_box;

typedef struct s_player
{
	float				x;
	float				y;
	float				angle;
	float				initial_direction;
}	t_player;

typedef struct s_minimap
{
	mlx_texture_t		*wall_texture;
	mlx_image_t			*wall_img;
	mlx_texture_t		*closed_door_texture;
	mlx_image_t			*closed_door_img;
	mlx_image_t			*open_door_img;
	mlx_texture_t		*floor_texture;
	mlx_image_t			*floor_img;
	mlx_texture_t		*player_texture;
	mlx_image_t			*player_img;
	mlx_texture_t		*empty_map_texture;
	mlx_image_t			*empty_map_img;
	mlx_image_t			*minimap_img;
	mlx_image_t			*blank_tile_img;
}	t_minimap;

typedef struct s_animation
{
	mlx_texture_t		*flame_t[12];
	mlx_image_t			*flame_img[12];
	mlx_image_t			*flame_mem_img;
	mlx_texture_t		*zippo_texture;
	mlx_image_t			*zippo_img;
	float				flame_x;
	float				flame_y;
	int					zippo_x;
	int					zippo_y;
	int					zippo_counter;
	int					frame_counter;
	double				new_flame_size_x;
	double				new_flame_size_y;
}	t_animation;

typedef struct s_game
{
	char				**map;
	char				**file;
	char				*path_to_north_texture;
	char				*path_to_south_texture;
	char				*path_to_west_texture;
	char				*path_to_east_texture;
	int					floor_r;
	int					floor_g;
	int					floor_b;
	unsigned int		floor_rgb;
	int					ceiling_r;
	int					ceiling_g;
	int					ceiling_b;
	unsigned int		ceiling_rgb;
	bool				found_floor_rgb;
	bool				found_ceiling_rgb;
	int					width_in_tiles;
	int					height_in_tiles;
	float				starting_direction;
	mlx_t				*mlx;
	mlx_image_t			*frame;
	mlx_texture_t		*north_texture;
	mlx_texture_t		*east_texture;
	mlx_texture_t		*south_texture;
	mlx_texture_t		*west_texture;
	mlx_texture_t		*door_texture;
	int32_t				mouse_x;
	bool				doors_closed;
	mlx_image_t			*door_warning;
	int					tile_size;
	int					frame_counter;
	int					frame_value;
	bool				show_minimap;
	struct s_player		player;
	struct s_ray		ray;
	struct s_minimap	minimap;
	struct s_animation	animation;
}	t_game;

// parsing functions
void			validate_filetype(char *filename);
void			create_copy_of_file(t_game *game, char *filename);
void			parse_file(t_game *game);
void			check_for_path(t_game *game, int i, int *j, char **path);
void			copy_map(t_game *game, char **file);
void			validate_map(t_game *game);
int				is_empty_space(char c);
void			get_paths_and_rgb(t_game *game, int *i);
int				check_for_all_paths(t_game *game);
// handling textures/images
void			resize_minimap(t_game *game);
void			create_textures(t_game *game);
void			create_images(t_game *game);
void			resize_images(t_game *game);
void			display_images(t_game *game);
// main loop
void			rendering(void *content);
bool			controls(t_game *game);
void			rotate_player(t_game *game, double direction);
// exit and free functions
void			error_exit(char *error);
void			error_exit_and_free(t_game *game, char *error);
void			error_exit_and_free_invalid_char(t_game *game, char *error, \
	char c);
void			free_all(t_game *game);
void			free_images(t_game *game);
void			free_textures(t_game *game);
// raycasting functions
void			raycasting(t_game *game);
void			determine_ray_direction(t_game *game);
void			reset_angles(t_game *game);
void			choose_shorter_distance(t_game *game, \
	double h_inter, double v_inter);
// checks
bool			is_wall(t_game *game, int x, int y);
bool			is_wall_ray(t_game *game, float x, float y, bool horizontal);
void			check_for_rgb(t_game *game, int i, int *j, int element);
void			check_for_valid_door(t_game *game, int x, int y);
// drawing functions
void			draw_line(t_game *game);
void			clear_line(t_game *game);
void			render_ray_into_frame(t_game *game, int ray);
void			render_ray_into_frame_dark(t_game *game, int ray);
void			draw_walls(t_game *game, int start, int end, int ray);
void			correct_distortion(t_game *game);
int				get_x_coordinate(t_game *game, mlx_texture_t *texture);
mlx_texture_t	*choose_texture(t_game *game);
void			extract_color_data(mlx_texture_t *texture, uint32_t *rgba, \
	unsigned int location);
void			extract_color_data_bw(mlx_texture_t *texture, \
	uint32_t *rgba, unsigned int location);
// animation functions
void			torch_animation(t_game *game);
void			disable_all_flames(t_game *game);
void			zippo_animation_recenter(t_game *game);
void			zippo_animation_rotate(t_game *game, double direction);
void			zippo_up_and_down(t_game *game);
// misc
void			open_close_doors(t_game *game);
void			set_up_space_bar(mlx_key_data_t key, void *data);
void			check_mouse_movement(t_game *game);

#endif