/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:14:51 by aazevedo          #+#    #+#             */
/*   Updated: 2021/02/24 17:05:44 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned char *str;

	if (!s)
		return ;
	str = (unsigned char *)s;
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}
