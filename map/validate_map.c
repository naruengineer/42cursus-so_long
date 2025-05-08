/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:31:18 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 18:53:54 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_map(t_game *game)
{
	if (check_rectangular(game) == NG)
		free_map_and_exit(game->map, "Error : map is not rectangular\n");
	if (check_charset(game) == NG)
		free_map_and_exit(game->map, "Error: map contains invalid char\n");
	if (check_char_counts(game) == NG)
		free_map_and_exit(game->map, "Error: must have 1 = P, 1 = E, 1 <= C\n");
	if (check_wall(game) == NG)
		free_map_and_exit(game->map, "Error: map is not surrounded by walls\n");
	if (path_exists(game) == NG)
		free_map_and_exit(game->map, "Error: invalid collectibles/exit path\n");
}
