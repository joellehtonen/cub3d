/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:42 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/31 15:53:06 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void disable_all_flames(t_game *game)
{
	int i;

	i = 0;
	while (i < 12)
	{
		game->flame_img[i]->enabled = false;
		i++;
	}
}

static void update_positions(t_game *game)
{
	int i;

	game->zippo_img->instances->x = game->zippo_x;
	game->zippo_img->instances->y = game->zippo_y;
	i = 0;
	while (i < 12)
	{
		game->flame_img[i]->instances->x = game->flame_x;
		game->flame_img[i]->instances->y = game->flame_y;
		i++;
	}
}

void torch_animation(t_game *game)
{
	update_positions(game);
	game->flame_img[game->frame_counter / 6]->enabled = false;
	game->frame_counter = (game->frame_counter + 1) % 33;
	game->flame_img[game->frame_counter / 6]->enabled = true;
}
