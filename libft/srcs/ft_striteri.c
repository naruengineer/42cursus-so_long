/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:47:24 by nando             #+#    #+#             */
/*   Updated: 2024/12/11 13:58:16 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	str_len;
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	str_len = ft_strlen(s);
	while (i < str_len)
	{
		f(i, &s[i]);
		i++;
	}
}
