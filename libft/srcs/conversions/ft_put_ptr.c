/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:49:55 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:21:56 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_ptr(void *ptr)
{
	unsigned long long	ptr_address;
	char				*hex_base;
	char				buf[16];
	int					i;

	hex_base = "0123456789abcdef";
	ptr_address = (unsigned long long)ptr;
	if (ptr_address == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	i = 15;
	while (ptr_address)
	{
		buf[i--] = hex_base[ptr_address % 16];
		ptr_address = ptr_address / 16;
	}
	write(1, &buf[i + 1], 15 - i);
	return (2 + 15 - i);
}
