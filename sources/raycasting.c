/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:03:55 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/27 11:22:42 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	calculate_vertical_step(t_game *game, float *step_x, float *step_y)
{
	*step_x = TILE_SIZE;
	if (game->ray.direction_left == true)
		*step_x *= -1;
	*step_y = *step_x * tan(game->ray.angle);
	if ((game->ray.direction_up == true && *step_y > 0)
		|| (game->ray.direction_up == false && *step_y < 0))
	{
		*step_y *= -1;
	}
}

static void	calculate_horizontal_step(t_game *game, float *step_x, float *step_y)
{
	*step_y = TILE_SIZE;
	if (game->ray.direction_up == true)
		*step_y *= -1;
	*step_x = *step_y / tan(game->ray.angle);
	if ((game->ray.direction_left == true && *step_x > 0)
		|| (game->ray.direction_left == false && *step_x < 0))
	{
		*step_x *= -1;
	}
}

static double find_vertical_intersection(t_game *game)
{
	float	point_x;
	float	point_y;
	float	step_x;
	float	step_y;
	double	distance;

	point_x = floor(game->player.x / TILE_SIZE) * TILE_SIZE;
	if (game->ray.direction_left == false)
		point_x += TILE_SIZE;
	point_y = game->player.y + (point_x - game->player.x) * tan(game->ray.angle);
	calculate_vertical_step(game, &step_x, &step_y);
	while (is_wall_float(game, point_x, point_y) == false)
	{
		point_x += step_x;
		point_y += step_y;
	}
	game->ray.vx = point_x;
	game->ray.vy = point_y;
	distance = sqrt(pow(point_x - game->player.x, 2) + pow(point_y - game->player.y, 2));
	return (distance);
}

static double find_horizontal_intersection(t_game *game)
{
	float	point_x;
	float	point_y;
	float	step_x;
	float	step_y;
	double	distance;

	point_y = floor(game->player.y / TILE_SIZE) * TILE_SIZE;
	if (game->ray.direction_up == false)
		point_y += TILE_SIZE;
	point_x = game->player.x + (point_y - game->player.y) / tan(game->ray.angle);
	calculate_horizontal_step(game, &step_x, &step_y);
	while (is_wall_float(game, point_x, point_y) == false)
	{
		point_y += step_y;
		point_x += step_x;
	}
	game->ray.hx = point_x;
	game->ray.hy = point_y;
	distance = sqrt(pow(point_x - game->player.x, 2) + pow(point_y - game->player.y, 2));
	return (distance);
}

void raycasting(t_game *game)
{
	double	h_inter;
	double	v_inter;
	int		ray;
	float	degree;

	degree = FOV / WINDOW_WIDTH;
	game->ray.angle = game->player.angle - (FOV / 2);
	//clear_frame(game);
	ray = 0;
	while (ray < WINDOW_WIDTH)
	{
		reset_angles(game);
		determine_ray_direction(game);
		h_inter = find_horizontal_intersection(game);
		v_inter = find_vertical_intersection(game);
		choose_shorter_distance(game, h_inter, v_inter);
		render_ray_into_frame(game, ray);
		draw_line(game);
		game->ray.angle += degree;
		ray++;
	}
	mlx_image_to_window(game->mlx, game->frame, 0, 0);
	mlx_set_instance_depth(&game->frame->instances[0], 0);
}
