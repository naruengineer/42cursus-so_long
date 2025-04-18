/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:28:30 by nando             #+#    #+#             */
/*   Updated: 2024/12/11 18:46:57 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_string(char const *s, char c)
{
	int	i;
	int	count;
	int	is_inside_word;

	i = 0;
	count = 0;
	is_inside_word = 1;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && is_inside_word == 1)
		{
			count++;
			is_inside_word = 0;
		}
		else if (s[i] == c)
			is_inside_word = 1;
		i++;
	}
	return (count);
}

static char	*create_new_string(char const *s, char c)
{
	char	*new_string;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	new_string = malloc((len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while (i < len)
	{
		new_string[i] = s[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

static void	free_inserted_memory(char **result, int j)
{
	j = j - 1;
	while (j >= 0)
	{
		free(result[j]);
		j--;
	}
	free(result);
}

static char	**create_split(char const *s, char **result, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result[j] = create_new_string(&s[i], c);
			if (!result[j])
			{
				free_inserted_memory(result, j);
				return (NULL);
			}
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((count_string(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = create_split(s, result, c);
	return (result);
}
