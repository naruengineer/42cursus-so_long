/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:34:41 by nando             #+#    #+#             */
/*   Updated: 2025/04/18 21:56:05 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char **load_map(char *filename)
{
	int fd;
	char *line;
	char **map;
	size_t count;
	
	map = NULL;
	count = 0;
	fd = open(filename, O_RDONLY);
	if(fd < 0)
	{
		perror("Error\nfile open failed.\n");
		exit(EXIT_FAILURE);
	}
	while()
}