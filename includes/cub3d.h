/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:57 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/29 11:27:24 by kattimaijan      ###   ########.fr       */
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
# define MAX_WIDTH_IN_TILES 60
# define MAX_HEIGHT_IN_TILES 32
# define MOVE_SIZE 16
# define MOVE_SPEED 6
# define PI 3.14159265358979323846
# define FOV (60 * (PI / 180))
# define ROTATE_SPEED 0.4
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

# define DARK 0

typedef struct s_ray
{
    float	x;
	float	y;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
    float	angle;
	double	length;
	float	wall_height;
	// float	wall_x_hit;
	bool	direction_left;
	bool	direction_up;
	bool	horizontal;
} t_ray;

typedef struct s_player
{
	int				x;
	int				y;
    float 			angle;
	float			initial_direction;
	mlx_image_t		*player_img;
}	t_player;

typedef struct s_game
{
    char	**map;
	char	**file;
    char	*path_to_north_texture;
    char	*path_to_south_texture;
    char	*path_to_west_texture;
    char	*path_to_east_texture;
    int		floor_R;
	int		floor_G;
	int		floor_B;
	unsigned int		floor_RGB;
    int		ceiling_R;
	int		ceiling_G;
	int		ceiling_B;
	unsigned int		ceiling_RGB;
	bool	found_floor_rgb;
	bool	found_ceiling_rgb;
	float	starting_direction;
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
	struct s_player		player;
	int width_in_tiles;
	int height_in_tiles;
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
void	display_map(t_game *game);
// raycasting functions
//void 	init_ray(t_game *game);
void	raycasting(t_game *game);
void	determine_ray_direction(t_game *game);
void	reset_angles(t_game *game);
void	choose_shorter_distance(t_game *game, double h_inter, double v_inter);
// main loop
void	rendering(void *content);
bool	controls(t_game *game);
// checks
bool	is_wall(t_game *game, int x, int y);
bool	is_wall_float(t_game *game, float x, float y);
// drawing functions
void 	draw_line(t_game *game);
void 	clear_line(t_game *game);
void    render_ray_into_frame(t_game *game, int ray);
void    render_ray_into_frame_dark(t_game *game, int ray);
void	correct_distortion(t_game *game);
int		get_color(t_game *game);
bool	place_for_minimap(t_game* game, int y, int x);
uint32_t	get_pixel_color(t_game *game, int y);

void 	check_for_rgb(t_game *game, int i, int *j, int element);
void	copy_map(t_game *game, char **file);
void	validate_map(t_game *game);
void 	rgb_to_hex(t_game *game);

#endif