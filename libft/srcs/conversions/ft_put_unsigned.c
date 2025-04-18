/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:26:53 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:44:00 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_unsigned(unsigned int i)
{
	char	put_unsigned;
	int		count;

	count = 0;
	if (i >= 10)
		count += ft_put_unsigned(i / 10);
	put_unsigned = (i % 10) + '0';
	write(1, &put_unsigned, 1);
	return (count + 1);
}
