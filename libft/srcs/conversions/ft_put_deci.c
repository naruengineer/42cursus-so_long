/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_deci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:42:05 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:43:17 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_deci(int i)
{
	char	put_deci;
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
		count += ft_put_deci(i / 10);
	put_deci = (i % 10) + '0';
	write(1, &put_deci, 1);
	count++;
	return (count);
}
