/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_animation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:49:09 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 10:09:20 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	zippo_animation_recenter(t_game *game)
{
	if (game->animation.flame_x > FLAME_X)
	{
		game->animation.flame_x -= ZIPPO_MOVE_SPEED;
		game->animation.zippo_x -= ZIPPO_MOVE_SPEED;
	}
	else if (game->animation.flame_x < FLAME_X)
	{
		game->animation.flame_x += ZIPPO_MOVE_SPEED;
		game->animation.zippo_x += ZIPPO_MOVE_SPEED;
	}
}

void	zippo_animation_rotate(t_game *game, double direction)
{
	if (direction == LEFT && (game->animation.flame_x - FLAME_X) < 50)
	{
		game->animation.flame_x += ZIPPO_MOVE_SPEED;
		game->animation.zippo_x += ZIPPO_MOVE_SPEED;
	}
	else if (direction == RIGHT && (FLAME_X - game->animation.flame_x) < 50)
	{
		game->animation.flame_x -= ZIPPO_MOVE_SPEED;
		game->animation.zippo_x -= ZIPPO_MOVE_SPEED;
	}
}

void	zippo_up_and_down(t_game *game)
{
	game->animation.zippo_counter = (game->animation.zippo_counter + 1) % 10;
	if (game->animation.zippo_counter < 5)
	{
		game->animation.flame_y -= ZIPPO_BOB_SPEED;
		game->animation.zippo_y -= ZIPPO_BOB_SPEED;
	}
	else
	{
		game->animation.flame_y += ZIPPO_BOB_SPEED;
		game->animation.zippo_y += ZIPPO_BOB_SPEED;
	}
}
