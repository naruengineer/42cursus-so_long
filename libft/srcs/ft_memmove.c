/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:37:04 by nando             #+#    #+#             */
/*   Updated: 2024/12/13 13:49:45 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cast_src;
	char	*cast_dest;
	size_t	i;

	if (dest == src)
		return (dest);
	cast_src = (char *)src;
	cast_dest = (char *)dest;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			cast_dest[i] = cast_src[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (n-- > 0)
			cast_dest[n] = cast_src[n];
	}
	return ((void *)cast_dest);
}

// void	test_ft_memmove(void)
// {
// 	char	buffer1[50] = "This is a test string";
// 	char	buffer2[50];
// 	char	buffer3[50] = "Hello, World!";
// 	char	buffer1_original[50] = "This is a test string";
// 	char	buffer3_original[50] = "Hello, World!";
// 	char	*null_test;
// 	char	buffer4[50] = "Self copy";
// 	char	buffer4_original[50] = "Self copy";

// 	// 通常コピー
// 	ft_memmove(buffer2, buffer1, 21);
// 	memmove(buffer2, buffer1_original, 21);
// 	printf("Normal Copy:\nft_memmove: %s\nmemmove:    %s\n\n", buffer2,
// 		buffer2);
// 	// オーバーラップ（後方からコピー）
// 	ft_memmove(buffer1 + 5, buffer1, 16);
// 	memmove(buffer1_original + 5, buffer1_original, 16);
// 	printf("Overlap Copy Backward:\nft_memmove: %s\nmemmove:    %s\n\n",
// 		buffer1, buffer1_original);
// 	// オーバーラップ（前方からコピー）
// 	ft_memmove(buffer3, buffer3 + 7, 6);
// 	memmove(buffer3_original, buffer3_original + 7, 6);
// 	printf("Overlap Copy Forward:\nft_memmove: %s\nmemmove:    %s\n\n", buffer3,
// 		buffer3_original);
// 	// NULLチェック
// 	null_test = ft_memmove(NULL, buffer1, 10);
// 	printf("NULL Test:\nft_memmove: %s\nmemmove:    %s\n\n",
// 		null_test == NULL ? "NULL passed" : "NULL failed", "NULL passed");
// 	// 自分自身にコピー
// 	ft_memmove(buffer4, buffer4, 10);
// 	memmove(buffer4_original, buffer4_original, 10);
// 	printf("Self Copy:\nft_memmove: %s\nmemmove:    %s\n", buffer4,
// 		buffer4_original);
// }

// int	main(void)
// {
// 	test_ft_memmove();
// 	return (0);
// }