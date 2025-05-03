/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:15:23 by nando             #+#    #+#             */
/*   Updated: 2025/05/03 17:54:08 by nando            ###   ########.fr       */
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
	ft_printf(error_script);
	exit(EXIT_FAILURE);
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

void	free_images(t_game *g)
{
	mlx_destroy_image(g->mlx, g->img.player);
	mlx_destroy_image(g->mlx, g->img.start);
	mlx_destroy_image(g->mlx, g->img.goal);
	mlx_destroy_image(g->mlx, g->img.collectable);
	mlx_destroy_image(g->mlx, g->img.wall);
	mlx_destroy_image(g->mlx, g->img.floor);
	mlx_destroy_image(g->mlx, g->img.img);
}
