/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:12:06 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 21:56:10 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_one_tile(t_game *g, void *tile, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, tile, x * g->tile_size, y * g->tile_size);
}

static void	draw_wall_floor(t_game *g)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if (g->map[y][x] == '1')
				draw_one_tile(g, g->img.wall, x, y);
			else
				draw_one_tile(g, g->img.floor, x, y);
			x++;
		}
		y++;
	}
}

static void	draw_materials(t_game *g)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if (g->map[y][x] == 'P')
			{
				g->player_x = x;
				g->player_y = y;
				draw_one_tile(g, g->img.player, x, y);
			}
			else if (g->map[y][x] == 'E')
				draw_one_tile(g, g->img.goal, x, y);
			else if (g->map[y][x] == 'C')
				draw_one_tile(g, g->img.collectable, x, y);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *g)
{
	draw_wall_floor(g);
	draw_materials(g);
}
