/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:56:45 by nando             #+#    #+#             */
/*   Updated: 2025/04/18 21:25:08 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"

typedef struct s_data
{
	void *img;
	char *address;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dest;
	
	dest = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void draw_circle(t_data *data, int cx, int cy, int r, int color)
{
    int x;
    int y;

    for (y = cy - r; y <= cy + r; y++)
    {
        for (x = cx - r; x <= cx + r; x++)
        {
            if (((x - cx) * (x - cx) + (y - cy) * (y - cy)) <= (r * r))
                my_mlx_pixel_put(data, x, y, color);
        }
    }
}



int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;
	int x;
	int y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.address = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 0;
    while (y < 1080)
    {
        x = 0;
        while (x < 1920)
        {
            my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
            x++;
        }
        y++;
    }
	draw_circle(&img, 960, 540, 300, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

