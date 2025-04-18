/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_trgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:13:22 by nando             #+#    #+#             */
/*   Updated: 2025/04/09 16:27:51 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


int get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int get_b(int trgb)
{
	return ((trgb) & 0xFF);
}

int add_shade(int color, double shade)
{
	int t;
	int r;
	int g;
	int b;

	t = get_t(color);
	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	
	r = (int)(r * (1.0 - shade));
	g = (int)(g * (1.0 - shade));
	b = (int)(b * (1.0 - shade));
	
	return create_trgb(t, r, g, b);
}

int get_opposite(int color)
{
	int t = get_t(color);
	int r = get_g(color);
	int g = get_g(color);
	int b = get_b(color);
	return create_trgb(t, 255 - r, 255 - g, 255 - b);
}
