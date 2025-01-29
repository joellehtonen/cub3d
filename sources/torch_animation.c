/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:42 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/28 17:02:45 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void torch_animation(t_game *game)
{
	if (game->frame_counter < 21)
		(game->frame_counter)++;
	else
		game->frame_counter = 0;
	mlx_image_to_window(game->mlx, game->torch_animation_images[game->frame_counter / 3], 960, 600);
}
