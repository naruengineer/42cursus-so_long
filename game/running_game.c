/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:34:27 by nando             #+#    #+#             */
/*   Updated: 2025/05/03 17:45:03 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	close_window(t_game *g)
{
	printf("\nGood Bye!\n");
	free_images(g);
	free_map(g->map);
	mlx_destroy_window(g->mlx, g->win);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	get_delta(int keycode, int *dx, int *dy)
{
	*dx = 0;
	*dy = 0;
	if (keycode == KEY_W || keycode == KEY_UP)
		*dy = -1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		*dy = 1;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		*dx = -1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		*dx = 1;
}

static int	handle_press_key(int keycode, t_game *g)
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	char	current;

	if (keycode == ESC_KEY)
		return (close_window(g));
	get_delta(keycode, &dx, &dy);
	x = g->player_x + dx;
	y = g->player_y + dy;
	current = g->map[y][x];
	if (current == '1' || (current == 'E' && g->collected != g->total_collect))
		return (0);
	g->count_move++;
	ft_printf("[move : %d]\n", g->count_move);
	if (current == 'C')
	{
		g->collected++;
		if (g->collected == g->total_collect)
			ft_printf("let's go home!\n");
		else
			ft_printf("You still need to get %d bones.\n", g->total_collect
				- g->collected);
		g->map[y][x] = '0';
	}
	else if (current == 'E' && g->collected == g->total_collect)
	{
		ft_printf("game clear!!!\n");
		close_window(g);
	}
	g->map[g->player_y][g->player_x] = '0';
	g->player_x = x;
	g->player_y = y;
	g->map[g->player_y][g->player_x] = 'P';
	draw_map(g);
	return (0);
}

void	running_game(t_game *g)
{
	draw_map(g);
	mlx_hook(g->win, 2, 1L << 0, handle_press_key, g);
	mlx_hook(g->win, 17, 0, close_window, g);
	mlx_loop(g->mlx);
}
