/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:23:16 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/04 20:04:35 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void check_for_invalid_char(t_game *game, char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' &&
		c != 'W' && c != 'E' && c != ' ')
		error_exit_and_free(game, "Map contains invalid char");
}

static void check_for_player_direction(t_game *game, char c, int x, int y)
{
	if (game->starting_direction && 
		(c == 'N' || c == 'S' || c == 'W' || c == 'E'))
		error_exit_and_free(game, "Map contains more than one player position");
	if (c == 'N')
		game->starting_direction = NORTH;
	else if (c == 'S')
		game->starting_direction = SOUTH;
	else if (c == 'W')
		game->starting_direction = WEST;
	else if (c == 'E')
		game->starting_direction = EAST;
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		game->player.x = x * game->tile_size + game->tile_size / 2;
		game->player.y = y * game->tile_size + game->tile_size / 2;
	}
}

static int is_empty_space(char c)
{
	if (c == ' ' || c == '\0')
		return (1);
	return (0);
}

static void check_for_surrounding_walls(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == ' ')
		return ;
	if (x == 0 || y == 0 || !game->map[y + 1])
		error_exit_and_free(game, "Map not surrounded by wall on edge");
	if ((int)ft_strlen(game->map[y]) - 1 == x)
		error_exit_and_free(game, "Map not surrounded by wall on edge");
	if ((int)ft_strlen(game->map[y - 1]) < x || is_empty_space(game->map[y - 1][x]))
		error_exit_and_free(game, "Map not surrounded by wall above");
	if ((int)ft_strlen(game->map[y + 1]) < x || is_empty_space(game->map[y + 1][x]))
		error_exit_and_free(game, "Map not surrounded by wall below");
	if (is_empty_space(game->map[y][x - 1]))
		error_exit_and_free(game, "Map not surrounded by wall to the left");
	if (is_empty_space(game->map[y][x + 1]))
		error_exit_and_free(game, "Map not surrounded by wall to the right");
	
}

static void validate_width_and_height_in_tiles(t_game *game)
{
	int i;
	int temp;

	i = 0;
	while (game->map[i])
	{
		temp = ft_strlen(game->map[i++]);
		if (temp > game->width_in_tiles)
			game->width_in_tiles = temp;
	}
	if (game->width_in_tiles > MAX_WIDTH_IN_TILES)
		error_exit_and_free(game, "Map is too large");
	if (i > MAX_HEIGHT_IN_TILES)
		error_exit_and_free(game, "Map is too large");
	else
		game->height_in_tiles = i;
}

void validate_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			check_for_invalid_char(game, game->map[y][x]);
			check_for_player_direction(game, game->map[y][x], x, y);
			check_for_surrounding_walls(game, x, y);
			validate_width_and_height_in_tiles(game);
			x++;
		}
		y++;	
	}
}
