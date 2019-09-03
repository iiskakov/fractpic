/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:37:45 by iiskakov          #+#    #+#             */
/*   Updated: 2019/03/09 16:09:05 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*b;
	char	*l;
	char	*b_begin;

	l = (char*)needle;
	if (*l == 0)
		return ((char*)haystack);
	b_begin = (char*)haystack;
	while ((*haystack) && ((size_t)(haystack - b_begin) < len))
	{
		b = (char*)haystack;
		if (*b == *needle)
		{
			l = (char*)needle;
			while ((*b == *l) && ((size_t)(b - b_begin) < len))
			{
				b++;
				l++;
				if (*l == 0)
					return ((char*)haystack);
			}
		}
		haystack++;
	}
	return (NULL);
}
