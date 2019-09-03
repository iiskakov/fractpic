/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 09:54:32 by iiskakov          #+#    #+#             */
/*   Updated: 2019/03/09 16:08:37 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	z;
	int	find_size;

	i = 0;
	z = 0;
	find_size = 0;
	while (needle[find_size] != '\0')
		find_size++;
	if (find_size == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		while (needle[z] == haystack[i + z])
		{
			if (z == find_size - 1)
				return ((char *)(haystack + i));
			z++;
		}
		z = 0;
		i++;
	}
	return (0);
}
