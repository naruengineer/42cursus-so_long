/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:46:33 by nando             #+#    #+#             */
/*   Updated: 2024/12/11 18:50:58 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n_str;
	size_t	i;
	size_t	j;
	size_t	n_str_len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	n_str_len = ft_strlen(s1) + (ft_strlen(s2));
	n_str = (char *)malloc(n_str_len + 1 * sizeof(char));
	if (!n_str)
		return (NULL);
	while (j < ft_strlen(s1))
		n_str[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
		n_str[i++] = s2[j++];
	n_str[i] = '\0';
	return (n_str);
}
