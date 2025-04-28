/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:31:18 by nando             #+#    #+#             */
/*   Updated: 2025/04/28 15:54:01 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_rectangular(char **map)
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

int	check_chars(char **map)
{
	int		i;
	int		j;
	char	c;

	if (map == NULL || map[0] == NULL)
		return (NG);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c == '\n')
			{
				j++;
				continue ;
			}
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (NG);
			j++;
		}
		i++;
	}
	return (OK);
}

static int	count_in_map(char **map, char target)
{
	int		i;
	int		j;
	int		count;
	char	c;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c == map[i][j];
			if (c != '\n' && c == target)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_counts(char **map)
{
	int	p_count;
	int	e_count;
	int	c_count;

	if (map == NULL || map[0] == NULL)
		return (NG);
	p_count = count_in_map(map, 'P');
	e_count = count_in_map(map, 'E');
	c_count = count_in_map(map, 'C');
	if (p_count == 1 && e_count == 1 && c_count >= 1)
		return (OK);
	return (NG);
}

void	validate_map(char **map)
{
	if (is_rectangular(map) == NG)
		free_map_and_exit(map, "Error : map is not rectangular");
	if (check_chars(map) == NG)
		free_map_and_exit(map, "Error: map contains invalid characters");
	if (check_counts(map) == NG)
		free_map_and_exit(map, "Error: must have 1 = P, 1 = E, 1 <= C");
	if (check_walls(map) == NG)
		free_map_and_exit(map, "Error: map must be surrounded by walls");
	if (path_exists(map) == NG)
		free_map_and_exit(map,
			"Error: no valid path for collectibles and exit");
}
