/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:08:29 by nando             #+#    #+#             */
/*   Updated: 2025/04/15 19:30:29 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
//#include "./create_trgb/create_trgb.c"

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_data;


typedef struct s_vars
{
	void	*mlx;
	void	*win;
} t_vars;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); 
	*(unsigned int*)dst = color;
}

//void draw_line(t_data *data, int start_x, int y, int length, int color)
//{
//	int i;
	
//	i = 0;
//	while(i < length)
//	{
//		my_mlx_pixel_put(data, start_x + i, y, color);
//		i++;
//	}
//}

//void draw_circle(t_data *data, int cx, int cy, int r, int color)
//{
//	int x;
//	int y;

//	y = cy - r;
//	while(y <= cy + r)
//	{
//		x = cx - r;
//		while(x <= cx + r)
//		{
//			if (((x - cx) * (x - cx) + (y - cy) * (y - cy)) <= (r * r))
//                my_mlx_pixel_put(data, x, y, color);
//			x++;
//		}
//		y++;
//	}
//}

////int add_shade(int color, double shade)
////{
////	int t;
////	int r;
////	int g;
////	int b;

////	if (shade < 0.0)
////		shade = 0.0;
////	if (shade > 1.0)
////		shade = 1.0;
////	t = get_t(color);
////	r =	get_r(color);
////	g = get_g(color);
////	b = get_b(color);
////	r = (int)(r * (1.0 - shade));
////	g = (int)(g * (1.0 - shade));
////	b = (int)(b * (1.0 - shade));
////	return (create_trgb(t, r, g, b));
////}

////int invert_color(int color)
////{
////	int t;
////	int r;
////	int g;
////	int b;
	
////	t = get_t(color);
////	r = get_r(color);
////	g = get_g(color);
////	b = get_b(color);
////	r = 255 - r;
////	g = 255 - g;
////	b = 255 - b;
////	return (create_trgb(t, r, g, b));
////}

void create_checker_board(t_data *data, int image_width, int image_height)
{
	int y;
	int x;
	int block_size;
	int color;
	block_size = 32;
	x = 0;
    while (x < image_width)
    {
        y = 0;
        while (y < image_height)
        {
            if (((x / block_size) + (y / block_size)) % 2 == 0)
                color = 0x00FFFFFF;
            else
                color = 0x00000000;
            my_mlx_pixel_put(data, x, y, color);
            y++;
        }
        x++;
    }
}

int close_window(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return 0;
}

int	main(void)
{
	t_data img;
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 960, 540, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 960, 540);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//draw_line(&img, 50, 50, 500, 0x0000FF00);
	//draw_line(&img, 50, 100, 500, 0x00FF0000);
	//draw_line(&img, 50, 150, 500, 0x000000FF);
	//draw_circle(&img, 300, 300, 50, 0x00FF0000);
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
	create_checker_board(&img, 960, 540);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
