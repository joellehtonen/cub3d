/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:03:55 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/23 11:48:14 by kattimaijan      ###   ########.fr       */
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
	{
		game->ray.direction_up = true;
		game->ray.direction_left = true;
	}
	else if (game->player.initial_direction == WEST)
	{
		game->ray.direction_up = false;
		game->ray.direction_left = true;
	}
	else if (game->player.initial_direction == SOUTH)
	{
		game->ray.direction_up = false;
		game->ray.direction_left = false;
	}
	else if (game->player.initial_direction == EAST)
	{
		game->ray.direction_up = true;
		game->ray.direction_left = false;
	}
}

void init_ray(t_game *game)
{
	determine_initial_player_direction(game);
	game->ray.y = 0;
	game->ray.x = 0;
	game->ray.distance = 0;
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
	// if (fabs(tan(game->ray.angle)) < 0.00001)
	// 	point_y = INFINITY;
	point_y = game->player.y + (point_x - game->player.x) * tan(game->ray.angle);
	calculate_vertical_step(game, &step_x, &step_y);
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
	// if (fabs(tan(game->ray.angle)) < 0.00001)
	// 	point_x = INFINITY;
	// else
	point_x = game->player.x + (point_y - game->player.y) / tan(game->ray.angle);

	// printf("\nhorizontal point_X is %f, point_Y %f\n", point_x, point_y);
	// printf("player x pos = %f, player y pos = %f\n", game->player.x, game->player.y);
	// printf("tan value is %f\n", tan(game->ray.angle));
	// printf("point y - player y = %f...\n", (point_y - game->player.y));
	// printf("... divided by tan(angle) === %f\n", ((point_y - game->player.y) / tan(game->ray.angle)));
	calculate_horizontal_step(game, &step_x, &step_y);
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
	int		ray;
	double	degree;

	degree = FOV / 60;
	//printf("degree = %f\n", degree);
	game->ray.angle = game->player.angle_radian - (FOV / 2);
	ray = 0;
	while (ray < 60)
	{
		h_inter = find_horizontal_intersection(game);
		v_inter = find_vertical_intersection(game);
		//printf("h_inter is %f, v_inter is %f\n", h_inter, v_inter);
		choose_shorter_distance(game, h_inter, v_inter);
		draw_line(game);
		// render_wall(game); // to do
		game->ray.angle += degree;
		//printf("ray angle = %f\n", game->ray.angle);
		ray++;
		//printf("ray = %d\n", ray);
	}
}
