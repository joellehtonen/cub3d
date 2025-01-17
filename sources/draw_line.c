/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:42:01 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/17 13:44:52 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void print_points(t_game *game, int points[10000][2], int num_of_points)
{
    int i;

    i = 0;
    while (i < num_of_points)
    {
        //printf("x = %d, y = %d\n", points[i][0], points[i][1]);
		mlx_put_pixel(game->minimap_img, points[i][0], points[i][1], 0xff00ffff);
        i++;
    }
}

static void store_points(t_game *game, int current_x, int current_y, int end_x, int end_y)
{
	// double delta_x;
	// double delta_y;
	
	// delta_x = (end_x - current_x)/(sqrt(pow((end_x - current_x), 2) + pow((end_y - current_y), 2)));
	// delta_y = (end_y - current_y)/(sqrt(pow((end_x - current_x), 2) + pow((end_y - current_y), 2)));

	// printf("delta_x = %f\n", delta_x);
	// printf("delta_y = %f\n", delta_y);
	
    int dif_x;
    int dif_y;
    int num_of_points;
    int points[10000][2];

    points[0][0] = current_x;
    points[0][1] = current_y;
    num_of_points = 1;
    while (1)
    {
        dif_x = end_x - current_x;
        dif_y = end_y - current_y;
        if (dif_x == 0 && dif_y == 0)
            break ;
        if (ft_abs(dif_y) > ft_abs(dif_x))
        {
            if (dif_y < 0)
                current_y--;
            else
                current_y++;
        }
        else
        {
            if (dif_x < 0)
                current_x--;
            else
                current_x++;
        }
        points[num_of_points][0] = current_x;
        points[num_of_points][1] = current_y;
        num_of_points++;
    }
    print_points(game, points, num_of_points);
}

static void clear_line(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < (int)game->minimap_img->height)
	{
		x = 0;
		while (x < (int)game->minimap_img->width)
		{
			mlx_put_pixel(game->minimap_img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void draw_line(t_game *game)
{
	clear_line(game);
    store_points(game, game->player.x, game->player.y, 0, 0);
}
