#include "../includes/cu3ed.h"

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


// left key = player.angle -=0.1; player.

void init_ray(t_game *game)
{
	// maybe not necessary to count degrees first
	// if supposed to face North = 0, if South = 180, East = 90, West = 270. Assume North for now.
	game->player.angle_degree = 0;
	game->player.angle_radian = game->player.angle_degree * (PI / 180);
	game->player.dx = cos(game->player.angle_radian);
	game->player.dy = sin(game->player.angle_radian);
}

void raycasting(t_game *game)
{
	double	h_inter; //horizontal intersection of the ray
	double	v_inter; //vertical intersection of the ray
	int		ray;

	ray = 0; //first ray, last one will be 60

	game->ray.angle = game->player.angle_degree - (FOV / 2);
	// now i wanna count the x & y coords of the ray end point, if ray is one tile_size long
	game->ray.y = (game->player.y / TILE_SIZE) * TILE_SIZE; //basically the y coord in pixels?
	game->ray.y = game->player.y; //perhaps this is enough
	game->ray.x = game->player.x + (game->ray.y - game->player.y) / tan(game->ray.angle);

	if (game->player.angle_degree < 0)
		game->player.angle_degree = 360;
	if (game->player.angle_degree > 360)
		game->player.angle_degree = 0;

	

}