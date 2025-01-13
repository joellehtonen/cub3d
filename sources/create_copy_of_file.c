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

static void	copy_file(t_main *main, char *filename)
{
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid file: Failed to open file");
	i = 0;
	(main->file)[0] = get_next_line(fd);
	while ((main->file)[i])
		(main->file)[++i] = get_next_line(fd); //ADD MALLOC CHECK
	(main->file)[i] = NULL;
	close(fd);
}

static void	malloc_for_copy_file(t_main *main, int num_of_lines)
{
	main->file = (char **)malloc((num_of_lines + 1) * sizeof(char *));
	if (!(main->file))
		error_exit("Failed to malloc copy of file");
}

static void	print_file(char **file) //REMOVE
{
	int i = 0;

	while (file[i])
		printf("%s", file[i++]);
}

void	create_copy_of_file(t_main *main, char *filename)
{
	int		num_of_lines;

	get_num_of_lines(filename, &num_of_lines);
	check_for_empty_file(num_of_lines);
	malloc_for_copy_file(main, num_of_lines);
	copy_file(main, filename);
	print_file(main->file); //REMOVE
}
