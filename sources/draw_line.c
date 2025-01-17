/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:42:01 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/17 22:05:32 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// static void store_points(t_game *game, int current_x, int current_y, int end_x, int end_y)
// {
// 	// double delta_x;
// 	// double delta_y;
	
// 	// delta_x = (end_x - current_x)/(sqrt(pow((end_x - current_x), 2) + pow((end_y - current_y), 2)));
// 	// delta_y = (end_y - current_y)/(sqrt(pow((end_x - current_x), 2) + pow((end_y - current_y), 2)));

// 	// printf("delta_x = %f\n", delta_x);
// 	// printf("delta_y = %f\n", delta_y);
	
//     int dif_x;
//     int dif_y;
//     int num_of_points;

//     num_of_points = 1;
//     while (1)
//     {
//         dif_x = end_x - current_x;
//         dif_y = end_y - current_y;
//         if (dif_x == 0 && dif_y == 0)
//             break ;
//         if (ft_abs(dif_y) > ft_abs(dif_x))
//         {
//             if (dif_y < 0)
//                 current_y--;
//             else
//                 current_y++;
//         }
//         else
//         {
//             if (dif_x < 0)
//                 current_x--;
//             else
//                 current_x++;
//         }
// 		mlx_put_pixel(game->minimap_img, current_x, current_y, 0xff00ffff);
//         num_of_points++;
//     }
// }

static void bresenham_line(t_game *game, int x1, int y1, int x2, int y2)
{
    int dx = ft_abs(x2 - x1);
    int dy = ft_abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
		if (x1 > 0 && x1 < game->width && y1 > 0 && y1 < game->height)
        	mlx_put_pixel(game->minimap_img, x1, y1, 0xff00ffff);
        
        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;
        
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
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
	//printf("game_ray_x = %f and %d, game_ray_y = %f and %d\n", game->ray.x, (int)game->ray.x, game->ray.y, (int)game->ray.y);
	clear_line(game);
    bresenham_line(game, game->player.x, game->player.y, (int)game->ray.x, (int)game->ray.y);
	//bresenham_line(game, game->player.x, game->player.y, game->player.x, game->player.y - 100);
	
}
