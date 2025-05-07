/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:31:18 by nando             #+#    #+#             */
/*   Updated: 2025/05/07 15:31:58 by nando            ###   ########.fr       */
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

void	validate_map(t_game *game)
{
	if (is_rectangular(game->map) == NG)
		free_map_and_exit(game->map, "Error : map is not rectangular\n");
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->width = ft_strlen(game->map[0]);
	if (check_charset(game) == NG)
		free_map_and_exit(game->map, "Error: map contains invalid characters\n");
	if (check_char_counts(game) == NG)
		free_map_and_exit(game->map, "Error: must have 1 = P, 1 = E, 1 <= C\n");
	if (check_wall(game) == NG)
		free_map_and_exit(game->map, "Error: map must be surrounded by walls\n");
	if (path_exists(game) == NG)
		free_map_and_exit(game->map,
			"Error: no valid path for collectibles and exit\n");
}
