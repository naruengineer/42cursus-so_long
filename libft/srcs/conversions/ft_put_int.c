/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:56:27 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:21:53 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_int(int i)
{
	char	put_int;
	int		count;

	count = 0;
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
		count++;
	}
	if (i >= 10)
		count += ft_put_int(i / 10);
	put_int = (i % 10) + '0';
	write(1, &put_int, 1);
	count++;
	return (count);
}
