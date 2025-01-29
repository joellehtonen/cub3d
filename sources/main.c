/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/29 12:04:45 by kattimaijan      ###   ########.fr       */
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
	game->file = NULL;
	game->frame = NULL;
	game->minimap_floor_img = NULL;
	game->floor_texture = NULL;
	game->found_ceiling_rgb = 0;
	game->found_floor_rgb = 0;
	game->height_in_tiles = 0;
	game->minimap_img = NULL;
	game->mlx = NULL;
	game->starting_direction = 0;
	game->minimap_wall_img = NULL;
	game->wall_texture = NULL;
	game->width_in_tiles = 0;
	game->map = NULL;
	game->path_to_north_texture = NULL;
	game->path_to_south_texture = NULL;
	game->path_to_west_texture = NULL;
	game->path_to_east_texture = NULL;
	game->floor_R = -1;
	game->floor_G = -1;
	game->floor_B = -1;
	game->ceiling_R = -1;
	game->ceiling_G = -1;
	game->ceiling_B = -1;
	game->floor_RGB = 0;
	game->ceiling_RGB = 0;
	game->frame_counter = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	//Init and parsing --------------------------------------------------------
	initialize_variables(&game);
	check_number_of_arguments(argc);
	validate_filetype(argv[1]);
	create_copy_of_file(&game, argv[1]);
	parse_file(&game);
	
	//MLX ---------------------------------------------------------------------
	game.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d", true);
	if (!(game.mlx))
		error_exit_and_free(&game, "MLX failed to initialize");
	create_textures(&game);
	create_images(&game);
	resize_images(&game);
	display_images(&game);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	// draw_background(&game);
	game.player.angle = game.starting_direction;
	mlx_loop_hook(game.mlx, &rendering, &game);
	mlx_loop(game.mlx);
	free_all(&game);
	return (0);
}
