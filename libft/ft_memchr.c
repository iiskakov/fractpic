/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 05:40:44 by iiskakov          #+#    #+#             */
/*   Updated: 2019/03/06 13:09:28 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ns;

	ns = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (*ns == (unsigned char)c)
			return ((void *)ns);
		ns++;
	}
	return (0);
}
