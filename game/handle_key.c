/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:25:26 by nando             #+#    #+#             */
/*   Updated: 2025/05/07 16:29:58 by nando            ###   ########.fr       */
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

static void	get_collectable(t_game *g, int new_x, int new_y)
{
	g->collected++;
	ft_printf("Yay, you got a bone!\n");
	if (g->collected == g->total_collect)
		ft_printf("Now you have all the bones. Let's go home.\n");
	g->map[new_y][new_x] = '0';
}

static void	get_goal(t_game *g)
{
	ft_printf("You’re finally home!!!\nThank you for completing this adventure.\n");
	close_window(g);
}

static void	update_tiles(t_game *g, int new_x, int new_y)
{
	g->map[g->player_y][g->player_x] = '0';
	g->player_x = new_x;
	g->player_y = new_y;
	g->map[g->player_y][g->player_x] = 'P';
}

int	handle_press_key(int keycode, t_game *g)
{
	int		new_x;
	int		new_y;
	int		dx;
	int		dy;
	char	cell;

	if (keycode == ESC_KEY)
		return (close_window(g));
	get_delta(keycode, &dx, &dy);
	new_x = g->player_x + dx;
	new_y = g->player_y + dy;
	cell = g->map[new_y][new_x];
	if (cell == '1' || (cell == 'E' && g->collected != g->total_collect))
		return (0);
	g->count_move++;
	ft_printf("[move : %d]\n", g->count_move);
	if (cell == 'C')
		get_collectable(g, new_x, new_y);
	else if (cell == 'E' && g->collected == g->total_collect)
		get_goal(g);
	update_tiles(g, new_x, new_y);
	draw_map(g);
	return (0);
}
