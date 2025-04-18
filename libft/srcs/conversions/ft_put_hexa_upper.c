/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:45:17 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:43:35 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_hexa_upper(int n)
{
	char	*hexa_upper_base;
	int		count;

	hexa_upper_base = "0123456789ABCDEF";
	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
		count += ft_put_hexa_upper(n / 16);
	count += write(1, &hexa_upper_base[n % 16], 1);
	return (count);
}
