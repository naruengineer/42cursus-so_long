/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:24:01 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 21:37:19 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_intro(void)
{
	ft_printf(" _     ___  ____ _____   ____   ___   ____\n"
				"| |   / _ \\/ ___|_   _| |  _ \\ / _ \\ / ___|\n"
				"| |  | | | \\___ \\ | |   | | | | | | | |  _\n"
				"| |__| |_| |___) || |   | |_| | |_| | |_| |\n"
				"|_____\\___/|____/ |_|   |____/ \\___/ \\____|\n");
	ft_printf("\n  * Woof! Woof! *\n\n");
	ft_printf("  Welcome, Lost dog adventure!\n\n");
	ft_printf("");
	ft_printf("  Your mission:  Collect all the bones and return (HOME.\n\n");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("invalid number of args.\nUsage : <./so_long> <map.ber>\n");
		return (0);
	}
	check_file_format(argv[1]);
	load_map(&game, argv[1]);
	validate_map(&game);
	print_intro();
	init_game(&game);
	running_game(&game);
	return (0);
}
