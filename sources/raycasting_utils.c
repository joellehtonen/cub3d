#include "../includes/cub3d.h"

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
