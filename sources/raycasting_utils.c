#include "../includes/cub3d.h"
void	reset_ray_angle(t_game *game)
{
	if (game->ray.angle < 0)
		game->ray.angle += 2 * PI;
	if (game->ray.angle > 2 * PI)
		game->ray.angle -= 2 * PI;
}

void	calculate_horizontal_steps(t_game *game, float *step_x, float *step_y)
{
	*step_y = TILE_SIZE;
	if (game->ray.direction_up == true)
		*step_y *= -1;
	if (fabs(tan(game->player.angle_radian)) < 0.0001)
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

void	calculate_vertical_steps(t_game *game, float *step_x, float *step_y)
{
	*step_x = TILE_SIZE;
	if (game->ray.direction_left == true)
		*step_x *= -1;
	if (fabs(tan(game->player.angle_radian)) < 0.0001)
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
	if ((game->ray.angle >= 0 && game->ray.angle <= PI / 2)
		|| (game->ray.angle <= 2 * PI && game->ray.angle >= 3 * PI / 2))
		game->ray.direction_up = true;
	else
		game->ray.direction_up = false;
	if (game->ray.angle >= 0 && game->ray.angle <= PI)
		game->ray.direction_left = true;
	else
		game->ray.direction_left = false;
	return ;
}

void	choose_shorter_distance(t_game *game, double h_inter, double v_inter)
{
	if (h_inter <= v_inter)
	{
		game->ray.distance = h_inter;
		game->ray.x = game->ray.hx;
		if (game->ray.x > 10000)
			game->ray.x = 10000;
		if (game->ray.x < -10000)
			game->ray.x = -10000;
		game->ray.y = game->ray.hy;
		if (game->ray.y > 10000)
			game->ray.y = 10000;
		if (game->ray.y < -10000)
			game->ray.y = -10000;
	}
	else
	{
		game->ray.distance = v_inter;
		game->ray.x = game->ray.vx;
		if (game->ray.x > 10000)
			game->ray.x = 10000;
		if (game->ray.x < -10000)
			game->ray.x = -10000;
		game->ray.y = game->ray.vy;
		if (game->ray.y > 10000)
			game->ray.y = 10000;
		if (game->ray.y < -10000)
			game->ray.y = -10000;
	}
}
