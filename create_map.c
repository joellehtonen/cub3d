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

#include "cu3ed.h"

static int	count_lines(char *filename)
{
	int		fd;
	int		result;
	char	*temp;

	result = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid file: File does not exist");
	temp = get_next_line(fd);
	while (temp)
	{
		result++;
		free(temp);
		temp = NULL;
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
	return (result);
}

void	create_map(char *filename)
{
	//int		file;
	//int		i;
	int		num_of_lines;

	num_of_lines = count_lines(filename);
	if (num_of_lines == 0)
		error_exit("Invalid file: File is empty");
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
