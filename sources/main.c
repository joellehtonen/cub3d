/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:57:39 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/03 16:35:55 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_number_of_arguments(int n)
{
	if (n != 2)
		error_exit("Invalid number of arguments");
}

static void	initialize_variables(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->floor_r = -1;
	game->floor_g = -1;
	game->floor_b = -1;
	game->ceiling_r = -1;
	game->ceiling_g = -1;
	game->ceiling_b = -1;
	game->animation.flame_x = FLAME_X;
	game->animation.flame_y = FLAME_Y;
	game->animation.zippo_x = ZIPPO_X;
	game->animation.zippo_y = ZIPPO_Y;
	game->tile_size = TILE_SIZE;
	game->show_minimap = true;
	game->doors_closed = true;
}

static void initialize_mlx(t_game *game)
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d", true);
	if (!(game->mlx))
		error_exit_and_free(game, "MLX failed to initialize");
}

static void	determine_player_starting_direction(t_game *game)
{
	if (game->starting_direction == NORTH)
		game->player.angle = LEFT;
	else if (game->starting_direction == SOUTH)
		game->player.angle = RIGHT;
	else if (game->starting_direction == EAST)
		game->player.angle = FORWARD;	
	else if (game->starting_direction == WEST)
		game->player.angle = BACK;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	initialize_variables(&game);
	check_number_of_arguments(argc);
	validate_filetype(argv[1]);
	create_copy_of_file(&game, argv[1]);
	parse_file(&game);
	initialize_mlx(&game);
	resize_minimap(&game);
	create_textures(&game);
	create_images(&game);
	resize_images(&game);
	display_images(&game);
	disable_all_flames(&game);
	determine_player_starting_direction(&game);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_key_hook(game.mlx, &set_up_space_bar, &game);
	mlx_loop_hook(game.mlx, &rendering, &game);
	mlx_loop(game.mlx);
	free_all(&game);
	return (0);
}
