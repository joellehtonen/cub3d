/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_minimap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:30:17 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/04 16:21:22 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void resize_minimap(t_game *game)
{
	if (game->width_in_tiles > 32 || game->height_in_tiles > 16)
	{
		printf("Map is too large to display minimap\n");
		game->show_minimap = false;
	}
	if (game->width_in_tiles <= 16 || game->height_in_tiles <= 8)
		game->tile_size = 32;
	else if (game->width_in_tiles <= 32 || game->height_in_tiles <= 16)
		game->tile_size = 16;
	else
		game->tile_size = 8;
}