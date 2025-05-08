/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:05:10 by nando             #+#    #+#             */
/*   Updated: 2025/05/08 21:11:07 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	file_format_error(void)
{
	perror("Error: invalid file format.\n");
	exit(EXIT_FAILURE);
}

void	check_file_format(char *filename)
{
	int	filename_len;
	int	result;

	if(!filename)
		error_and_exit("Error : map_file is NULL");
	filename_len = ft_strlen(filename);
	if (filename_len < 4)
		file_format_error();
	result = ft_strncmp(filename + filename_len - 4, ".ber", 4);
	if (result != 0)
		file_format_error();
}
