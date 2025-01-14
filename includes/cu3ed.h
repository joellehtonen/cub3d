/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu3ed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:57 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/14 14:48:59 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CU3ED_H
# define CU3ED_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define PI 3.1415926535
# define FOV 60
# define TILE_SIZE 64
# define MOVEMENT_SPEED 4
# define ROTATION_SPEED 4 // a random value for testing
# define WIDTH 1920 // can be changed
# define HEIGHT 1080 // can be changed

typedef struct s_player
{
    int x;
    int y;
    int dx;
    int dy;
    double angle_degree;
    float angle_radian // = angle_degree * (PI / 180);
} t_player;

typedef struct s_ray
{
    int x;
    int y;
    int angle; // += turn_direction * rotation_speed;
    //int rotation_speed; // already defined in header
    int turn_direction;
} t_ray;

typedef struct s_game
{
    t_ray       ray;
    t_player    player;
    char	**map;
	char	**file;
    char	*path_to_north_texture;
    char	*path_to_south_texture;
    char	*path_to_west_texture;
    char	*path_to_east_texture;
    int		*floor_rgb;
    int		*ceiling_rgb;
} t_game;

void	error_exit(char *error);
void	error_exit_and_free(t_game *game, char *error);
void	validate_filetype(char *filename);
void	create_copy_of_file(t_game *game, char *filename);
void    parse_file(t_game *game);
void	free_all(t_game *game);
void	check_for_path(t_game *game, int i, int *j, char **path);

#endif