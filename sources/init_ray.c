/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:19:13 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/24 17:23:09 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_ray(t_game *game)
{
	draw_background(game);
	mlx_image_to_window(game->mlx, game->background, 0, 0);
	game->background->instances[0].z = -1;
	game->player.angle = game->starting_direction;
}
