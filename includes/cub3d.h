/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:57 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/20 14:03:20 by eberkowi         ###   ########.fr       */
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
# define PI 3.1415926535
# define FOV 60
# define ROTATION_SPEED 4 // a random value for testing
# define WIDTH 1920 // can be changed
# define HEIGHT 1080 // can be changed
# define FLOOR_RGB 100
# define CEILING_RGB 101

typedef struct s_ray
{
    int x;
    int y;
    int angle; // += turn_direction * rotation_speed;
    //int rotation_speed; // already defined in header
    int turn_direction;
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
    float 			angle_radian; // = angle_degree * (PI / 180);
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
    int		ceiling_R;
	int		ceiling_G;
	int		ceiling_B;
	int		found_floor_rgb;
	int		found_ceiling_rgb;
	mlx_t				*mlx;
	mlx_texture_t		*wall_texture;
	mlx_image_t			*wall_img;
	mlx_texture_t		*floor_texture;
	mlx_image_t			*floor_img;
	mlx_texture_t		*player_texture;
	struct s_player		player;
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
void	controls(void *content);
void 	check_for_rgb(t_game *game, int i, int *j, int element);
void	copy_map(t_game *game, char **file);

#endif