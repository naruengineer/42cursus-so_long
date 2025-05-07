/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:24:01 by nando             #+#    #+#             */
/*   Updated: 2025/05/07 16:28:53 by nando            ###   ########.fr       */
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

static void	print_intro(void)
{
	ft_printf(
		" _     ___  ____ _____   ____   ___   ____\n"
		"| |   / _ \\/ ___|_   _| |  _ \\ / _ \\ / ___|\n"
		"| |  | | | \\___ \\ | |   | | | | | | | |  _\n" 
		"| |__| |_| |___) || |   | |_| | |_| | |_| |\n"
		"|_____\\___/|____/ |_|   |____/ \\___/ \\____|\n"
	);
	ft_printf("\n  * Woof! Woof! *\n\n");
	ft_printf("  Welcome, Lost dog adventurer!\n\n");
	ft_printf("");
	ft_printf("  Your mission:  Collect all the bones and return HOME.\n");
	ft_printf("  Controls    :  [W] / [↑] : Move Up\n                 [A] / [←] : Move Left\n                 [S] / [↓] : Move Down\n                 [D] / [→] : Move Right\n                 [ESC]     : Quit\n\n"
	);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		return (0);
	check_file_format(argv[1]);
	game.map = load_map(argv[1]);
	validate_map(&game);
	print_intro();
	init_game(&game);
	running_game(&game);
	return (0);
}
