/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:24:11 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 17:17:02 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	ft_judge_overflow_long(long result, int sign, char next)
{
	if (sign == 1)
	{
		if ((__LONG_MAX__ / 10 < result) || (__LONG_MAX__ / 10 == result
				&& __LONG_MAX__ % 10 <= next - '0'))
			return (1);
	}
	if (sign == -1)
	{
		if ((__LONG_MAX__ / 10 < result) || (__LONG_MAX__ / 10 == result
				&& __LONG_MAX__ % 10 + 1 <= next - '0'))
			return (-1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (ft_judge_overflow_long(result, sign, nptr[i + 1]) == 1)
			return ((int)__LONG_MAX__);
		if (ft_judge_overflow_long(result, sign, nptr[i + 1]) == -1)
			return (-((int)__LONG_MAX__ + 1));
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}
