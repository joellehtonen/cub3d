/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:58:27 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 16:21:06 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

/*
	@brief Checks if the door placement on the map follows the rules or not.
	@param Our game struct
	@param x x-coordinate to check on the map
	@param y y-coordinate to check on the map
*/
void	check_for_valid_door(t_game *game, int x, int y)
{
	if (game->map[y][x] != 'D')
		return ;
	else if (game->map[y][x] == 'D')
	{
		if (!(game->map[y + 1][x] == '1' && game->map[y - 1][x] == '1' \
			&& game->map[y][x + 1] == '0' && game->map[y][x - 1] == '0')
			&& !(game->map[y + 1][x] == '0' && game->map[y - 1][x] == '0' \
			&& game->map[y][x + 1] == '1' && game->map[y][x - 1] == '1'))
		{
			printf("Door position not valid at x:%d, y:%d\n", x, y);
			error_exit_and_free(game, \
				"A door needs to be next to both walls and open spaces");
		}
	}
	return ;
}

/*
	@brief Sets up and checks if space bar was pressed. 
	 Triggers the function to open or close doors. 
	@param key A struct holding information about the keypress.
	@param *data Void pointer containing the game information
*/
void	set_up_space_bar(mlx_key_data_t key, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
		open_close_doors(game);
	return ;
}

/*
	@brief Opens or closes all the doors.
	@param key Our game struct
*/
void	open_close_doors(t_game *game)
{
	char		*string;

	if (game->door_warning)
		mlx_delete_image(game->mlx, game->door_warning);
	if (game->map[(int)game->player.y / game->tile_size] \
		[(int)game->player.x / game->tile_size] == 'D')
	{
		string = "Cannot close the door. You are too close!";
		game->door_warning = mlx_put_string(game->mlx, string, \
			WINDOW_WIDTH / 2.5, WINDOW_HEIGHT / 2);
		if (game->door_warning)
			mlx_resize_image(game->door_warning, 700, 50);
		game->frame_value = game->frame_counter;
		return ;
	}
	game->doors_closed = !game->doors_closed;
}
