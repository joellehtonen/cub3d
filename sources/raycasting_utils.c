/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:08:49 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/27 10:23:49 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	determine_ray_direction(t_game *game)
{
	if (game->ray.angle >= PI && game->ray.angle <= PI * 2)
	{
		game->ray.direction_up = true;
		//printf("ray points up\n");
	}
	else
	{
		game->ray.direction_up = false;
		//printf("ray points down\n");
	}
	if (game->ray.angle >= PI / 2 && game->ray.angle <= 3 * (PI / 2))
	{
		game->ray.direction_left = true;
		//printf("ray points left\n");
	}
	else
	{
		game->ray.direction_left = false;
		//printf("ray points right\n");
	}
	return ;
}

void	choose_shorter_distance(t_game *game, double h_inter, double v_inter)
{
	if (h_inter <= v_inter)
	{
		game->ray.length = h_inter;
		game->ray.x = game->ray.hx;
		game->ray.y = game->ray.hy;
		game->ray.horizontal = true;
	}
	else
	{
		game->ray.length = v_inter;
		game->ray.x = game->ray.vx;
		game->ray.y = game->ray.vy;
		game->ray.horizontal = false;
	}
}
