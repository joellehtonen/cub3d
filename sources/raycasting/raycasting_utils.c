#include "cub3d.h"

void	determine_ray_direction(t_game *game)
{
	if ((game->ray.angle >= 0 && game->ray.angle <= 90)
		|| game->ray.angle <= 360 && game->ray.angle >= 270)
		game->ray.direction_up = true;
	else
		game->ray.direction_up = false;
	if (game->ray.angle >= 0 && game->ray.angle <= 180)
		game->ray.direction_left = true;
	else
		game->ray.direction_left = false;
	return ;
}
