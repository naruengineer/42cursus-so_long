/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:15:23 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 20:54:09 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map_and_exit(char **map, char *error_script)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	error_and_exit(error_script);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}


void	free_mlx(t_game *g)
{
	mlx_destroy_image(g->mlx, g->img.player);
	mlx_destroy_image(g->mlx, g->img.start);
	mlx_destroy_image(g->mlx, g->img.goal);
	mlx_destroy_image(g->mlx, g->img.collectable);
	mlx_destroy_image(g->mlx, g->img.wall);
	mlx_destroy_image(g->mlx, g->img.floor);
	mlx_destroy_image(g->mlx, g->img.img);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
}
