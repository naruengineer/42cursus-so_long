/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:56:45 by nando             #+#    #+#             */
/*   Updated: 2025/04/18 21:52:43 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "so_long.h"

int main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		peeror("Error\nopen failed");
		exit(EXIT_FAILURE);
	}
}

