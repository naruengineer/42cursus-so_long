/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:41:36 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 21:30:41 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_line(char *filename)
{
	int		fd;
	size_t	line_count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_and_exit("Error : open failed\n");
	line = get_next_line(fd);
	line_count = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		line_count++;
	}
	close(fd);
	return (line_count);
}

static void	fill_a_map(char **map, int fd, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			free_map_and_exit(map, "Error : get_next_line failed\n");
		i++;
	}
	map[i] = NULL;
}

static void	remove_line_break(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		i++;
	}
}

static void	search_player_xy(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'P')
			{
				g->player_y = y;
				g->player_x = x;
			}
			x++;
		}
		y++;
	}
}

void	load_map(t_game *g, char *filename)
{
	int		fd;
	size_t	line_count;

	line_count = count_line(filename);
	g->map = malloc(sizeof(char *) * (line_count + 1));
	if (!g->map)
		error_and_exit("Error : malloc failed\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		free_map_and_exit(g->map, "Error : open failed\n");
	fill_a_map(g->map, fd, line_count);
	remove_line_break(g->map);
	search_player_xy(g);
	close(fd);
}
