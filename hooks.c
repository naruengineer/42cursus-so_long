/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:42:28 by nando             #+#    #+#             */
/*   Updated: 2025/04/09 17:21:14 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define ESC_KEY 65307

typedef struct s_vars
{
	void *mlx;
	void *win;
	int key_pressed;
	struct timeval press_time;
	double threshold;
}	t_vars;

// int close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int handle__key(int keycode, t_vars *vars)
// {
// 	if(keycode == ESC_KEY)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(0);
// 	}
// 	return (0);
// }

// int handle_resize(void *param)
// {
// 	(void)param;
// 	printf("window resized!\n");
// 	return (0);
// }

// int handle_destroy(void *param)
// {
// 	t_vars *vars = (t_vars *)param;
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	exit(0);
// 	return (0);
// }

int key_press(int keycode, t_vars *vars)
{
	if(vars->key_pressed == -1)
	{
		vars->key_pressed = keycode;
		gettimeofday(&vars->press_time, NULL);
	}
	return(0);
}

int key_release(int keycode, t_vars *vars)
{
	if(vars->key_pressed == keycode)
	{
		struct timeval release_time;
		gettimeofday(&release_time, NULL);
		double duration = (release_time.tv_sec - vars->press_time.tv_sec)
							+ (release_time.tv_usec - vars->press_time.tv_usec) / 1000000.0;
		if(duration >= vars->threshold)
			printf("Key %d was held for %.2f second!\n", keycode, duration);
		vars->key_pressed = -1;
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.key_pressed = -1;
	vars.threshold = 2.0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	// mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	// mlx_hook(vars.win, 2, 1L<<0, handle__key, &vars);
	// mlx_hook(vars.win, 17, 1L<<17, handle_resize, &vars);
	// mlx_hook(vars.win, 17, 0, handle_destroy, &vars);
	mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L<<1, key_release, &vars);
	mlx_loop(vars.mlx);
}
