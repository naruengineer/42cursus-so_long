/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:41:36 by nando             #+#    #+#             */
/*   Updated: 2025/04/28 15:25:28 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_line(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error : open failed");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	free_map_and_exit(char **map, char *error_script)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
			free(map[i++]);
		free(map);
	}
	perror(error_script);
	exit(EXIT_FAILURE);
}

char	**load_map(const char *filename)
{
	int		line_count;
	char	**map;
	int		fd;
	int		i;

	i = 0;
	line_count = count_line(filename);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		free_map_and_exit(map, i, "Error : malloc failed");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		free_map_and_exit(map, i, "Error : open failed");
	while (i < line_count)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			free_map_and_exit(map, i - 1, "Error : get_next_line failed");
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
