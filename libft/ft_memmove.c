/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:56:41 by aazevedo          #+#    #+#             */
/*   Updated: 2021/02/18 09:56:43 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dst && !src)
		return (0);
	i = 0;
	d = (char *)dst;
	s = (char *)src;
	while (i < len)
	{
		if (s >= d)
			d[i] = s[i];
		else
			d[len - 1 - i] = s[len - 1 - i];
		i++;
	}
	return (dst);
}
