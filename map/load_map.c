/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:41:36 by nando             #+#    #+#             */
/*   Updated: 2025/05/02 16:00:41 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_file_format(char *filename)
{
	int	filename_len;
	int	result;

	filename_len = ft_strlen(filename);
	if (filename_len < 4)
	{
		ft_putstr_fd("Error: Invalid file extension.\n", 2);
		exit(EXIT_FAILURE);
	}
	result = ft_strncmp(filename + filename_len - 4, ".ber", 4);
	if (result != 0)
	{
		ft_putstr_fd("Error: Invalid file extension.\n", 2);
		exit(EXIT_FAILURE);
	}
}

static int	count_line(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error : open failed\n");
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

char	**load_map(const char *filename)
{
	int		line_count;
	char	**map;
	int		fd;
	int		i;

	i = 0;
	check_file_format(filename);
	line_count = count_line(filename);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		free_map_and_exit(map, "Error : malloc failed\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		free_map_and_exit(map, "Error : open failed\n");
	while (i < line_count)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			free_map_and_exit(map, "Error : get_next_line failed\n");
		i++;
	}
	map[i] = NULL;
	remove_line_break(map);
	close(fd);
	return (map);
}
