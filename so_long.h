/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:27:50 by nando             #+#    #+#             */
/*   Updated: 2025/05/03 19:24:57 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef ERROR
#  define ERROR -1
# endif

# ifndef OK
#  define OK 1
# endif

# ifndef NG
#  define NG 0
# endif

# define ESC_KEY 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# include "./minilibx-Linux/mlx.h"
# include "libft/includes/ft_printf.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_mapinfo
{
	char		**map;
	int			width;
	int			height;
}				t_mapinfo;

typedef struct s_dfs
{
	t_mapinfo	*mapinfo;
	char		*visited;
	int			total_c;
	int			found_c;
	int			found_e;
}				t_dfs;

typedef struct s_data
{
	void		*img;
	char		*address;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*player;
	void		*start;
	void		*goal;
	void		*collectable;
	void		*wall;
	void		*floor;
}				t_data;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_data		img;
	char		**map;
	int			collected;
	int			total_collect;
	int			player_x;
	int			player_y;
	int			height;
	int			width;
	int			count_move;
}				t_game;

int				main(int argc, char **argv);
void			free_map_and_exit(char **map, char *error_script);
void			free_images(t_game *g);
void			free_map(char **map);
int				close_window(t_game *g);
void			print_map(char **map);
char			**load_map(const char *filename);
void			validate_map(char **map, t_mapinfo *info, t_dfs *dfs);
int				check_charset(const t_mapinfo *info);
int				check_char_counts(const t_mapinfo *info);
int				check_wall(const t_mapinfo *info);
int				path_exists(t_mapinfo *mapinfo, t_dfs *dfs);
void			init_game(t_game *g, t_mapinfo *info, t_dfs *dfs);
void			running_game(t_game *g);
int				handle_press_key(int keycode, t_game *g);
void			draw_map(t_game *g);

#endif