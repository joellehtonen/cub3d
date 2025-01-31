/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:58:27 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/31 14:52:20 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	open_close_doors(t_game *game)
{
	// mlx_image_t	*door;
	// char		*string;

	if (game->frame_counter % 9 == 0)
		game->can_close_doors = true;
	if (game->map[(int)game->player.y / TILE_SIZE][(int)game->player.x / TILE_SIZE] == 'D')
	{
		// string = "Cannot close doors. You are too close!";
		// door = mlx_put_string(game->mlx, string, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		printf("Cannot close doors. You are too close!\n");
		return ;
	}
	if (game->can_close_doors == true)
		game->doors_closed = !game->doors_closed;
	game->can_close_doors = false;
}

void check_for_valid_door(t_game *game, int x, int y)
{
	if (game->map[y][x] != 'D')
		return ;
	else if (game->map[y][x] == 'D')
	{
		if (!(game->map[y + 1][x] == '1' && game->map[y - 1][x] == '1' && game->map[y][x + 1] == '0' && game->map[y][x - 1] == '0') 
			&& !(game->map[y + 1][x] == '0' && game->map[y - 1][x] == '0' && game->map[y][x + 1] == '1' && game->map[y][x - 1] == '1'))
		{
			printf("Door position not valid at x:%d, y:%d\n", x, y);
			error_exit_and_free(game, "A door needs to be next to both walls and open spaces");
		}
	}
	return ;
}
