/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:56:18 by aazevedo          #+#    #+#             */
/*   Updated: 2021/02/18 09:56:20 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1_char;
	char	*s2_char;
	int		diff;

	i = 0;
	diff = 0;
	s1_char = (char *)s1;
	s2_char = (char *)s2;
	while (i < n)
	{
		diff = (unsigned char)s1_char[i] - (unsigned char)s2_char[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (diff);
}
