/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:35:13 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/30 10:48:45 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    rendering(void * content)
{
    t_game  *game;
    game =  (t_game *)content;
    bool     movement;

    raycasting(game);
    movement = controls(game);
    if (movement == true)
    {
        clear_line(game);
        raycasting(game);
    }
	//mlx_image_to_window(game->mlx, game->flame_img[0], 0, 0);
	torch_animation(game);
}
