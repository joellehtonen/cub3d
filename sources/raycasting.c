/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:03:55 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/22 11:51:01 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void determine_initial_player_direction(t_game *game)
{
	game->player.initial_direction = EAST; //for testing, determine later by the symbol on the map. also now points to east
	game->player.angle_radian = game->player.initial_direction;
	game->ray.direction_up = false;
	game->ray.direction_left = false;
	if (game->player.initial_direction == NORTH)
		game->ray.direction_up = true;
	else if (game->player.initial_direction == WEST)
		game->ray.direction_left = true;
}

void init_ray(t_game *game)
{
	determine_initial_player_direction(game);
	game->ray.angle = game->player.angle_radian - (FOV / 2);
	game->ray.y = 0;
	game->ray.x = 0;
	game->ray.distance = 0;
	// game->player.dx = 0;
	// game->player.dy = 0;
	
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
	if (fabs(tan(game->ray.angle)) < 0.00001)
		point_y = INFINITY;
	else
		point_y = (point_x - game->player.x) / tan(game->ray.angle) + game->player.y;
	calculate_vertical_step(game, &step_x, &step_y);
	//printf("vertical point_X is %f, point_Y %f\n", point_x / TILE_SIZE, point_y / TILE_SIZE);
	while (is_wall_float(game, point_x, point_y) == false)
	{
		//printf("vertical wall not found at x: %f, y: %f, stepping\n", point_x, point_y);
		point_x += step_x;
		point_y += step_y;
	}
	game->ray.vx = point_x;
	game->ray.vy = point_y;
	//printf("wall found. vertical intersection at x: %f, y: %f\n", point_x / TILE_SIZE, point_y / TILE_SIZE);
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
	if (fabs(tan(game->ray.angle)) < 0.00001)
		point_x = INFINITY;
	else
		point_x = (point_y - game->player.y) / tan(game->ray.angle) + game->player.x;
	calculate_horizontal_step(game, &step_x, &step_y);
	//printf("horizontal point_X is %f, point_Y %f\n", point_x / TILE_SIZE, point_y / TILE_SIZE);
	while (is_wall_float(game, point_x, point_y) == false)
	{
		//printf("horizontal wall not found at x: %f, y: %f, stepping\n", point_x, point_y);
		point_y += step_y;
		point_x += step_x;
	}
	game->ray.hx = point_x;
	game->ray.hy = point_y;
	//printf("wall found. horizontal intersection at x: %f, y: %f\n", point_x / TILE_SIZE, point_y / TILE_SIZE);
	distance = sqrt(pow(point_x - game->player.x, 2) + pow(point_y - game->player.y, 2));
	return (distance);
}

void raycasting(t_game *game)
{
	double	h_inter;
	double	v_inter;
	// int		ray;
	// int		degree;

	// game->ray.angle = game->player.angle_radian + (FOV / 2);
	// degree = game->ray.fov_radian / FOV;
	// ray = 0;
	// while (ray < FOV)
	// {
	// 	printf("RAY ANGLE = %f\n", game->ray.angle);
		h_inter = find_horizontal_intersection(game);
		v_inter = find_vertical_intersection(game);
		printf("h_inter is %f, v_inter is %f\n", h_inter, v_inter);
		choose_shorter_distance(game, h_inter, v_inter);
		// render_wall(game); // to do
		// render_ray(game); // for testing/minimap
		// printf("The ray hits wall in: %f\n", game->ray.distance); // CAN BE REMOVED LATER
		// game->ray.angle += degree;
		// ray++;
	// }
}
