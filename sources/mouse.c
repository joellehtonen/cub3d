/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:59:00 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/03 14:43:20 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_up_mouse(void *data)
{
	t_game *game;
	int32_t	y;
	
	game = (t_game *)data;
	mlx_get_mouse_pos(game->mlx, &game->mouse_x, &y);
	return ;
}

void	check_mouse_movement(t_game *game)
{
	int32_t	x;
	int32_t	y;
	
	mlx_get_mouse_pos(game->mlx, &x, &y);
	if (x > game->mouse_x)
		rotate_player(game, RIGHT);
	if (x < game->mouse_x)
		rotate_player(game, LEFT);
	game->mouse_x = x;
}
