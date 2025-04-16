/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:08:29 by nando             #+#    #+#             */
/*   Updated: 2025/04/16 20:00:22 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include "./make_rainbow/make_rainbow.c"

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
	int 	keycode;
	double	hue;
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

int close_window(t_vars *vars)
{
	printf("Good Bye!\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return 0;
}

int handle_resize(void *param)
{
	(void )param;
	printf("window resize!\n");
	return 0;
}

int handle_key_down(int press_keycode, t_vars *vars)
{
	if(press_keycode == 65307)
	{
		printf("Press ESC key. Destroy window.\nGood Bye!\n");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
		return 0;
	}
	vars->keycode = press_keycode;
	printf("Press key %d\n", press_keycode);
	return (0);
}

int handle_mouse_enter(t_vars *vars)
{
	printf("mouse in\n");
	return 0;
}

int handle_mouse_leave(t_vars *vars)
{
	printf("mouse out\n");
	return 0;
}

int key_print(int keycode, t_vars *vars)
{
	printf("key code is %d\n", keycode);
	return 0;
}

int render_next_frame(t_vars *vars)
{
	t_data img;
	int x;
	int y;
	int color;

	img.img = mlx_new_image(vars->mlx, 960, 540);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	color = hsv_to_rgb(vars->hue);
	y = 0;
	while(y < 540)
	{
		x = 0;
		while(x < 960)
		{
			my_mlx_pixel_put(&img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_destroy_image(vars->mlx, img.img);
	vars->hue += 1.0;
	if(vars->hue >= 360)
		vars->hue = 0;
	usleep(10000);
	return 0;
}


int	main(void)
{
	//t_data img;
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 960, 540, "Hello world!");
	vars.hue = 0;
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	//img.img = mlx_new_image(vars.mlx, 960, 540);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//draw_line(&img, 50, 50, 500, 0x0000FF00);
	//draw_line(&img, 50, 100, 500, 0x00FF0000);
	//draw_line(&img, 50, 150, 500, 0x000000FF);
	//draw_circle(&img, 300, 300, 50, 0x00FF0000);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_hook(vars.win, 2, 1L<<0, handle_key_down, &vars);
	mlx_hook(vars.win, 22, 1L<<17, handle_resize, &vars);
	mlx_hook(vars.win, 7, 1L<<4, handle_mouse_enter,&vars);
	mlx_hook(vars.win, 8, 1L<<5, handle_mouse_leave,&vars);
	//mlx_key_hook(vars.win, key_print, &vars);
	//create_checker_board(&img, 960, 540);
	//mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	return 0;
}
