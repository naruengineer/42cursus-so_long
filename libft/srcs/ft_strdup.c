/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:24:04 by nando             #+#    #+#             */
/*   Updated: 2024/12/13 13:55:14 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	str_len;
	char	*str_cpy;

	i = 0;
	str_len = ft_strlen(s);
	str_cpy = (char *)malloc(str_len + 1 * sizeof(char));
	if (!str_cpy)
		return (NULL);
	while (i < str_len)
	{
		str_cpy[i] = s[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
