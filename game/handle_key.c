/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:25:26 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 22:24:55 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

static int	check_dest_and_execute_events(t_game *g, char cell)
{
	if (cell == '1')
		return (NG);
	if (cell == 'E' && g->collected != g->total_collect)
	{
		ft_printf("Collect all the bones!\n");
		return (NG);
	}
	g->count_move++;
	ft_printf("[move : %d]\n", g->count_move);
	if (cell == 'C')
		get_collectable(g);
	else if (cell == 'E' && g->collected == g->total_collect)
		get_goal(g);
	return (OK);
}

static void	update_tiles(t_game *g)
{
	g->map[g->player_y][g->player_x] = '0';
	g->player_x = g->new_x;
	g->player_y = g->new_y;
	g->map[g->player_y][g->player_x] = 'P';
}

int	handle_press_key(int keycode, t_game *g)
{
	int		dx;
	int		dy;
	char	cell;

	if (keycode == ESC_KEY)
		return (close_window(g));
	get_delta(keycode, &dx, &dy);
	g->new_x = g->player_x + dx;
	g->new_y = g->player_y + dy;
	cell = g->map[g->new_y][g->new_x];
	if (check_dest_and_execute_events(g, cell) == NG)
		return (0);
	update_tiles(g);
	draw_map(g);
	return (0);
}
