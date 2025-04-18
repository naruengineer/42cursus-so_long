/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_trgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:28:01 by nando             #+#    #+#             */
/*   Updated: 2025/04/15 18:46:01 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int create_trgb(int t, int r, int g, int b)
{
	return ((t << 24) | (r << 16) | (g << 8) | b);
}

int get_t(int color)
{
	return (color >> 24 & 0xFF);
}

int get_r(int color)
{
	return (color >> 16 & 0xFF);
}

int get_g(int color)
{
	return (color >> 8 & 0xFF);
}

int get_b(int color)
{
	return (color & 0xFF);
}