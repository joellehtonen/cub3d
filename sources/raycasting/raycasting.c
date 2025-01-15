/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:03:55 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/15 18:51:08 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void init_ray(t_game *game)
{
	// maybe not necessary to count degrees first
	// if supposed to face North = 0, if South = 180, East = 90, West = 270. Assume North for now.
	game->player.angle_degree = 0;
	//game->player.angle_radian = game->player.angle_degree * (PI / 180); //determine this when needed, maybe within a func instead of within struct
	game->ray.angle = game->player.angle_degree - (FOV / 2);
	if (game->ray.angle < 0)
		game->ray.angle += 360;
	game->ray.y = (game->player.y / TILE_SIZE) * TILE_SIZE;
	game->ray.x = game->player.x + (game->ray.y - game->player.y) / tan(game->ray.angle);
	game->ray.distance = 0;
	game->player.dx = 0;
	game->player.dy = 0;
	// game->player.dx = cos(game->player.angle_radian);
	// game->player.dy = sin(game->player.angle_radian);
	// these are determined based on the starting direction, maybe create a func later for it
	game->ray.ray_points_left = false; //or true if points straight up???
	game->ray.ray_points_up = true;
}

static void	choose_shorter_distance(t_game *game, double h_inter, double v_inter)
{
	if (h_inter <= v_inter)
		game->ray.distance = h_inter;
	else
		game->ray.distance = v_inter;
}

static double find_horizontal_intersection(t_game *game)
{
	float	x;
	float	y;
	float	x_step;
	float	y_step;

	// r
	if (game->ray.ray_points_up)
		

	// ray
}

void raycasting(t_game *game)
{
	double	h_inter; //horizontal intersection of the ray
	double	v_inter; //vertical intersection of the ray
	int		ray;

	ray = 0; //first ray, last one will be 60
	while (ray <= 60)
	{
		h_inter = find_horizontal_intersection(game);
		v_inter = find_vertical_intersection(game);
		choose_shorter_distance(game, h_inter, v_inter);
		ray++;
	}
}
