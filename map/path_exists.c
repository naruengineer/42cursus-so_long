/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_exists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:37:34 by nando             #+#    #+#             */
/*   Updated: 2025/05/07 15:32:53 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	find_start(t_game *game ,int *start_row, int *start_column)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				*start_row = i;
				*start_column = j;
				return ;
			}
			j++;
		}
		i++;
	}
	*start_row = -1;
	*start_column = -1;
	return ;
}

static void	init_dfs(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->found_goal = 0;
	game->collected = 0;
	game->total_collect = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				game->total_collect++;
			j++;
		}
		i++;
	}
	game->visited = calloc(game->height * game->width,
			sizeof * game->visited);
	if (!game->visited)
		free_map_and_exit(game->map, "Error : memory allocation failed");
}

static void	running_dfs(t_game *game, int row, int column)
{
	int			index;

	if (row < 0 || row >= game->height || column < 0 || column >= game->width)
		return ;
	if (game->map[row][column] == '1')
		return ;
	index = row * game->width + column;
	if (game->visited[index])
		return ;
	game->visited[index] = 1;
	if (game->map[row][column] == 'C')
		game->collected++;
	if (game->map[row][column] == 'E')
		game->found_goal = 1;
	running_dfs(game, row + 1, column);
	running_dfs(game, row - 1, column);
	running_dfs(game, row, column + 1);
	running_dfs(game, row, column - 1);
}

int	path_exists(t_game *game)
{
	int		start_row;
	int		start_column;

	find_start(game, &start_row, &start_column);
	if (start_row < 0 || start_column < 0)
		return (NG);
	init_dfs(game);
	running_dfs(game, start_row, start_column);
	if (game->found_goal == 1 && game->collected == game->total_collect)
	{
		free(game->visited);
		return (OK);
	}
	free(game->visited);
	return (NG);
}
