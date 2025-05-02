/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_exists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:37:34 by nando             #+#    #+#             */
/*   Updated: 2025/05/02 14:15:31 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	find_start(t_mapinfo *mapinfo, int *start_row, int *start_column)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapinfo->height)
	{
		j = 0;
		while (j < mapinfo->width)
		{
			if (mapinfo->map[i][j] == 'P')
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

static void	init_dfs(t_dfs *dfs, t_mapinfo *mapinfo)
{
	int	i;
	int	j;

	i = 0;
	dfs->mapinfo = mapinfo;
	dfs->found_e = 0;
	dfs->found_c = 0;
	dfs->total_c = 0;
	while (i < mapinfo->height)
	{
		j = 0;
		while (j < mapinfo->width)
		{
			if (mapinfo->map[i][j] == 'C')
				dfs->total_c++;
			j++;
		}
		i++;
	}
	dfs->visited = calloc(mapinfo->height * mapinfo->width,
			sizeof * dfs->visited);
	if (!dfs->visited)
		free_map_and_exit(mapinfo->map, "Error : memory allocation failed");
}

static void	running_dfs(int row, int column, t_dfs *dfs)
{
	int			index;
	t_mapinfo	*map;

	map = dfs->mapinfo;
	if (row < 0 || row >= map->height || column < 0 || column >= map->width)
		return ;
	if (map->map[row][column] == '1')
		return ;
	index = row * map->width + column;
	if (dfs->visited[index])
		return ;
	dfs->visited[index] = 1;
	if (map->map[row][column] == 'C')
		dfs->found_c++;
	if (map->map[row][column] == 'E')
		dfs->found_e = 1;
	running_dfs(row + 1, column, dfs);
	running_dfs(row - 1, column, dfs);
	running_dfs(row, column + 1, dfs);
	running_dfs(row, column - 1, dfs);
}

int	path_exists(t_mapinfo *mapinfo)
{
	int		start_row;
	int		start_column;
	t_dfs	dfs;

	find_start(mapinfo, &start_row, &start_column);
	if (start_row < 0 || start_column < 0)
		return (NG);
	init_dfs(&dfs, mapinfo);
	running_dfs(start_row, start_column, &dfs);
	if (dfs.found_e == 1 && dfs.found_c == dfs.total_c)
	{
		free(dfs.visited);
		return (OK);
	}
	free(dfs.visited);
	return (NG);
}
