/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:07:43 by nando             #+#    #+#             */
/*   Updated: 2025/05/06 18:03:11 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_exit(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

static void	init_game_materials(t_game *g)
{
	int	tile_height;
	int	tile_width;

	g->img.player = mlx_xpm_file_to_image(g->mlx, "materials/player.xpm",
			&tile_height, &tile_width);
	g->img.start = mlx_xpm_file_to_image(g->mlx, "materials/start.xpm",
			&tile_height, &tile_width);
	g->img.goal = mlx_xpm_file_to_image(g->mlx, "materials/goal.xpm",
			&tile_height, &tile_width);
	g->img.collectable = mlx_xpm_file_to_image(g->mlx,
			"materials/collectable.xpm", &tile_height, &tile_width);
	g->img.wall = mlx_xpm_file_to_image(g->mlx, "materials/wall.xpm",
			&tile_height, &tile_width);
	g->img.floor = mlx_xpm_file_to_image(g->mlx, "materials/floor.xpm",
			&tile_height, &tile_width);
}

void	init_game(t_game *g)
{
	g->collected = 0;
	g->count_move = 0;
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->width * 64, g->height * 64, "so_long");
	g->img.img = mlx_new_image(g->mlx, g->width * 64, g->height * 64);
	g->img.address = mlx_get_data_addr(g->img.img, &g->img.bits_per_pixel,
			&g->img.line_length, &g->img.endian);
	init_game_materials(g);
}
