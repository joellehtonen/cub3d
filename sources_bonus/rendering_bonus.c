/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:19:38 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/10 13:25:32 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

/*
	@brief Increments frame counter as the game loops.
    @param *game Our game struct
*/
static void	increment_frame_counter(t_game *game)
{
	game->frame_counter++;
	if (game->frame_counter == INT_MAX - 1)
	{
		game->frame_counter = 0;
	}
}

/*
	@brief Intermittently deletes on-screen warning text about doors. 
    @param *game Our game struct
*/
static void	delete_door_warning(t_game *game)
{
	if (game->door_warning && game->frame_counter >= game->frame_value + 30)
	{
		mlx_delete_image(game->mlx, game->door_warning);
	}
}

/*
	@brief Toggles the door open or closed on the minimap display
    @param *game Our game struct
*/
static void	toggle_door_on_minimap(t_game *game)
{
	if (game->doors_closed == true)
	{
		game->minimap.closed_door_img->enabled = true;
	}
	else
		game->minimap.closed_door_img->enabled = false;
}

/*
	@brief Our main loop, raycasting and rendering whenever a movement occurs.
    @param *data Our game struct as a void pointer
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
		clear_line(game);
		raycasting(game);
	}
	increment_frame_counter(game);
	torch_animation(game);
	delete_door_warning(game);
	toggle_door_on_minimap(game);
}
