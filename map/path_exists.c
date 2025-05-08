/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_exists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:37:34 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 21:40:18 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_dfs(t_game *g)
{
	size_t	y;
	size_t	x;

	g->found_goal = 0;
	g->collected = 0;
	g->total_collect = 0;
	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if (g->map[y][x] == 'C')
				g->total_collect++;
			x++;
		}
		y++;
	}
	g->visited = calloc(g->height * g->width, sizeof *g->visited);
	if (!g->visited)
		free_map_and_exit(g->map, "Error : calloc failed");
}

static int	check_can_visit(t_game *g, size_t y, size_t x, int *index)
{
	if (y >= g->height || x >= g->width)
		return (NG);
	if (g->map[y][x] == '1')
		return (NG);
	*index = y * g->width + x;
	if (g->visited[*index])
		return (NG);
	return (OK);
}

static void	running_dfs(t_game *g, size_t y, size_t x)
{
	int	index;

	if (check_can_visit(g, y, x, &index) == NG)
		return ;
	g->visited[index] = 1;
	if (g->map[y][x] == 'C')
		g->collected++;
	if (g->map[y][x] == 'E')
		g->found_goal = 1;
	running_dfs(g, y + 1, x);
	running_dfs(g, y - 1, x);
	running_dfs(g, y, x + 1);
	running_dfs(g, y, x - 1);
}

static int	check_path(t_game *g)
{
	if (g->found_goal == 1 && g->collected == g->total_collect)
	{
		free(g->visited);
		return (OK);
	}
	free(g->visited);
	return (NG);
}

int	path_exists(t_game *g)
{
	init_dfs(g);
	running_dfs(g, g->player_y, g->player_x);
	if (check_path(g))
		return (OK);
	return (NG);
}
