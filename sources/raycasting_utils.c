/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:08:49 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/22 10:28:29 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	reset_angles(t_game *game)
{
	if (game->ray.angle < 0)
		game->ray.angle += 2 * PI;
	if (game->ray.angle > 2 * PI)
		game->ray.angle -= 2 * PI;
	if (game->player.angle_radian < 0)
		game->player.angle_radian += 2 * PI;
	if (game->player.angle_radian > 2 * PI)
		game->player.angle_radian -= 2 * PI;
}

void	calculate_horizontal_step(t_game *game, float *step_x, float *step_y)
{
	*step_y = TILE_SIZE;
	if (game->ray.direction_up == true)
		*step_y *= -1;
	if (fabs(tan(game->ray.angle)) == 0)
		*step_x = 0;
	else
	{
		*step_x = *step_y * tan(game->player.angle_radian);
		if ((game->ray.direction_left == true && *step_x > 0)
			|| (game->ray.direction_left == false && *step_x < 0))
		{
			*step_x *= -1;
		}
	}
}

void	calculate_vertical_step(t_game *game, float *step_x, float *step_y)
{
	*step_x = TILE_SIZE;
	if (game->ray.direction_left == true)
		*step_x *= -1;
	if (fabs(tan(game->ray.angle)) == 0)
		*step_y = 0;
	else
	{
		*step_y = *step_x * tan(game->player.angle_radian);
		if ((game->ray.direction_up == true && *step_y > 0)
			|| (game->ray.direction_up == false && *step_y < 0))
		{
			*step_y *= -1;
		}
	}
}

void	determine_ray_direction(t_game *game)
{
	if (game->ray.angle >= 0 && game->ray.angle <= PI)
	{
		game->ray.direction_up = true;
		printf("ray points up\n");
	}
	else
	{
		game->ray.direction_up = false;
		printf("ray points down\n");
	}
	if (game->ray.angle >= PI / 2 && game->ray.angle <= 3 * (PI / 2))
	{
		game->ray.direction_left = true;
		printf("ray points left\n");
	}
	else
	{
		game->ray.direction_left = false;
		printf("ray points right\n");
	}
	return ;
}

void	choose_shorter_distance(t_game *game, double h_inter, double v_inter)
{
	if (h_inter == INFINITY || v_inter == INFINITY)
		return ;
	if (h_inter <= v_inter)
	{
		game->ray.distance = h_inter;
		game->ray.x = game->ray.hx;
		game->ray.y = game->ray.hy;
		printf("h_inter chosen!\n");
	}
	else
	{
		game->ray.distance = v_inter;
		game->ray.x = game->ray.vx;
		game->ray.y = game->ray.vy;
		printf("v_inter chosen!\n");
	}
}
