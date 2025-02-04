/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:42 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/04 10:46:26 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	disable_all_flames(t_game *game)
{
	int i;

	i = 0;
	while (i < 12)
	{
		game->animation.flame_img[i]->enabled = false;
		i++;
	}
}

static void	shrink_flames(t_game *game, int i)
{
	int	repeat;
	
	game->animation.new_flame_size_x -= 1;
	game->animation.new_flame_size_y -= 1;
	mlx_resize_image(game->animation.flame_img[i], game->animation.new_flame_size_x, game->animation.new_flame_size_y);
	// game->animation.flame_img[i]->instances->x -= 10;
	// game->animation.flame_img[i]->instances->y -= 10;
	game->animation.flame_x += 0.45;
	game->animation.flame_y += 0.57;
	if (game->animation.new_flame_size_x < 10)
	{
		repeat = 0;
		while (repeat < 50)
		{
			printf("You're lost in the darkness...\n");
			repeat++;
		}
		free_all(game);
		exit (1);
	}
}

static void	update_positions(t_game *game)
{
	int i;

	game->animation.zippo_img->instances->x = game->animation.zippo_x;
	game->animation.zippo_img->instances->y = game->animation.zippo_y;
	i = 0;
	while (i < 12)
	{
		if (DARK == 1 && game->frame_counter % 20 == 0)
			shrink_flames(game, i);
		game->animation.flame_img[i]->instances->x = game->animation.flame_x;
		game->animation.flame_img[i]->instances->y = game->animation.flame_y;
		i++;
		
	}
}

void	torch_animation(t_game *game)
{
	update_positions(game);
	game->animation.flame_img[game->animation.frame_counter / 6]->enabled = false;
	game->animation.frame_counter = (game->animation.frame_counter + 1) % 33;
	game->animation.flame_img[game->animation.frame_counter / 6]->enabled = true;
}
