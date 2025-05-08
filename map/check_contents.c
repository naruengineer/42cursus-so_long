/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:21:42 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 21:38:53 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_rectangular(t_game *g)
{
	g->width = ft_strlen(g->map[0]);
	g->height = 1;
	while (g->map[g->height])
	{
		if (g->width != ft_strlen(g->map[g->height]))
			return (NG);
		g->height++;
	}
	return (OK);
}

int	check_charset(t_game *g)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			c = g->map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (NG);
			j++;
		}
		i++;
	}
	return (OK);
}

static int	count_in_map(t_game *g, char target)
{
	int		i;
	int		j;
	size_t	count;

	i = 0;
	count = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == target)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_char_counts(t_game *g)
{
	size_t	p_count;
	size_t	e_count;
	size_t	c_count;

	p_count = count_in_map(g, 'P');
	e_count = count_in_map(g, 'E');
	c_count = count_in_map(g, 'C');
	if (p_count != 1 || e_count != 1 || c_count < 1)
		return (NG);
	return (OK);
}

int	check_wall(t_game *g)
{
	size_t	i;

	i = 0;
	while (i < g->width)
	{
		if (g->map[0][i] != '1' || g->map[g->height - 1][i] != '1')
			return (NG);
		i++;
	}
	i = 1;
	while (i < g->height)
	{
		if (g->map[i][0] != '1' || g->map[i][g->width - 1] != '1')
			return (NG);
		i++;
	}
	return (OK);
}
