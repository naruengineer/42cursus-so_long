/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:10:27 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 17:42:50 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game *g)
{
	printf("\nGood Bye!\n");
	free_map(g->map);
	free_mlx(g);
	exit(EXIT_SUCCESS);
	return (0);
}
