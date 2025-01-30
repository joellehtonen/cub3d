/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:59:10 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/30 09:02:50 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	place_for_minimap(t_game* game, int x, int y)
{
	(void)game;
	if (x < (MINIMAP_WIDTH) && y < (MINIMAP_HEIGHT))
		return (true);
	else
		return (false);
}

void	correct_distortion(t_game *game)
{
	game->ray.length = game->ray.length * cos(game->ray.angle - game->player.angle);
}

int	get_color(t_game *game)
{
	if (game->ray.horizontal == true)
	{
		if (game->ray.direction_up == true)
			return (0x323232FF);
		else
			return (0x313131FF);
	}
	else
	{
		if (game->ray.direction_left == true)
			return (0x303030FF);
		else
			return (0x292929FF);
	}
}

