/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:42 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/03 10:10:07 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void disable_all_flames(t_game *game)
{
	int i;

	i = 0;
	while (i <  12)
	{
		game->animation.flame_img[i]->enabled = false;
		i++;
	}
}

static void update_positions(t_game *game)
{
	int i;

	game->animation.zippo_img->instances->x = game->animation.zippo_x;
	game->animation.zippo_img->instances->y = game->animation.zippo_y;
	i = 0;
	while (i < 12)
	{
		game->animation.flame_img[i]->instances->x = game->animation.flame_x;
		game->animation.flame_img[i]->instances->y = game->animation.flame_y;
		i++;
	}
}

void torch_animation(t_game *game)
{
	update_positions(game);
	game->animation.flame_img[game->animation.frame_counter / 6]->enabled = false;
	game->animation.frame_counter = (game->animation.frame_counter + 1) % 33;
	game->animation.flame_img[game->animation.frame_counter / 6]->enabled = true;
}
