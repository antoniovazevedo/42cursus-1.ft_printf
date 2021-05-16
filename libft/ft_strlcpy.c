/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:57:43 by aazevedo          #+#    #+#             */
/*   Updated: 2021/02/24 16:55:32 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_i;
	size_t	src_len;

	if (!dst)
		return (-1);
	src_i = 0;
	src_len = ft_strlen(src);
	if (!dst && !src)
		return (0);
	else if (!dstsize)
		return (src_len);
	while (src_i < src_len && src_i + 1 < dstsize)
	{
		dst[src_i] = src[src_i];
		src_i++;
	}
	if (dstsize > 0)
		dst[src_i] = '\0';
	return (src_len);
}
