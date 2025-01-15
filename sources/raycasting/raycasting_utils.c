#include "cub3d.h"

void	determine_ray_direction(t_game *game)
{
	if ((game->ray.angle >= 0 && game->ray.angle <= 90)
		|| game->ray.angle <= 360 && game->ray.angle >= 270)
		game->ray.ray_points_up = true;
	else
		game->ray.ray_points_up = false;
	if (game->ray.angle >= 0 && game->ray.angle <= 180)
		game->ray.ray_points_left = true;
	else
		game->ray.ray_points_left = false;
	return ;
}
