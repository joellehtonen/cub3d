/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:28:30 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/21 09:10:43 by jlehtone         ###   ########.fr       */
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
    game->map = NULL;
	game->file = NULL;
    game->path_to_north_texture = NULL;
	game->path_to_south_texture = NULL;
	game->path_to_west_texture = NULL;
	game->path_to_east_texture = NULL;
    game->floor_rgb = NULL;
	game->ceiling_rgb = NULL;
	game->mlx = NULL;
	game->floor_img = NULL;
	game->floor_texture = NULL;
	game->wall_img = NULL;
	game->wall_texture = NULL;
	game->minimap_img = NULL;
	game->width = TILE_SIZE * 20;
	game->height = TILE_SIZE * 10;
	game->image_size = TILE_SIZE;
}

static void temp_copy_file_to_map(t_game *game)
{
	int i = 0;
	while (game->file[i])
		i++;
	game->map = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (game->file[i])
	{
		game->map[i] = ft_strdup(game->file[i]);
		i++;
	}
	game->map[i] = NULL;
}

int	main(int argc, char *argv[])
{
	t_game game;

	//Init and parsing --------------------------------------------------------
	initialize_variables(&game);
	check_number_of_arguments(argc);
	validate_filetype(argv[1]);
	create_copy_of_file(&game, argv[1]);
	parse_file(&game);
	temp_copy_file_to_map(&game); //REMOVE

	//MLX ---------------------------------------------------------------------
	game.mlx = mlx_init(game.width, game.height, "cub3d", true);
	if (!(game.mlx))
		error_exit_and_free(&game, "MLX failed to initialize");
	create_textures(&game);
	create_images(&game);
	resize_images(&game);
	display_map(&game);
	init_ray(&game); //we can find a better/more logical place for this
	mlx_loop_hook(game.mlx, &rendering, &game);
	mlx_loop(game.mlx);
	free_all(&game);
	return (0);
}
