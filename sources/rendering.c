/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:35:13 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/31 10:24:35 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	@brief Our main loop, raycasting and rendering whenever a movement occurs.acos
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
}
