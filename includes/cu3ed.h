/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu3ed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:57 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/10 17:41:11 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CU3ED_H
# define CU3ED_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
//# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_main
{
    char	**map;
	char	**file;
    char	*path_to_north_texture;
    char	*path_to_south_texture;
    char	*path_to_west_texture;
    char	*path_to_east_texture;
    int		*floor_rgb;
    int		*ceiling_rgb;
} t_main;

void	error_exit(char *error);
void	validate_filetype(char *filename);
void	create_copy_of_file(t_main *main, char *filename);
void    parse_file(t_main *main);

#endif