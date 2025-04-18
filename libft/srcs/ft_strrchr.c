/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:55:43 by nando             #+#    #+#             */
/*   Updated: 2024/12/13 13:51:39 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	while (string[i] != '\0')
	{
		if ((char)string[i] == (char)c)
			result = (char *)&string[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&string[i]);
	return (result);
}
