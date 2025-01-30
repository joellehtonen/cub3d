/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:42 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/30 11:41:47 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void disable_all_flames(t_game *game)
{
	int i;

	i = 0;
	while (i <  12)
	{
		game->flame_img[i]->enabled = false;
		i++;
	}
}

static void update_flame_positions(t_game *game)
{
	int i;

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
	update_flame_positions(game);
	game->flame_img[game->frame_counter / 6]->enabled = false;
	game->frame_counter = (game->frame_counter + 1) % 33;
	//ft_memcpy(game->flame_mem_img->pixels, game->flame_img[game->frame_counter / 6]->pixels, FLAME_SIZE * FLAME_SIZE * 4);
	//disable_all_flames(game);
	game->flame_img[game->frame_counter / 6]->enabled = true;
}
