/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:57:39 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/31 15:13:22 by jlehtone         ###   ########.fr       */
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
	game->floor_r = -1;
	game->floor_g = -1;
	game->floor_b = -1;
	game->ceiling_r = -1;
	game->ceiling_g = -1;
	game->ceiling_b = -1;
	game->floor_rgb = 0;
	game->ceiling_rgb = 0;
	game->frame_counter = 0;
	game->flame_mem_img = NULL;
	game->flame_x = FLAME_X;
	game->flame_y = FLAME_Y;
	game->zippo_x = ZIPPO_X;
	game->zippo_y = ZIPPO_Y;
	game->zippo_counter = 0;
	game->tile_size = TILE_SIZE;
	game->doors_closed = true;
	game->can_close_doors = true;
	// maybe lets memset these, except -1s
}

// static void resize_minimap(t_game *game)
// {
	
// }

int	main(int argc, char *argv[])
{
	t_game	game;

	initialize_variables(&game);
	check_number_of_arguments(argc);
	validate_filetype(argv[1]);
	create_copy_of_file(&game, argv[1]);
	parse_file(&game);
	game.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d", true);
	if (!(game.mlx))
		error_exit_and_free(&game, "MLX failed to initialize");
	//resize_minimap(&game);
	create_textures(&game);
	create_images(&game);
	resize_images(&game);
	display_images(&game);
	disable_all_flames(&game);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	game.player.angle = game.starting_direction;
	mlx_loop_hook(game.mlx, &rendering, &game);
	mlx_loop(game.mlx);
	free_all(&game);
	return (0);
}
