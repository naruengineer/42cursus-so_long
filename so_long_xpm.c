/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:41:10 by nando             #+#    #+#             */
/*   Updated: 2025/04/18 20:52:17 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-Linux/mlx.h"

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

int main()
{
	t_state state;
	t_data  data;
	char *relative_path;
	int img_width;
	int img_height;

	relative_path = "./test.xpm";
	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, 8*20, 8*20, "XPM Model");
	data.img = mlx_xpm_file_to_image(state.mlx, relative_path, &img_width, &img_height);
	if(!data.img)
		return (1);
	mlx_put_image_to_window(state.mlx, state.win, data.img, 0, 0);
	mlx_loop(state.mlx);
	return (0);
}