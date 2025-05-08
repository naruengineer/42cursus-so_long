/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:15:28 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 22:22:39 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_collectable(t_game *g)
{
	g->collected++;
	ft_printf("Yay, you got a bone!\n");
	if (g->collected == g->total_collect)
		ft_printf("Now you have all the bones. Let's go home.\n");
	g->map[g->new_y][g->new_x] = '0';
}

void	get_goal(t_game *g)
{
	ft_printf("Welcome back!\nThank you for completing this adventure.\n");
	close_window(g);
}