/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wasd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:46:40 by nando             #+#    #+#             */
/*   Updated: 2025/04/18 20:38:33 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-Linux/mlx.h"
#include "./color_and_shapes/create_trgb.c"
#include "./color_and_shapes/shapes.c"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_state
{
	void *mlx;
	void *win;
	int width;
	int height;
	int cx;
	int cy;
	int radius;
}	t_state;

typedef struct s_data
{
	void *img;
	char *addr;
	int bit_per_pixel;
	int line_length;
	int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8)); 
	*(unsigned int*)dst = color;
}

void draw_circle(t_data *data, int cx, int cy, int r, int color)
{
	int x;
	int y;

	y = cy - r;
	while(y <= cy + r)
	{
		x = cx - r;
		while(x <= cx + r)
		{
			if (((x - cx) * (x - cx) + (y - cy) * (y - cy)) <= (r * r))
               my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

int render_next_frame(t_state *state)
{
	t_data img;
	int bg_color;
	int circle_color;
	int y;
	int x;
	
	bg_color = create_trgb(0, 0, 0, 0);
	circle_color = create_trgb(0, 255, 0, 0);
	img.img = mlx_new_image(state->mlx, state->width, state->height);
	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_length, &img.endian);
	y = 0;
	while(y < state->height)
	{
		x = 0;
		while(x < state->width)
		{
			my_mlx_pixel_put(&img, x, y, bg_color);
			x++;
		}
		y++;
	}
	draw_circle(&img, state->cx, state->cy, state->radius, circle_color);
	mlx_put_image_to_window(state->mlx, state->win, img.img, 0, 0);
	mlx_destroy_image(state->mlx, img.img);
	return (0);
}


int handle_key(int keycode, t_state *state)
{
	int step = 10;
	if(keycode == 65307)
	{
		printf("Good Bye!\n");
		exit(0);
	}
	else if (keycode == 'w' || keycode == 'W')
		state->cy -= step;
	else if (keycode == 's' || keycode == 'S')
		state->cy += step;
	else if (keycode == 'a' || keycode == 'A')
		state->cx -= step;
	else if (keycode == 'd' || keycode == 'D')
		state->cx += step;
	if (state->cx < state->radius)            
		state->cx = state->radius;
	if (state->cx > state->width  - state->radius)
		state->cx = state->width  - state->radius;
	if (state->cy < state->radius)
		state->cy = state->radius;
	if (state->cy > state->height - state->radius)
		state->cy = state->height - state->radius;
	return(0);
}



int main(void)
{
	t_state state;

	state.width = 800;
	state.height = 600;
	state.cx = state.width / 2;
	state.cy = state.height / 2;
	state.radius = 50;
	
	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, state.width, state.height, "Move Circle with WASD");
	mlx_loop_hook(state.mlx, render_next_frame, &state);
	mlx_hook(state.win, 2, 1L<<0, handle_key, &state);
	mlx_loop(state.mlx);
	return(0);
}