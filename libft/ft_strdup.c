/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:23:12 by iiskakov          #+#    #+#             */
/*   Updated: 2019/03/07 11:32:44 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1);
	if (!s1 || !(dup = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr = dup;
	while (len)
	{
		*dup++ = *s1++;
		len--;
	}
	*dup++ = '\0';
	return (ptr);
}
