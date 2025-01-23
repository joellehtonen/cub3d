/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:35:13 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/23 11:54:05 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void rendering(void * content)
{
    t_game  *game;
    game =  (t_game *)content;
    bool     movement;

    movement = controls(game);
    if (movement == true)
    {
        raycasting(game);
    }
}
