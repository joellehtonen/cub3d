/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:57 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/21 11:38:05 by jlehtone         ###   ########.fr       */
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

# define TILE_SIZE 64
# define MOVE_SIZE 14
# define MOVE_SPEED 4
# define PI 3.14159265358979323846
# define FOV (60 * (PI / 180))
# define ROTATE_SPEED 0.01 // a random value for testing
# define MAP_WIDTH 1920 // can be changed
# define MAP_HEIGHT 1080 // can be changed

# define FORWARD 0
# define RIGHT (PI / 2)
# define BACK PI
# define LEFT (3 * PI / 2)

typedef struct s_ray
{
    double	x;
	double	y;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
    double	angle;
	double	fov_radian;	
	double	distance;
	bool	direction_left;
	bool	direction_up;
} t_ray;

typedef struct s_box
{	
	int	x;
	int	y;
	int	width;
	int	height;
}	t_box;

typedef struct s_player
{
	int				x;
	int				y;
	int 			dx;
    int 			dy;
    double 			angle_degree;
    float 			angle_radian;
	int				initial_direction;
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
    int		*floor_rgb;
    int		*ceiling_rgb;
	mlx_t				*mlx;
	mlx_texture_t		*wall_texture;
	mlx_image_t			*wall_img;
	mlx_texture_t		*floor_texture;
	mlx_image_t			*floor_img;
	mlx_texture_t		*player_texture;
	mlx_image_t			*minimap_img;
	struct s_player		player;
	struct s_ray		ray;
	int width;
	int height;
	int image_size;
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
bool	controls(t_game *game);
void 	draw_line(t_game *game);
// raycasting functions
void	raycasting(t_game *game);
void	init_ray(t_game *game);
void	determine_ray_direction(t_game *game);
void	reset_ray_angle(t_game *game);
void	calculate_horizontal_step(t_game *game, float *x_step, float *y_step);
void	calculate_vertical_step(t_game *game, float *x_step, float *y_step);
void	choose_shorter_distance(t_game *game, double h_inter, double v_inter);
// main loops
void	rendering(void *content);
// checks
bool	is_wall(t_game *game, int x, int y);
bool	is_wall_float(t_game *game, float x, float y);


#endif