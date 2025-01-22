/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_copy_of_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:47:42 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/22 11:11:01 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_num_of_lines(char *filename, int *num_of_lines)
{
	int		fd;
	char	*temp;

	*num_of_lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid file: Failed to open file");
	temp = get_next_line(fd);
	while (temp)
	{
		(*num_of_lines)++;
		free(temp);
		temp = NULL;
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
}

static void check_for_empty_file(int num_of_lines)
{
	if (num_of_lines == 0)
		error_exit("Invalid file: File is empty");	
}

static void	copy_file(t_game *game, char *filename)
{
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid file: Failed to open file");
	i = 0;
	(game->file)[0] = get_next_line(fd);
	while ((game->file)[i])
		(game->file)[++i] = get_next_line(fd); //ADD MALLOC CHECK AND IF FAIL FREE PREVIOUS
	(game->file)[i] = NULL;
	close(fd);
}

static void	malloc_for_copy_file(t_game *game, int num_of_lines)
{
	game->file = (char **)malloc((num_of_lines + 1) * sizeof(char *));
	if (!(game->file))
		error_exit("Failed to malloc copy of file");
}

// static void	print_file(char **file) //REMOVE
// {
// 	int i = 0;

// 	while (file[i])
// 		printf("%s", file[i++]);
// }

void	create_copy_of_file(t_game *game, char *filename)
{
	int		num_of_lines;

	get_num_of_lines(filename, &num_of_lines);
	check_for_empty_file(num_of_lines);
	malloc_for_copy_file(game, num_of_lines);
	copy_file(game, filename);
	//print_file(game->file); //REMOVE
}
