/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:03:55 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/18 12:06:24 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Pythagora's theorem: a^2 + b^2 = c^2
// We need to find the value of c, where c is the distance between two points A(a,0) and B(0,b) on a 2D plane. 
// The formula to find c is c = sqrt(a^2 + b^2). 

//soh = Sine = Opposite / Hypotenuse
//cah = Cosine = Adjacent / Hypotenuse
//toa = Tangent = Opposite / Adjacent

// h_inter = (game.ray->x/TILE_SIZE) * TILE_SIZE;
// x_inter = game.ray->x + (h_inter - game.ray->y) / tan(game.ray->rotation_angle);
// y_step = TILE_SIZE;
// x_step = TILE_SIZE / tan(game.ray->rotation_angle);
// c = sqrt(a^2 + b^2);

// isRayFacingDown  = rayAngle > 0 && rayAngle < pi [180];
// isRayFacingUp    = !isRayFacingDown;
// isRayFacingRight = rayAngle < (0.5 * pi) [90] || rayAngle > (1.5 * pi) [270];
// isRayFacingLeft  = !isRayFacingRight;

static void determine_initial_player_direction(t_game *game)
{
	game->player.initial_direction = FORWARD; //for testing, determine later by the symbol on the map
	game->player.angle_radian = game->player.initial_direction;
	game->ray.direction_up = false;
	game->ray.direction_left = false;
	if (game->player.initial_direction == FORWARD)
		game->ray.direction_up = true;
	else if (game->player.initial_direction == LEFT)
		game->ray.direction_left = true;
}

void init_ray(t_game *game)
{
	determine_initial_player_direction(game);
	game->ray.angle = game->player.angle_radian - (FOV / 2);
	if (game->ray.angle < 0)
		game->ray.angle += 2 * PI;
	game->ray.y = (game->player.y / TILE_SIZE) * TILE_SIZE;
	game->ray.x = game->player.x + (game->ray.y - game->player.y) / tan(game->ray.angle);
	game->ray.distance = 0;
	game->player.dx = 0;
	game->player.dy = 0;
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
	point_y = (point_x - game->player.x) / tan(game->player.angle_radian) + game->player.y; // or -tan?
	step_x = TILE_SIZE;
	step_y = step_x / tan(game->player.angle_radian);
	while (is_wall_float(game, point_x, point_y) == false)
	{
		if (game->ray.direction_left == true)
			point_x -= step_x;
		else
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
	point_x = (point_y - game->player.y) / tan(game->player.angle_radian) + game->player.x; // or -tan?
	step_y = TILE_SIZE;
	step_x = step_y / tan(game->player.angle_radian);
	while (is_wall_float(game, point_x, point_y) == false)
	{
		if (game->ray.direction_up == true)
			point_y -= step_y;
		else
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
	// int		ray;

	// ray = 0;
	// while (ray <= 60)
	// {
		h_inter = find_horizontal_intersection(game);
		v_inter = find_vertical_intersection(game);
		choose_shorter_distance(game, h_inter, v_inter);
		// render_wall(game); // to do
		// render_ray(game); // for testing/minimap
		//printf("The ray hits wall in: %f\n", game->ray.distance); // CAN BE REMOVED LATER
	// 	ray++;
	// }
}
