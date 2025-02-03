/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:35:13 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/03 17:01:15 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void increment_frame_counter(t_game *game)
{
    game->frame_counter++;
    if (game->frame_counter == INT_MAX - 1)
        game->frame_counter = 0;
}

/*
	@brief Intermittently deletes on-screen warning text about doors. 
    @param content Our game struct
*/
static void    delete_door_warning(t_game *game)
{
    if (game->door_warning && game->frame_counter % 50 == 0)
		mlx_delete_image(game->mlx, game->door_warning);
}

/*
	@brief Our main loop, raycasting and rendering whenever a movement occurs.
    @param content Our game struct as a void pointer
*/
void    rendering(void *content)
{
    t_game  *game;
    bool     movement;

    game = (t_game *)content;
    raycasting(game);
    movement = controls(game);
    if (movement == true)
    {
        clear_line(game);
        raycasting(game);
    }
    increment_frame_counter(game);
	torch_animation(game);
    delete_door_warning(game);
}
