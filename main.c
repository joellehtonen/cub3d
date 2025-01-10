/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:19 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/10 17:37:24 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cu3ed.h"

static void	check_number_of_arguments(int n)
{
	if (n != 2)
		error_exit("Invalid number of argument");	
}

int	main(int argc, char *argv[])
{
	check_number_of_arguments(argc);
	validate_filetype(argv[1]);
	create_map(argv[1]);
}
