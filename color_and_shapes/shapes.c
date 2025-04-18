/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:44:07 by nando             #+#    #+#             */
/*   Updated: 2025/04/18 20:09:54 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-Linux/mlx.h"

// void draw_line(t_data *data, int start_x, int y, int length, int color)
// {
// 	int i;
	
// 	i = 0;
// 	while(i < length)
// 	{
// 		my_mlx_pixel_put(data, start_x + i, y, color);
// 		i++;
// 	}
// }


// int add_shade(int color, double shade)
// {
// 	int t;
// 	int r;
// 	int g;
// 	int b;

// 	if (shade < 0.0)
// 		shade = 0.0;
// 	if (shade > 1.0)
// 		shade = 1.0;
// 	t = get_t(color);
// 	r =	get_r(color);
// 	g = get_g(color);
// 	b = get_b(color);
// 	r = (int)(r * (1.0 - shade));
// 	g = (int)(g * (1.0 - shade));
// 	b = (int)(b * (1.0 - shade));
// 	return (create_trgb(t, r, g, b));
// }

// int invert_color(int color)
// {
// 	int t;
// 	int r;
// 	int g;
// 	int b;
	
// 	t = get_t(color);
// 	r = get_r(color);
// 	g = get_g(color);
// 	b = get_b(color);
// 	r = 255 - r;
// 	g = 255 - g;
// 	b = 255 - b;
// 	return (create_trgb(t, r, g, b));
// }

// void create_checker_board(t_data *data, int image_width, int image_height)
// {
// 	int y;
// 	int x;
// 	int block_size;
// 	int color;
// 	block_size = 32;
// 	x = 0;
//     while (x < image_width)
//     {
//         y = 0;
//         while (y < image_height)
//         {
//             if (((x / block_size) + (y / block_size)) % 2 == 0)
//                 color = 0x00FFFFFF;
//             else
//                 color = 0x00000000;
//             my_mlx_pixel_put(data, x, y, color);
//             y++;
//         }
//         x++;
//     }
// }
