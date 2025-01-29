/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:59:10 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/29 21:18:59 by kattimaijan      ###   ########.fr       */
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
			return (0x708090FF);
		else
			return (0x778899FF);
	}
	else
	{
		if (game->ray.direction_left == true)
			return (0xA9A9A9FF);
		else
			return (0x808080FF);
	}
}

