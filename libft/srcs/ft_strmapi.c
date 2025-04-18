/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:41:03 by nando             #+#    #+#             */
/*   Updated: 2024/12/11 16:43:06 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_string;
	size_t	str_len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	str_len = ft_strlen(s);
	new_string = (char *)malloc((str_len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while (i < str_len)
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
