/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:15:23 by aazevedo          #+#    #+#             */
/*   Updated: 2021/02/24 17:00:05 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_elements(char const *str, char sep)
{
	size_t	i;
	size_t	el_len;
	size_t	count;

	i = 0;
	el_len = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == sep)
		{
			if (el_len > 0)
				count++;
			el_len = 0;
		}
		else
			el_len++;
		i++;
	}
	if (el_len > 0)
		count++;
	return (count);
}

static char		**fill_list(char const *str, char s, char **list, size_t len)
{
	size_t	i;
	size_t	list_i;
	size_t	substr_len;
	char	*substr;

	i = 0;
	list_i = 0;
	substr_len = 0;
	while (list_i < len)
	{
		if (str[i] == s || str[i] == 0)
		{
			if (substr_len > 0)
			{
				substr = (char *)ft_calloc(substr_len + 1, sizeof(char));
				ft_memcpy(substr, str + i - substr_len, substr_len);
				list[list_i++] = substr;
			}
			substr_len = 0;
		}
		else
			substr_len++;
		i++;
	}
	return (list);
}

char			**ft_split(char const *s, char c)
{
	size_t	list_len;
	char	**list;

	if (!s)
		return (0);
	list_len = ft_count_elements(s, c);
	list = (char **)malloc(sizeof(char *) * (list_len + 1));
	if (!list)
		return (0);
	fill_list(s, c, list, list_len);
	list[list_len] = 0;
	return (list);
}
