/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:19:38 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 20:05:39 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	@brief Our main loop, raycasting and rendering whenever a movement occurs.
    @param content Our game struct as a void pointer
*/
void	rendering(void *data)
{
	t_game	*game;
	bool	movement;

	game = (t_game *)data;
	raycasting(game);
	movement = controls(game);
	if (movement == true)
	{
		raycasting(game);
	}
}
