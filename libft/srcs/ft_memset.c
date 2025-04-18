/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:18:06 by nando             #+#    #+#             */
/*   Updated: 2024/12/10 17:17:08 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*cast_s;

	i = 0;
	cast_s = (char *)s;
	while (i < n)
	{
		cast_s[i] = c;
		i++;
	}
	return ((void *)cast_s);
}
