/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:34:27 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 22:00:29 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	running_game(t_game *g)
{
	draw_map(g);
	mlx_hook(g->win, 2, 1L << 0, handle_press_key, g);
	mlx_hook(g->win, 17, 0, close_window, g);
	mlx_expose_hook(g->win, handle_expose, g);
	mlx_loop(g->mlx);
}
