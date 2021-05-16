/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:58:16 by aazevedo          #+#    #+#             */
/*   Updated: 2021/02/23 19:37:54 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_i;
	int		found_at;

	i = 0;
	needle_i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i + needle_i])
	{
		needle_i = 0;
		found_at = -1;
		while (needle[needle_i] == haystack[i + needle_i] && i + needle_i < len)
		{
			if (found_at == -1)
				found_at = i;
			if (!needle[needle_i + 1])
				return ((char *)&haystack[found_at]);
			needle_i++;
		}
		i++;
	}
	return (NULL);
}
