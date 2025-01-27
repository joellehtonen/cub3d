/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:59:10 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/27 18:18:29 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	place_for_minimap(t_game* game, int x, int y)
{
	if (x < (game->width_in_tiles * TILE_SIZE) && y < (game->height_in_tiles * TILE_SIZE))
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
			return (0xCD5C5CFF);
		else
			return (0x8B0000FF);
	}
	else
	{
		if (game->ray.direction_left == true)
			return (0xFF8C00FF);
		else
			return (0xB22222FF);
	}
}

// void	clear_frame(t_game *game)
// {
// 	int			i;
// 	int			alpha;
	
// 	alpha = 0x00000000;
// 	i = 0;
// 	while (i < (WINDOW_HEIGHT * WINDOW_HEIGHT))
// 	{
// 		((uint32_t *)game->frame->pixels)[i] = alpha;
// 		i++;
// 	}
// }
