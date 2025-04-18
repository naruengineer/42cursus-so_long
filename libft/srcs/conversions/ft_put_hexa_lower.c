/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:06:50 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:43:25 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_hexa_lower(int n)
{
	char	*hexa_lower_base;
	int		count;

	hexa_lower_base = "0123456789abcdef";
	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
		count += ft_put_hexa_lower(n / 16);
	count += write(1, &hexa_lower_base[n % 16], 1);
	return (count);
}
