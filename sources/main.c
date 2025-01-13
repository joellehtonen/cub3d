/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:19 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/13 15:52:08 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cu3ed.h"

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
}

int	main(int argc, char *argv[])
{
	t_game game;

	initialize_variables(&game);
	check_number_of_arguments(argc);
	validate_filetype(argv[1]);
	create_copy_of_file(&game, argv[1]);
	parse_file(&game);
	free_all(&game);
	return (0);
}
