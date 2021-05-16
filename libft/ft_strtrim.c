/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:12:50 by aazevedo          #+#    #+#             */
/*   Updated: 2021/02/24 16:59:19 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	s1_len;

	i = 0;
	start = 0;
	s1_len = ft_strlen(s1);
	while (i < s1_len)
	{
		if (ft_strchr(set, s1[i]))
			start++;
		else
			break ;
		i++;
	}
	return (start);
}

static int	get_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	end = s1_len;
	i = s1_len - 1;
	while (i > 0)
	{
		if (ft_strchr(set, s1[i]))
			end--;
		else
			break ;
		i--;
	}
	return (end);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	return (ft_substr(s1, start, end - start));
}
