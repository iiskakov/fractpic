/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiskakov <iiskakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 21:37:18 by iiskakov          #+#    #+#             */
/*   Updated: 2019/03/07 12:24:19 by iiskakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*ptr;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
						ft_strlen(s2) + 1))))
		return (NULL);
	ptr = res;
	i = ft_strlen(s1);
	while (i--)
		*res++ = *s1++;
	i = ft_strlen(s2);
	while (i--)
		*res++ = *s2++;
	*res = '\0';
	return (ptr);
}
