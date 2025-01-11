/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:47:42 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/10 17:46:43 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cu3ed.h"

static void	get_num_of_lines(char *filename, int *num_of_lines)
{
	int		fd;
	char	*temp;

	*num_of_lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid file: File does not exist");
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

void	create_map(char *filename)
{
	int		num_of_lines;

	get_num_of_lines(filename, &num_of_lines);
	check_for_empty_file(num_of_lines);
	printf("num_of_lines = %d\n", num_of_lines); //REMOVE
	
	// file = open(filename, O_RDONLY);
	// if (!file)
	// 	error_exit("Invalid file: Could not open file");
	// s->map = (char **)malloc(((s->line_num + 1) * sizeof(char *)) + 1);
	// if (!s->map)
	// 	error_exit("Failed to malloc map array");
	// i = 0;
	// s->map[i] = get_next_line(file);
	// while (s->map[i])
	// {
	// 	i++;
	// 	s->map[i] = get_next_line(file);
	// }
	// s->map_height = i - 1;
	// s->map[i] = 0;
	// remove_newlines(s);
	// close(file);
}
