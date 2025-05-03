/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:24:01 by nando             #+#    #+#             */
/*   Updated: 2025/05/03 18:45:17 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	file_format_error(void)
{
	ft_putstr_fd("Error: Invalid file format.\n", 2);
	exit(EXIT_FAILURE);
}

static void	check_file_format(char *filename)
{
	int	filename_len;
	int	result;

	filename_len = ft_strlen(filename);
	if (filename_len < 4)
		file_format_error();
	result = ft_strncmp(filename + filename_len - 4, ".ber", 4);
	if (result != 0)
		file_format_error();
}

static void	print_game_system(t_game *g)
{
	ft_printf("\nYou are a pretty dog.\nCollect all the bones and go home!\n");
	ft_printf("It looks like there are %d bones.\n", g->total_collect);
	ft_printf("Please press [WSAD] or [Arrow keys].\n\n");
}

int	main(int argc, char **argv)
{
	char		**map;
	t_mapinfo	info;
	t_game		game;
	t_dfs		dfs;

	if (argc != 2)
		return (0);
	check_file_format(argv[1]);
	map = load_map(argv[1]);
	validate_map(map, &info, &dfs);
	init_game(&game, &info, &dfs);
	print_game_system(&game);
	running_game(&game);
	return (0);
}
