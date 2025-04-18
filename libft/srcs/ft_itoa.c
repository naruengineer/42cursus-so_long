/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:51:59 by nando             #+#    #+#             */
/*   Updated: 2024/12/11 20:06:55 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_of_digits(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
	{
		digits++;
		n = -n;
	}
	while (n > 0)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

static void	convert_to_string(char *nbr, int n, int digits)
{
	while (digits > 0)
	{
		nbr[--digits] = (n % 10) + '0';
		if (n / 10 < 1)
			break ;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		digits;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = num_of_digits(n);
	nbr = (char *)malloc((digits + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[digits] = '\0';
	if (n < 0)
	{
		nbr[0] = '-';
		n = -n;
	}
	convert_to_string(nbr, n, digits);
	return (nbr);
}
