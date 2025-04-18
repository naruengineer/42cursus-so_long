/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:15:56 by nando             #+#    #+#             */
/*   Updated: 2024/12/13 13:51:19 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if ((char)string[i] == (char)c)
			return ((char *)&string[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&string[i]);
	return (NULL);
}
