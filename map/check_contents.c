/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:21:42 by nando             #+#    #+#             */
/*   Updated: 2025/05/07 15:03:58 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_charset(t_game *game)
{
	char	**map;
	int		i;
	int		j;
	char	c;

	map = game->map;
	if (map == NULL || map[0] == NULL)
		return (NG);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
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
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == target)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_char_counts(t_game *game)
{
	char	**map;
	int		p_count;
	int		e_count;
	int		c_count;

	map = game->map;
	if (map == NULL || map[0] == NULL)
		return (NG);
	p_count = count_in_map(map, 'P');
	e_count = count_in_map(map, 'E');
	c_count = count_in_map(map, 'C');
	if (p_count == 1 && e_count == 1 && c_count >= 1)
		return (OK);
	return (NG);
}

int	check_wall(t_game *game)
{
	char	**map;
	int		m_height;
	int		m_width;
	int		i;

	map = game->map;
	i = 0;
	m_height = game->height;
	m_width = game->width;
	while (i < m_width)
	{
		if (map[0][i] != '1' || map[m_height - 1][i] != '1')
			return (NG);
		i++;
	}
	i = 1;
	while (i < m_height)
	{
		if (map[i][0] != '1' || map[i][m_width - 1] != '1')
			return (NG);
		i++;
	}
	return (OK);
}
