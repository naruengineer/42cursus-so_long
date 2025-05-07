/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:05:10 by nando             #+#    #+#             */
/*   Updated: 2025/05/07 17:11:23 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	file_format_error(void)
{
	ft_putstr_fd("Error: Invalid file format.\n", 2);
	exit(EXIT_FAILURE);
}

void	check_file_format(char *filename)
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
