/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:27:50 by nando             #+#    #+#             */
/*   Updated: 2025/05/02 16:04:56 by nando            ###   ########.fr       */
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
}				t_data;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_data		img;
	char		**map;
	int			height;
	int			width;
}				t_game;

int				main(int argc, char **argv);
void			free_map_and_exit(char **map, char *error_script);
void			print_map(char **map);
char			**load_map(const char *filename);
void			validate_map(char **map);
int				check_charset(const t_mapinfo *info);
int				check_char_counts(const t_mapinfo *info);
int				check_wall(const t_mapinfo *info);
int				path_exists(t_mapinfo *mapinfo);

#endif