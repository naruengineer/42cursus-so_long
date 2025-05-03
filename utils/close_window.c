/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:10:27 by nando             #+#    #+#             */
/*   Updated: 2025/05/03 19:29:26 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game *g)
{
	printf("\nGood Bye!\n");
	free_images(g);
	free_map(g->map);
	mlx_destroy_window(g->mlx, g->win);
	exit(EXIT_SUCCESS);
	return (0);
}
