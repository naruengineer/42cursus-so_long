/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:54:46 by nando             #+#    #+#             */
/*   Updated: 2024/12/11 19:32:19 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	subs_len;
	char	*str_cpy;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_calloc(1, sizeof(char)));
	subs_len = s_len - start;
	if (subs_len > len)
		subs_len = len;
	str_cpy = (char *)ft_calloc(subs_len + 1, sizeof(char));
	if (!str_cpy)
		return (NULL);
	while (i < subs_len)
	{
		str_cpy[i] = s[start];
		start++;
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
