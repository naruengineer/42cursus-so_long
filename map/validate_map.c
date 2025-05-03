/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:31:18 by nando             #+#    #+#             */
/*   Updated: 2025/05/03 17:17:28 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_rectangular(char **map)
{
	size_t	width;
	int		i;

	if (map == NULL || map[0] == NULL)
		return (NG);
	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (width != ft_strlen(map[i]))
			return (NG);
		i++;
	}
	return (OK);
}

void	validate_map(char **map, t_mapinfo *info, t_dfs *dfs)
{
	if (is_rectangular(map) == NG)
		free_map_and_exit(map, "Error : map is not rectangular\n");
	info->map = map;
	info->height = 0;
	while (map[info->height])
		info->height++;
	info->width = ft_strlen(map[0]);
	if (check_charset(info) == NG)
		free_map_and_exit(map, "Error: map contains invalid characters\n");
	if (check_char_counts(info) == NG)
		free_map_and_exit(map, "Error: must have 1 = P, 1 = E, 1 <= C\n");
	if (check_wall(info) == NG)
		free_map_and_exit(map, "Error: map must be surrounded by walls\n");
	if (path_exists(info, dfs) == NG)
		free_map_and_exit(map,
			"Error: no valid path for collectibles and exit\n");
}
