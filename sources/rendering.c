/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:35:13 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/03 12:23:26 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	@brief Our main loop, raycasting and rendering whenever a movement occurs.
    @param content Our game struct as a void pointer
*/
void    rendering(void *content)
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
	torch_animation(game);
    if (game->door_text && game->animation.frame_counter % 30 == 0)
		mlx_delete_image(game->mlx, game->door_text);
}
