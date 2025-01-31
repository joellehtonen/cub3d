/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:03:55 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/31 15:13:46 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

/*
	@brief Calculates how large a vertical "step" the ray needs to take,
	 and to which direction in order to find 
	 the next intersection to check.
	@param *game Our game struct
	@param *step_x Reference to the value of step in x-axis
	@param *step_y Reference to the value of step in y-axis
*/
static void	calculate_vertical_step(t_game *game, float *step_x, float *step_y)
{
	*step_x = game->tile_size;
	if (game->ray.direction_left == true)
		*step_x *= -1;
	*step_y = *step_x * tan(game->ray.angle);
	if ((game->ray.direction_up == true && *step_y > 0)
		|| (game->ray.direction_up == false && *step_y < 0))
	{
		*step_y *= -1;
	}
}

/*
	@brief Calculates how large a horizontal "step" the ray needs to take,
	 and to which direction in order to find the next intersection to check.
	@param *game Our game struct
	@param *step_x Reference to the value of step in x-axis
	@param *step_y Reference to the value of step in y-axis
*/
static void	calculate_horizontal_step(t_game *game, \
	float *step_x, float *step_y)
{
	*step_y = game->tile_size;
	if (game->ray.direction_up == true)
		*step_y *= -1;
	*step_x = *step_y / tan(game->ray.angle);
	if ((game->ray.direction_left == true && *step_x > 0)
		|| (game->ray.direction_left == false && *step_x < 0))
	{
		*step_x *= -1;
	}
}

/*
	@brief Finds and records the first place where 
	 the ray hits a vertical wall.
	@param *game Our game struct
	@return The distance from the player to the hit location
*/
static double	find_vertical_intersection(t_game *game)
{
	float	point_x;
	float	point_y;
	float	step_x;
	float	step_y;
	double	distance;

	point_x = floor(game->player.x / game->tile_size) * game->tile_size;
	if (game->ray.direction_left == false)
		point_x += game->tile_size;
	point_y = game->player.y + (point_x - game->player.x) \
		* tan(game->ray.angle);
	calculate_vertical_step(game, &step_x, &step_y);
	while (is_wall_ray(game, point_x, point_y, false) == false)
	{
		point_x += step_x;
		point_y += step_y;
	}
	game->ray.vx = point_x;
	game->ray.vy = point_y;
	distance = sqrt(pow(point_x - game->player.x, 2) \
		+ pow(point_y - game->player.y, 2));
	return (distance);
}
/*
	@brief Finds and records the first place where 
	 the ray hits a horizontal wall.
	@param *game Our game struct
	@return The distance from the player to the hit location
*/
static double	find_horizontal_intersection(t_game *game)
{
	float	point_x;
	float	point_y;
	float	step_x;
	float	step_y;
	double	distance;

	point_y = floor(game->player.y / game->tile_size) * game->tile_size;
	if (game->ray.direction_up == false)
		point_y += game->tile_size;
	point_x = game->player.x + (point_y - game->player.y) \
		/ tan(game->ray.angle);
	calculate_horizontal_step(game, &step_x, &step_y);
	while (is_wall_ray(game, point_x, point_y, true) == false)
	{
		point_y += step_y;
		point_x += step_x;
	}
	game->ray.hx = point_x;
	game->ray.hy = point_y;
	distance = sqrt(pow(point_x - game->player.x, 2) \
		+ pow(point_y - game->player.y, 2));
	return (distance);
}

/*
	@brief Shoots a ray into all directions the player can see.
	 We record the location where it hits a wall 
	 and render objects accordingly. 
	@param *game Our game struct
*/
void	raycasting(t_game *game)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	game->ray.angle = game->player.angle - (FOV / 2);
	ray = 0;
	while (ray < WINDOW_WIDTH)
	{
		game->ray.horizontal_door_hit = false;
		game->ray.vertical_door_hit = false;
		reset_angles(game);
		determine_ray_direction(game);
		h_inter = find_horizontal_intersection(game);
		v_inter = find_vertical_intersection(game);
		choose_shorter_distance(game, h_inter, v_inter);
		if (DARK == 0)
			render_ray_into_frame(game, ray);
		else
			render_ray_into_frame_dark(game, ray);
		draw_line(game);
		game->ray.angle += DEGREE;
		ray++;
	}
}

