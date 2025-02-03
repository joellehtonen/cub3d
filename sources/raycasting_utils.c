/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:08:49 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/03 16:55:12 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	@brief Resets the angles in case they exceed 360
	 or get lower than 0.
	@param *game Our game struct
*/
void	reset_angles(t_game *game)
{
	if (game->ray.angle < 0)
		game->ray.angle += 2 * PI;
	if (game->ray.angle > 2 * PI)
		game->ray.angle -= 2 * PI;
	if (game->player.angle < 0)
		game->player.angle += 2 * PI;
	if (game->player.angle > 2 * PI)
		game->player.angle -= 2 * PI;
}

/*
	@brief Determines which way the ray is pointing.
	@param *game Our game struct
*/
void	determine_ray_direction(t_game *game)
{
	if (game->ray.angle >= PI && game->ray.angle <= PI * 2)
		game->ray.direction_up = true;
	else
		game->ray.direction_up = false;
	if (game->ray.angle >= PI / 2 && game->ray.angle <= 3 * (PI / 2))
		game->ray.direction_left = true;
	else
		game->ray.direction_left = false;
	return ;
}

/*
	@brief Chooses the shorter distance between two intersections
	 where the ray hit the wall. 
	@param *game Our game struct
	@param h_inter The distance to the horizontal intersection
	@param v_inter The distance to the vertical intersection
*/
void	choose_shorter_distance(t_game *game, double h_inter, double v_inter)
{
	if (h_inter <= v_inter)
	{
		game->ray.length = h_inter;
		game->ray.x = game->ray.hx;
		game->ray.y = game->ray.hy;
		game->ray.horizontal = true;
		if (game->ray.vertical_door_hit == true)
			game->ray.vertical_door_hit = false;
	}
	else
	{
		game->ray.length = v_inter;
		game->ray.x = game->ray.vx;
		game->ray.y = game->ray.vy;
		game->ray.horizontal = false;
		if (game->ray.horizontal_door_hit == true)
			game->ray.horizontal_door_hit = false;
	}
}
