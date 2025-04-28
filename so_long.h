/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:27:50 by nando             #+#    #+#             */
/*   Updated: 2025/04/28 15:18:30 by nando            ###   ########.fr       */
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

char		**load_map(const char *filename);
void		free_map_and_exit(char **map, char *error_script);
static int	count_line(const char *filename);
void		validate_map(char **map);

#endif