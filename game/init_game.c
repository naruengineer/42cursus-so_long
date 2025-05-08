/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:07:43 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 21:59:37 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

#define TILE_SIZE 64

static void	init_game_materials(t_game *g)
{
	g->img.player = mlx_xpm_file_to_image(g->mlx, "textures/player.xpm",
			&g->tile_size, &g->tile_size);
	g->img.start = mlx_xpm_file_to_image(g->mlx, "textures/start.xpm",
			&g->tile_size, &g->tile_size);
	g->img.goal = mlx_xpm_file_to_image(g->mlx, "textures/goal.xpm",
			&g->tile_size, &g->tile_size);
	g->img.collectable = mlx_xpm_file_to_image(g->mlx,
			"textures/collectable.xpm", &g->tile_size, &g->tile_size);
	g->img.wall = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm",
			&g->tile_size, &g->tile_size);
	g->img.floor = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm",
			&g->tile_size, &g->tile_size);
}

void	init_game(t_game *g)
{
	g->collected = 0;
	g->count_move = 0;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->width * TILE_SIZE, g->height * TILE_SIZE,
			"so_long");
	g->img.img = mlx_new_image(g->mlx, g->width * TILE_SIZE, g->height
			* TILE_SIZE);
	g->img.address = mlx_get_data_addr(g->img.img, &g->img.bits_per_pixel,
			&g->img.line_length, &g->img.endian);
	init_game_materials(g);
}
