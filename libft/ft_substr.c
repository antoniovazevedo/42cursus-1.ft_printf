/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:21:11 by aazevedo          #+#    #+#             */
/*   Updated: 2021/02/18 20:04:16 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	substr_max_len;
	char	*substr;

	i = 0;
	substr_max_len = ft_strlen(s);
	if (len < substr_max_len)
		substr_max_len = len;
	substr = (char *)malloc(sizeof(char) * (substr_max_len + 1));
	if (!substr)
		return (0);
	while (start < ft_strlen(s) && i < substr_max_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
