/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:57:16 by aazevedo          #+#    #+#             */
/*   Updated: 2021/02/18 09:57:17 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_i;
	size_t	dst_len;
	size_t	src_len;

	src_i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (src_i + dst_len < dstsize - 1 && src[src_i])
	{
		dst[dst_len + src_i] = src[src_i];
		src_i++;
	}
	dst[dst_len + src_i] = '\0';
	return (dst_len + src_len);
}
