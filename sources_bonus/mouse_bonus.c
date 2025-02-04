/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:59:00 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 16:21:18 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

/*
	@brief Checks if mouse has moved on x-axis, 
	 and if so, rotates player
    @param content Our game struct as a void pointer
*/
void	check_mouse_movement(t_game *game)
{
	int32_t	x;
	int32_t	y;

	x = 0;
	y = 0;
	mlx_get_mouse_pos(game->mlx, &x, &y);
	if (x > game->mouse_x)
		rotate_player(game, RIGHT);
	if (x < game->mouse_x)
		rotate_player(game, LEFT);
	game->mouse_x = x;
	reset_angles(game);
	determine_ray_direction(game);
}
