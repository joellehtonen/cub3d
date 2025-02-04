/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:59:10 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 16:21:08 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

/*
	@brief Corrects the fish eye-effect that comes when the rays hit the wall 
	 at slightly different angles.
	@param *game Our game struct
*/
void	correct_distortion(t_game *game)
{
	game->ray.length = game->ray.length * \
		cos(game->ray.angle - game->player.angle);
}
